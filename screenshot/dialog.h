#ifndef DIALOG_H
#define DIALOG_H

#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QScreen>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QPixmap map, submap;
    void refresh();
private:
    Ui::Dialog *ui;
    QWidget * desktop;
    QPoint start, end;
    int height, width;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // DIALOG_H
