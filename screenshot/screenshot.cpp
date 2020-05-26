#include "screenshot.h"
#include "ui_screenshot.h"

screenshot::screenshot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::screenshot)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start_capture()));
    QMainWindow::setMouseTracking(true);
    QMainWindow::centralWidget()->setMouseTracking(true);
    ui->image_view->setMouseTracking(true);
}

screenshot::~screenshot()
{
    delete ui;
}

void screenshot::start_capture()
{
    int delay_time = ui->lineEdit->text().toUInt();
    if(delay_time > 0)
    {
        this->hide();
        //Sleep(delay_time*1000);
        this->show();
    }
    connect(&dlg, SIGNAL(accepted()),this, SLOT(show_window()));
    connect(&dlg, SIGNAL(rejected()),this, SLOT(show_window()));
    this->hide();
    dlg.refresh();
    dlg.exec();
}

void screenshot::show_window()
{
    ui->image_view->clear();
    this->showNormal();
    this->show();
    ui->image_view->setPixmap(dlg.submap);
}

void screenshot::mouseMoveEvent(QMouseEvent *event)
{
    ui->x_pos->setText(QString::number(QCursor::pos().x()));
    ui->y_pos->setText(QString::number(QCursor::pos().y()));
}

void screenshot::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        start.setX(QCursor::pos().x());
        start.setY(QCursor::pos().y());

    }
}

void screenshot::mouseReleaseEvent(QMouseEvent *event)
{
    end.setX(QCursor::pos().x());
    end.setY(QCursor::pos().y());
}




