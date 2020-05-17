#ifndef DISPLAY_GUIDE_H
#define DISPLAY_GUIDE_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <windows.h>
#include  <QPainter>



 /*namespace Ui {
class Display_Guide;
}
*/
class Display_Guide : public QWidget
{
    Q_OBJECT

public:
    explicit Display_Guide(QWidget *parent = 0);
    ~Display_Guide();


private:
   // Ui::Display_Guide *ui;
    QPainter *painter_guide;
    QPainter *painter;

public slots:

void paintEvent(QPaintEvent *event);
};


#endif // DISPLAY_GUIDE_H
