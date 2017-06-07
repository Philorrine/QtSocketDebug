#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include "iniconfig.h"

int RecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);

extern MainWindow* pWnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_tcpServer_bind_clicked()
{
    IniConfig config(INI_PATH);
    QString section = QString().sprintf("TcpServer%d", TCP_SERVER_ID);
    config.SetValue(section, "Address", ui->comboBox_tcpServer_localIP->currentText());
    config.SetValue(section, "Port", ui->lineEdit_tcpServer_localPort->text());
    InitSocket(TCP_SERVER_ID, TCP_SERVER, INI_PATH, RecvProc);
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

int RecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv)
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
