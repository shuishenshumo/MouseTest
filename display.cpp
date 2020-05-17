#include "display.h"
#include "ui_display.h"
#include "mainwindow.h"
#include "globalvalue.h"
#include "QTime"

int delaytime_display=0;
QPoint p1,p2;
int x_old2=0,x_new2=0,y_old2=0,y_new2=0;
int RandomNum2;

Display::Display(QWidget *parent) :
    QWidget(parent)
{
    ui->setupUi(this);
	MOVE = new mousemove(this);
	connect(MOVE, SIGNAL(set_xold(int)), this, SLOT(get_xold(int)));
	connect(MOVE, SIGNAL(set_xnew(int)), this, SLOT(get_xnew(int)));
	connect(MOVE, SIGNAL(set_yold(int)), this, SLOT(get_yold(int)));
	connect(MOVE, SIGNAL(set_ynew(int)), this, SLOT(get_ynew(int)));
    MOVE->setGeometry(0, 0, 600, 600);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
     // delaytime_display=delaytime;
    //timer->start(delaytime_display);
    timer->start(1);
	QTime time;
	time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    RandomNum2 = qrand() % 6 + 1;
	display_guide=new Display_Guide(this);
	display_guide->setGeometry(1000, 600, 200, 200);
}

Display::~Display()
{
	MOVE->~mousemove();
	x_old2 =0 ;
	y_old2 = 0;
	x_new2 = 0;
	y_new2 = 0;
}

void Display::get_xold(int xold)
{
    x_old2=xold;
}
void Display::get_yold(int yold)
{
    y_old2=yold;

}

void Display::get_xnew(int xnew)
{
    x_new2=xnew;

}

void Display::get_ynew(int ynew)
{
    y_new2=ynew;
}

void Display::paintEvent(QPaintEvent *event)
{  
	//static int firstflag=1;
	
	if (endflag == 1 || startFlag == 0)
	{   
	    
		line.setLine(0, 0, 0, 0);
		lines.clear();
		startFlag = 1;	
		delaytime_display = delaytime_display+delaytime;
		if (endflag == 1)
		{			
            MOVE->set_xold(0);
            MOVE->set_xnew(0);
            MOVE->set_yold(0);
            MOVE->set_ynew(0);

			x_old2 = 0;
			x_new2 = 0;
			y_old2 = 0;
			y_new2 = 0;
			endflag = 0;

		}
	
		
	}
	if (x_old2 != 0 && y_old2 != 0  )
    {
        line.setLine(x_old2, y_old2, x_new2, y_new2);
        lines.append(line);
    }

	
	if (endflag == 0)
	{
		
		
		painter = new QPainter(this);
		//painter->begin(this);
		painter->setPen(QPen(QColor(11, 67, 127), 3));
        painter->drawRect(0, 0, 600, 600);
        painter->setRenderHint(QPainter::Antialiasing, true);
		
		//画背后的提示圆
		QPen pen;
		pen.setStyle(Qt::DashLine);
		pen.setJoinStyle(Qt::MiterJoin);
		pen.setWidth(4);
		pen.setColor(Qt::blue);
		pen.setBrush(Qt::blue);
		painter->setPen(pen);

		switch (RandomNum)
		{
		case 1:
            painter->drawLine(0, 300, 600, 300);
			if (RandomNum_test != RandomNum)
			{
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;

				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(400, 400);
				RandomNum_test = RandomNum;
			
			}
			break;
		case 2:
            painter->drawLine(300, 0, 300, 600);
			if (RandomNum_test != RandomNum)
			{
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;

				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(700, 100);
				RandomNum_test = RandomNum;
			}
			break;
		case 3:
            painter->drawLine(0, 600, 600, 0);
			if (RandomNum_test != RandomNum)
			{
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;

				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(400, 700);
				RandomNum_test = RandomNum;
			}
			break;
		case 4:
            painter->drawLine(600, 600, 0, 0);
			if (RandomNum_test != RandomNum)
			{
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;

				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(1000, 700);
				RandomNum_test = RandomNum;
			}
			break;
		case 5:
            painter->drawArc(-300, 0, 600, 600, -90 * 16, 180 * 16);
			if (RandomNum_test != RandomNum)
			{
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;

				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(400, 100);
				RandomNum_test = RandomNum;
			}
			break;
		case 6:
            painter->drawArc(300, 0, 600, 600, 90 * 16, 180 * 16);
			if (RandomNum_test != RandomNum)
			{
				
				x_old = 0;
				x_new = 0;
				y_old = 0;
				y_new = 0;
				x_old2 = 0;
				x_new2 = 0;
				y_old2 = 0;
				y_new2 = 0;
				cursor().setPos(1000, 100);
				RandomNum_test = RandomNum;
			}
			break;
		default:
			break;
		}
		
		//画板，自由发挥
		pen.setStyle(Qt::SolidLine);
		pen.setJoinStyle(Qt::MiterJoin);
		pen.setWidth(5);
		pen.setColor(Qt::red);
		pen.setBrush(Qt::red);
        painter->setPen(pen);
        if ((lines.size() > 1))
		{
			
			painter->drawLines(lines);
			
			switch (RandomNum)
			{
			case 1:
                if ((x_new2 > 550) && (y_new2<350) && (y_new2>250))
				{
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
					
                   // firstflag = 0;
					
					
				}
				break;
			case 2:
                if ((y_new2 >550) && (x_new2<350) && (x_new2>250))
				{  
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
					
					//firstflag = 0;
					
				}
				break;
			case 3:
                if ((x_new2 > 550)&&(x_new2<600)&&(y_new2<50))
				{  
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
					
					//firstflag = 0;
					
				}
				break;
			case 4:
				if ((y_new2 <100) && (x_new2>0) && (x_new2<100))
				{   
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
					
					//firstflag = 0;
					}

				break;
			case 5:
                if ((y_new2 >450) && (x_new2<200) && (x_new2>0))
				{  
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
				
					//firstflag = 0;
					
				}
				break;
			case 6:

                if ((y_new2 >450) && (x_new2<600) && (x_new2>400))
				{
					RandomNum_test = RandomNum;
					RandomNum2 = qrand() % 6 + 1;
					RandomNum = RandomNum2;
					endflag = 1;
					
					//firstflag = 0;
				
				}
				break;
			default:
				break;
			}
		}
		
		painter->end();
		

	}
	


}

