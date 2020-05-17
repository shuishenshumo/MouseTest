#ifndef MOUSEMOVE_H
#define MOUSEMOVE_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <windows.h>
#include  <QPainter>

/*namespace Ui {
class mousemove;
}
*/
class mousemove : public QWidget
{
    Q_OBJECT

public:
    explicit mousemove(QWidget *parent = 0);
    ~mousemove();
    void mouseMoveEvent(QMouseEvent *event);

private:
    //Ui::mousemove *ui;
signals:
    int set_xold(int);
    int set_xnew(int);
    int set_yold(int);
    int set_ynew(int);
};

#endif // MOUSEMOVE_H
