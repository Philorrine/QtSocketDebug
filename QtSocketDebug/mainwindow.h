#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "socket.h"

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
    void recvMsg(QString msg);

private slots:
    void on_pushButton_tcpServer_bind_clicked();

    void on_pushButton_tcpServer_send_clicked();

private:
    Ui::MainWindow *ui;

    //int RecvProc(int nType, const char* szIP, int nPort, int nSize, const char* szRecv);
};

#endif // MAINWINDOW_H
