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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addClient(QString client);
    void delClient(QString client);

signals:
    void tcpServerRecvMsg(QString msg);
    void tcpClientRecvMsg(QString msg);
    void udpRecvMsg(QString msg);

private slots:
    void on_pushButton_tcpServer_bind_clicked();
    void on_pushButton_tcpServer_send_clicked();
    void on_pushButton_tcpClient_send_clicked();
    void on_pushButton_tcpClient_connect_clicked();
    void on_pushButton_udp_bind_clicked();
    void on_pushButton_udp_send_clicked();

private:
    Ui::MainWindow *ui;
    void InitTcpServerUI();
    void InitTcpClientUI();
    void InitUdpUI();
    bool m_bTcpClientIsConnect;
    bool m_bTcpServerIsBind;
    bool m_bUdpIsCreate;
};


#endif // MAINWINDOW_H
