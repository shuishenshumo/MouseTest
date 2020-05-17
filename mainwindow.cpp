#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>
#include <windows.h>
#include "globalvalue.h"
#include <QTextEdit>
#include <QDir>
#include <QFile>
#include <QTextCodec>



//全局变量
QLine line(0,0,0,0);
QLine line2(0,0,0,0);
QVector<QLine> lines={line2};
int delaytime=0;
int delaytime_Input=0;
int endflag=0;
int RandomNum=1;
int RandomNum_test=1;
int clickFlag = 0;
QString txtname;
/*int x_old3=0;
int x_new3=0; 
int y_old3=0; 
int y_new3=0;
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Init()
{
   ui->label->setHidden(true);
   ui->label_2->setHidden(true);
   ui->label_5->setHidden(true);
   display=new Display(this);
   display->setHidden(true);

   clickFlag = 1;
}
void MainWindow::on_pushButton_clicked()
{
	if (clickFlag == 1)
	{
		display->~Display();
		clickFlag = 0;
	}

	if (clickFlag == 0)
	{
		ui->label->setHidden(true);
		ui->label_2->setHidden(true);
		ui->label_5->setHidden(true);

		display = new Display(this);
        display->setGeometry(400, 100, 1600, 800);
		display->setHidden(false);
		lines.clear();
		generate_random();
			
		clickFlag = 1;
		startFlag = 0;
		
	}
	

}


void MainWindow::on_pushButton_2_clicked()
{

    ui->label->setHidden(false);
    ui->label_2->setHidden(false);
    ui->label_5->setHidden(false);
	//endflag = 1;
   // delaytime=5;
	display->setHidden(true);
    QString str2=QString::number(delaytime_display);
    ui->label_2->setText(str2);
    if(txtname!=0)

    {
    QFile  file(txtname);
    bool res = file.open(QIODevice::WriteOnly | QIODevice::Text );
    if(res)
    {
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
        QTextStream txtOutput(&file);
        txtOutput << current_date << endl;
        txtOutput << QStringLiteral("延迟时间：")<<delaytime_display<<"ms"<< endl;
        qApp->quit();
     }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str=ui->lineEdit->text();
    delaytime_Input=str.toInt();
    delaytime=delaytime_Input;
}

void MainWindow::generate_random()
{
    //RandomNum_test=RandomNum;
    QTime time;
    time=QTime::currentTime(); 
    qsrand(time.msec()+time.second()*1000);
    RandomNum=qrand()%6+1;
    qDebug()<<RandomNum;
}


void MainWindow::on_pushButton_4_clicked()
{
     QDir PathFile;
     PathFile.mkdir("C:/test");
     QString dir_str="C:test";
     QString fileName = dir_str +"/"+ ui->lineEdit_2->text() + ".txt";
     QFile  file(fileName);
     txtname=fileName;
     if(!file.exists())
      {

        qDebug() << QStringLiteral("创建成功") ;
         ui->lineEdit_2->setText(QStringLiteral("创建成功"));
      }
     else
      {
        qDebug() <<QStringLiteral("文件存在") ;
        ui->lineEdit_2->setText(QStringLiteral("哟，还想测一次？"));
      }




}
