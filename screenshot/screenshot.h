#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include "dialog.h"
#include <QPainter>
#include <QScreen>
#include <QMouseEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class screenshot; }
QT_END_NAMESPACE

class screenshot : public QMainWindow
{
    Q_OBJECT

public:
    screenshot(QWidget *parent = nullptr);
    ~screenshot();
private slots:
    void start_capture();
    void show_window();
private:
    Ui::screenshot *ui;
    QPoint start, end;
    Dialog dlg;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
#endif // SCREENSHOT_H
