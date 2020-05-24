#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class server; }
QT_END_NAMESPACE

class server : public QMainWindow
{
    Q_OBJECT

public:
    server(QWidget *parent = nullptr);
    ~server();

private slots:
    void on_start_server_button_clicked();
    void show_new_connection();
    void show_incoming_msg();
    void send_msg();
private:
    Ui::server *ui;
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;
};
#endif // SERVER_H
