#include "display_guide.h"
#include "ui_display_guide.h"
#include "mainwindow.h"
#include "globalvalue.h"


Display_Guide::Display_Guide(QWidget *parent) :
    QWidget(parent)
{
    //ui->setupUi(this);

}

Display_Guide::~Display_Guide()
{

}

void Display_Guide::paintEvent(QPaintEvent *event)
{
    painter_guide= new QPainter(this);
    painter_guide->setPen(QPen(QColor(11, 67, 127), 3));
    painter_guide->drawRect(0, 0, 200, 200);
    painter_guide->setRenderHint(QPainter::Antialiasing, true);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    pen.setBrush(Qt::blue);
    painter_guide->setPen(pen);

switch(RandomNum)
{
    case 1:
    painter_guide->drawLine(0,100,200,100);
    painter_guide->drawLine(100,100,90,110);
	painter_guide->drawLine(100, 100, 90, 90);
	
    break;
    case 2:
    painter_guide->drawLine(100,0,100,200);
	painter_guide->drawLine(90, 90, 100, 100);
	painter_guide->drawLine(110, 90, 100, 100);
    break;
    case 3:
    painter_guide->drawLine(0,200,200,0);
	painter_guide->drawLine(100, 100, 100, 120);
	painter_guide->drawLine(100, 100, 80, 100);
    break;
    case 4:
    painter_guide->drawLine(200,200,0,0);
	painter_guide->drawLine(100, 100, 120, 100);
	painter_guide->drawLine(100, 100, 100, 120);
    break;
    case 5:
	painter_guide->drawArc(-100,0,200,200, -90*16, 180*16);
	painter_guide->drawLine(90, 90, 100, 100);
	painter_guide->drawLine(110, 90, 100, 100);
	break;
	case 6:
	painter_guide->drawArc(100, 0, 200, 200, 90 * 16, 180* 16);
	painter_guide->drawLine(90, 90, 100, 100);
	painter_guide->drawLine(110, 90, 100, 100);

    break;
    default:
    break;
}

painter_guide->end();
}
