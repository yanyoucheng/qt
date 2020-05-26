#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::refresh()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    map = screen->grabWindow(QApplication::desktop()->winId());
    height = map.height();
    width = map.width();
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    desktop=QApplication::desktop()->screen();
    resize(desktop->width(),desktop->height());
    this->setMouseTracking(true);
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{

}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        start.setX(QCursor::pos().x());
        start.setY(QCursor::pos().y());

    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    end.setX(QCursor::pos().x());
    end.setY(QCursor::pos().y());
    update();
    this->setMouseTracking(false);
}

void Dialog::paintEvent(QPaintEvent *event)
{
    int alpha=1;
    QPainter paint(this);
    paint.begin(this);
    paint.fillRect(0, 0, desktop->width(), desktop->height(), QColor(0, 0, 0, alpha));
    QPen pen(Qt::red,2);
    paint.setPen(pen);
    paint.drawRect(start.x(), start.y(), end.x()-start.x(), end.y()-start.y());
    submap = map.copy(start.x(), start.y(), end.x()-start.x(), end.y()-start.y());
    paint.end();
}
