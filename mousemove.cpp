#include "mousemove.h"
#include "ui_mousemove.h"
#include "globalvalue.h"

int x_old=0,x_new=0,y_old=0,y_new=0;
int delaytime_move=0;
int startFlag = 0;
mousemove::mousemove(QWidget *parent) :
    QWidget(parent)
{
    //setMouseTracking(true);
   
}

mousemove::~mousemove()
{
    //delete ui;
	x_old = 0;
	x_new = 0;
	y_old = 0;
	y_new = 0;


}
void mousemove::mouseMoveEvent(QMouseEvent *event)
{

	if (endflag == 1)
	{
		x_old = 0;
		x_new = 0;
		y_old = 0;
		y_new = 0;
	}

	    delaytime_move = delaytime_display;
        x_old = x_new;
        y_old = y_new;

        x_new = event->pos().x();
		y_new = event->pos().y();
		Sleep(delaytime_move /2);
		if (x_old <580 && y_old <580 && x_new <580 && y_new <580 && x_old >20 && y_old >20 && x_new >20 && y_new >20)
	{
		emit set_xold(x_old);
		emit set_yold(y_old);
		emit set_xnew(x_new);
		emit set_ynew(y_new);
	}
    
}


