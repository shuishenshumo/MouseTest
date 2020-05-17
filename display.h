#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <windows.h>
#include  <QPainter>
#include <QTimer>
#include "mousemove.h"
#include "display_guide.h"

 namespace Ui {
class Display;
}

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();


private:
    Ui::Display *ui;
    mousemove *MOVE;
	Display_Guide *display_guide;
    QTimer *timer;
    QPainter *painter;
    QPainter *painter2;

public slots:
void get_xold(int xold);
void get_yold(int yold);
void get_xnew(int xnew);
void get_ynew(int ynew);
void paintEvent(QPaintEvent *event);
};

#endif // DISPLAY_H
