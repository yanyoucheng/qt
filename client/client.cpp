#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}


void client::on_connectButton_clicked()
{
    tcpsocket = new QTcpSocket();
    tcpsocket->bind(2345);
    tcpsocket->connectToHost(QHostAddress(ui->ipEdit->text()), ui->portEdit->text().toUInt());
    connect(tcpsocket, SIGNAL(connected()), this, SLOT(show_new_connection()));

}

void client::show_new_connection()
{
    ui->textBrowser->setText(QString("connected success"));
    connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(show_incoming_msg()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(send_msg()));
}

void client::show_incoming_msg()
{
    char buf[128];
    memset(buf, '\0', 128);
    int readlen = tcpsocket->read(buf, 128);
    ui->textBrowser->append(QString("recv:"+QLatin1String(buf)));
}

void client::send_msg()
{
    char buf[128];
    memset(buf, '\0', 128);
    strcpy(buf, ui->sendEdit->toPlainText().toStdString().c_str());
    tcpsocket->write(buf, strlen(buf));
    ui->textBrowser->append(QString("send:"+QLatin1String(buf)));
    ui->sendEdit->clear();
}
