#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include "iniconfig.h"

int TcpServerRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);
int TcpClientRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);
int UdpRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);

extern MainWindow* pWnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_bTcpClientIsConnect(false),
    m_bTcpServerIsBind(false)
{
    ui->setupUi(this);
    InitTcpServerUI();
    InitTcpClientUI();
    InitUdpUI();
}

MainWindow::~MainWindow()
{
    UninitSocket(TCP_SERVER_ID);
    UninitSocket(TCP_CLIENT_ID);
    UninitSocket(UDP_ID);
    delete ui;
}

void MainWindow::InitTcpServerUI()
{
    connect(this, SIGNAL(tcpServerRecvMsg(QString)), ui->textEdit_tcpServer_recv, SLOT(append(QString)));

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList[i].toIPv4Address())
            ui->comboBox_tcpServer_localIP->addItem(ipAddressesList[i].toString());
    }

    IniConfig config(INI_PATH);
    QString section = QString().sprintf("TcpServer%d", TCP_SERVER_ID);
    QVariant IP = config.GetValue(section, "Address", ui->comboBox_tcpServer_localIP->currentText());
    QVariant Port = config.GetValue(section, "Port", 9999);

    ui->comboBox_tcpServer_localIP->setCurrentText(IP.toString());
    ui->lineEdit_tcpServer_localPort->setText(Port.toString());
}

void MainWindow::InitTcpClientUI()
{
   connect(this, SIGNAL(tcpClientRecvMsg(QString)), ui->textEdit_tcpClient_recv, SLOT(append(QString)));

   IniConfig config(INI_PATH);
   QString section = QString().sprintf("TcpClient%d", TCP_CLIENT_ID);
   QVariant IP = config.GetValue(section, "Address", "127.0.0.1");
   QVariant Port = config.GetValue(section, "Port", 9999);

   ui->lineEdit_tcpClient_serverIp->setText(IP.toString());
   ui->lineEdit_tcpClient_serverPort->setText(Port.toString());
}

void MainWindow::InitUdpUI()
{
    connect(this, SIGNAL(udpRecvMsg(QString)), ui->textEdit_udp_recv, SLOT(append(QString)));

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList[i].toIPv4Address())
            ui->comboBox_udp_localIP->addItem(ipAddressesList[i].toString());
    }

    IniConfig config(INI_PATH);
    QString section = QString().sprintf("UDP%d", UDP_ID);
    QVariant IP = config.GetValue(section, "Address", ui->comboBox_udp_localIP->currentText());
    QVariant Port = config.GetValue(section, "Port", 10000);

    ui->comboBox_udp_localIP->setCurrentText(IP.toString());
    ui->lineEdit_udp_localPort->setText(Port.toString());
}

void MainWindow::on_pushButton_tcpServer_bind_clicked()
{
    IniConfig config(INI_PATH);
    QString section = QString().sprintf("TcpServer%d", TCP_SERVER_ID);
    config.SetValue(section, "Address", ui->comboBox_tcpServer_localIP->currentText());
    config.SetValue(section, "Port", ui->lineEdit_tcpServer_localPort->text());
    if (m_bTcpServerIsBind == false)
    {
        if (InitSocket(TCP_SERVER_ID, TCP_SERVER, INI_PATH, TcpServerRecvProc) == 0)
        {
            ui->pushButton_tcpServer_bind->setText("关闭");
            m_bTcpServerIsBind = true;
        }
        else
        {
            ui->pushButton_tcpServer_bind->setText("建立");
            m_bTcpServerIsBind = false;
        }
    }
    else
    {
        UninitSocket(TCP_SERVER_ID);
        ui->pushButton_tcpServer_bind->setText("建立");
        m_bTcpServerIsBind = false;
    }
}

void MainWindow::on_pushButton_tcpServer_send_clicked()
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString address = ui->comboBox_tcpServer_clientList->currentText();
    QStringList strList = address.split(":");
    QString ip = strList.at(0);
    QString strPort = strList.at(1);
    int port = strPort.toInt();
    QString sendStr = ui->textEdit_tcpServer_send->toPlainText();
    QByteArray msg = codec->fromUnicode(sendStr);
    TCPSend(TCP_SERVER_ID, msg.data(), ip.toStdString().c_str(), port);
    emit tcpServerRecvMsg(QString().sprintf("[Send to %s]: %s", address.toStdString().c_str(),
                                   sendStr.toStdString().c_str()));
}

void MainWindow::addClient(QString client)
{
    ui->comboBox_tcpServer_clientList->addItem(client);
}

void MainWindow::delClient(QString client)
{
    int nIndex = ui->comboBox_tcpServer_clientList->findText(client);
    ui->comboBox_tcpServer_clientList->removeItem(nIndex);
}

int TcpServerRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv)
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString recvStr;
    switch (nType) {
    case RECV_SOCKET:
        pWnd->addClient(QString().sprintf("%s:%d", szIP, nPort));
        break;
    case RECV_DATA:
        recvStr = codec->toUnicode(szRecv, nSize);
        emit pWnd->tcpServerRecvMsg(QString().sprintf("[Received from %s:%d]: %s", szIP, nPort,
                                                      recvStr.toStdString().c_str()));
        break;
    case RECV_CLOSE:
        pWnd->delClient(QString().sprintf("%s:%d", szIP, nPort));
        break;
    default:
        break;
    }
    return 0;
}

int TcpClientRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv)
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString recvStr;
    switch (nType) {
    case RECV_SOCKET:
        break;
    case RECV_DATA:
        recvStr = codec->toUnicode(szRecv, nSize);
        emit pWnd->tcpClientRecvMsg(QString().sprintf("[Received from %s:%d]: %s", szIP, nPort,
                                                      recvStr.toStdString().c_str()));
        break;
    case RECV_CLOSE:
        break;
    case RECV_ERROR:
        break;
    default:
        break;
    }
    return 0;
}

int UdpRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv)
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString recvStr;
    switch (nType) {
    case RECV_SOCKET:
        break;
    case RECV_DATA:
        recvStr = codec->toUnicode(szRecv, nSize);
        emit pWnd->udpRecvMsg(QString().sprintf("[Received from %s:%d]: %s", szIP, nPort,
                                                recvStr.toStdString().c_str()));
        break;
    case RECV_CLOSE:
        break;
    case RECV_ERROR:
        break;
    default:
        break;
    }
    return 0;
}

void MainWindow::on_pushButton_tcpClient_send_clicked()
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString msg = ui->textEdit_tcpClient_send->toPlainText();
    QByteArray sendBytes = codec->fromUnicode(msg);
    TCPSend(TCP_CLIENT_ID, sendBytes.data());
    emit tcpClientRecvMsg(QString().sprintf("[Send to server]: %s", msg.toStdString().c_str()));
}

void MainWindow::on_pushButton_tcpClient_connect_clicked()
{
    if (!m_bTcpClientIsConnect)
    {
        IniConfig config(INI_PATH);
        QString section = QString().sprintf("TcpClient%d", TCP_CLIENT_ID);
        config.SetValue(section, "Address", ui->lineEdit_tcpClient_serverIp->text());
        config.SetValue(section, "Port", ui->lineEdit_tcpClient_serverPort->text());
        InitSocket(TCP_CLIENT_ID, TCP_CLIENT, INI_PATH, TcpClientRecvProc);
        if (TCPConnect(TCP_CLIENT_ID, 5000) == 0)
        {
            m_bTcpClientIsConnect = true;
            ui->pushButton_tcpClient_connect->setText("断开");
        }
        else
        {
            m_bTcpClientIsConnect = false;
            ui->pushButton_tcpClient_connect->setText("连接");
        }
    }
    else
    {
        UninitSocket(TCP_CLIENT_ID);
        m_bTcpClientIsConnect = false;
        ui->pushButton_tcpClient_connect->setText("连接");
    }
}

void MainWindow::on_pushButton_udp_bind_clicked()
{
    IniConfig config(INI_PATH);
    QString section = QString().sprintf("UDP%d", UDP_ID);
    config.SetValue(section, "Address", ui->comboBox_udp_localIP->currentText());
    config.SetValue(section, "Port", ui->lineEdit_udp_localPort->text());

    InitSocket(UDP_ID, UDP, INI_PATH, UdpRecvProc);
}

void MainWindow::on_pushButton_udp_send_clicked()
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString strIP = ui->lineEdit_udp_remote_ip->text();
    int nPort = ui->lineEdit_udp_remote_port->text().toInt();
    QString msg = ui->textEdit_udp_send->toPlainText();
    QByteArray sendBytes = codec->fromUnicode(msg);
    UDPSend(UDP_ID, sendBytes.data(),
            strIP.toStdString().c_str(), nPort);
    emit udpRecvMsg(QString().sprintf("[Send to %s:%d]: %s", strIP.toStdString().c_str(), nPort,
                                      msg.toStdString().c_str()));
}
