#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class client; }
QT_END_NAMESPACE

class client : public QMainWindow
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_connectButton_clicked();
    void show_new_connection();
    void show_incoming_msg();
    void send_msg();

private:
    Ui::client *ui;
    QTcpSocket *tcpsocket;
};
#endif // CLIENT_H
