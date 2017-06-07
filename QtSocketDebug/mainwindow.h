#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "socket.h"
#include "QThread"

#define INI_PATH        "SocketDebugger.ini"
#define TCP_SERVER_ID   0
#define TCP_CLIENT_ID   1
#define UDP_ID          2

namespace Ui {
class MainWindow;
}

class CTcpClientRecvThread : public QThread
{
public:
    CTcpClientRecvThread();
    ~CTcpClientRecvThread() {}
    void stop();
protected:
    void run();
private:
    volatile bool m_bStop;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addClient(QString client);
    void delClient(QString client);

signals:
    void recvMsg(QString msg);
    void clientRecvMsg(QString msg);

private slots:
    void on_pushButton_tcpServer_bind_clicked();
    void on_pushButton_tcpServer_send_clicked();
    void on_pushButton_tcpClient_Connect_clicked();
    void on_pushButton_tcpClient_send_clicked();
    void on_pushButton_tcpClient_recv_clicked();

private:
    Ui::MainWindow *ui;
    void IniTcpServerUI();
    void IniTcpClientUI();
    bool m_bIsConnect;
    CTcpClientRecvThread m_thread;
};


#endif // MAINWINDOW_H
