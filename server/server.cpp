#include "qobject.h"
#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
}

server::~server()
{
    delete ui;
}


void server::on_start_server_button_clicked()
{
    tcpserver = new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any , 1234);
    connect(tcpserver, SIGNAL(newConnection()), this, SLOT(show_new_connection()));
}

void server::show_new_connection()
{
    tcpsocket = tcpserver->nextPendingConnection();
    unsigned int port = tcpsocket->peerPort();
    QString ipaddr = tcpsocket->peerAddress().toString();
    ui->textBrowser->append(ipaddr);
    ui->textBrowser->append(QString::number(port));
    connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(show_incoming_msg()));
    connect(ui->send, SIGNAL(clicked()), this, SLOT(send_msg()));
}

void server::show_incoming_msg()
{
    char buf[128];
    memset(buf, '\0', 128);
    int readlen = tcpsocket->read(buf, 128);
    ui->textBrowser->append(QString("recv:"+QLatin1String(buf)));
}

void server::send_msg()
{
    char buf[128];
    memset(buf, '\0', 128);
    strcpy(buf, ui->sendEdit->toPlainText().toStdString().c_str());
    tcpsocket->write(buf, strlen(buf));
    ui->textBrowser->append(QString("send:"+QLatin1String(buf)));
    ui->sendEdit->clear();
}
