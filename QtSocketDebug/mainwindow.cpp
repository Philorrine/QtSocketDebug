#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include "iniconfig.h"

int TcpServerRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);
int TcpClientRecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);

extern MainWindow* pWnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_bIsConnect(false)
{
    ui->setupUi(this);
    IniTcpServerUI();
    IniTcpClientUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::IniTcpServerUI()
{
    connect(this, SIGNAL(recvMsg(QString)), ui->textEdit_tcpServer_recv, SLOT(append(QString)));

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList[i].toIPv4Address())
            ui->comboBox_tcpServer_localIP->addItem(ipAddressesList[i].toString());
    }

    IniConfig config(INI_PATH);
    QString section = QString().sprintf("TcpServer%d", TCP_SERVER_ID);
    QVariant IP = config.GetValue(section, "Address", ui->comboBox_tcpServer_localIP->currentText());
    QVariant Port = config.GetValue(section, "Port", ui->lineEdit_tcpServer_localPort->text());

    ui->comboBox_tcpServer_localIP->setCurrentText(IP.toString());
    ui->lineEdit_tcpServer_localPort->setText(Port.toString());
}

void MainWindow::IniTcpClientUI()
{
   connect(this, SIGNAL(clientRecvMsg(QString)), ui->textEdit_tcpClient_recv, SLOT(append(QString)));

   QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
   for (int i = 0; i< ipAddressesList.size(); i++)
   {
       if (ipAddressesList[i].toIPv4Address())
           ui->comboBox_tcpClient_serverIP->addItem(ipAddressesList[i].toString());
   }

   IniConfig config(INI_PATH);
   QString section = QString().sprintf("TcpClient%d", TCP_CLIENT_ID);
   QVariant IP = config.GetValue(section, "Address", ui->comboBox_tcpClient_serverIP->currentText());
   QVariant Port = config.GetValue(section, "Port", ui->lineEdit_tcpClient_serverPort->text());

   ui->comboBox_tcpClient_serverIP->setCurrentText(IP.toString());
   ui->lineEdit_tcpClient_serverPort->setText(Port.toString());
}

void MainWindow::on_pushButton_tcpServer_bind_clicked()
{
    IniConfig config(INI_PATH);
    QString section = QString().sprintf("TcpServer%d", TCP_SERVER_ID);
    config.SetValue(section, "Address", ui->comboBox_tcpServer_localIP->currentText());
    config.SetValue(section, "Port", ui->lineEdit_tcpServer_localPort->text());

    InitSocket(TCP_SERVER_ID, TCP_SERVER, INI_PATH, TcpServerRecvProc);
}

void MainWindow::on_pushButton_tcpServer_send_clicked()
{
    QString address = ui->comboBox_tcpServer_clientList->currentText();
    QStringList strList = address.split(":");
    QString ip = strList.at(0);
    QString strPort = strList.at(1);
    int port = strPort.toInt();
    QString msg = ui->textEdit_tcpServer_send->toPlainText();
    TCPSend(TCP_SERVER_ID, msg.toStdString().c_str(), ip.toStdString().c_str(), port);
    emit recvMsg(QString().sprintf("[Send to %s]: %s", address.toStdString().c_str(),
                                   msg.toStdString().c_str()));
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
    switch (nType) {
    case RECV_SOCKET:
        pWnd->addClient(QString().sprintf("%s:%d", szIP, nPort));
        break;
    case RECV_DATA:
        emit pWnd->recvMsg(QString().sprintf("[Received from %s:%d]: %s", szIP, nPort, szRecv));
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
    switch (nType) {
    case RECV_SOCKET:
        //pWnd->addClient(QString().sprintf("%s:%d", szIP, nPort));
        break;
    case RECV_DATA:
        emit pWnd->clientRecvMsg(QString().sprintf("[Received from Server %s:%d]: %s", szIP, nPort, szRecv));
        break;
    case RECV_CLOSE:
        //pWnd->delClient(QString().sprintf("%s:%d", szIP, nPort));
        break;
    case RECV_ERROR:
        break;
    default:
        break;
    }
    return 0;
}

void MainWindow::on_pushButton_tcpClient_Connect_clicked()
{
    if (!m_bIsConnect)
   {
        IniConfig config(INI_PATH);
        QString section = QString().sprintf("TcpClient%d", TCP_CLIENT_ID);
        config.SetValue(section, "Address", ui->comboBox_tcpClient_serverIP->currentText());
        config.SetValue(section, "Port", ui->lineEdit_tcpClient_serverPort->text());
        InitSocket(TCP_CLIENT_ID, TCP_CLIENT, INI_PATH, NULL);
        if (!TCPConnect(TCP_CLIENT_ID, 50000))
        {
            m_bIsConnect = true;
            ui->pushButton_tcpClient_Connect->setText("断开");
            ui->pushButton_tcpClient_Connect->setStyleSheet("background-color: rgb(255, 0, 0);");
            m_thread.start();
        }
        else
        {
            m_bIsConnect = false;
            ui->pushButton_tcpClient_Connect->setText("连接");
            ui->pushButton_tcpClient_Connect->setStyleSheet("background-color: rgb(50, 50, 255);");
        }
    }
    else
    {
//        UninitSocket(TCP_CLIENT_ID);
//        m_bIsConnect = false;
        ui->pushButton_tcpClient_Connect->setText("连接");
        ui->pushButton_tcpClient_Connect->setStyleSheet("background-color: rgb(50, 50, 255);");
        m_thread.stop();

    }
}

void MainWindow::on_pushButton_tcpClient_send_clicked()
{
    QString msg = ui->textEdit_tcpClient_send->toPlainText();
    TCPSend(TCP_CLIENT_ID, msg.toStdString().c_str());
    emit clientRecvMsg(QString().sprintf("[Send]: %s", msg.toStdString().c_str()));
}

void MainWindow::on_pushButton_tcpClient_recv_clicked()
{
   // m_thread.start();
}

CTcpClientRecvThread::CTcpClientRecvThread()
    : m_bStop(false)
{

}

void CTcpClientRecvThread::run()
{
    char szRecv[1024*4] = { 0 };
    while(!m_bStop)
    {
        if (TCPRecv(TCP_CLIENT_ID, szRecv, sizeof(szRecv), 1000) == 0)
            emit pWnd->clientRecvMsg(QString().sprintf("[Recv from server]: %s", szRecv));
    }
}

void CTcpClientRecvThread::stop()
{
    m_bStop = true;
}
