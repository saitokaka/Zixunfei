#include "widget.h"
#include "./ui_widget.h"
#include "jisuan.h"

#include <QRegularExpressionValidator>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QRegularExpression rx("[0-9\\.-]+$");
    QRegularExpression reg("^([1-9]|[1-9]\\d|100)$");
    QValidator *validator=new QRegularExpressionValidator(rx,this);
    QValidator *validator1=new QRegularExpressionValidator(reg,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator1);
    ui->lineEdit_4->setText("80");
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(setlistvalue()));


}

Widget::~Widget()
{
    delete ui;
}



void Widget::setlistvalue()
{
    double finalres;
    QString init1=ui->lineEdit_2->text();
    QString init2=ui->lineEdit_3->text();
    QString init3=ui->lineEdit->text()+"工程咨询费计算如下:";
    QString init4=ui->lineEdit_4->text();
    double num1=init1.toDouble();
    double num2=init2.toDouble();
    double num3=init4.toDouble();
    Jisuan jieguo(num1,num2);
    double res_jiben=jieguo.jibenfei(num1)*num3/100;
    double res_jinhejian=jieguo.jinhejiane(num1,num2);
    QString ouit1,ouit2;
    ouit1= "基本费:"+ouit1.setNum(res_jiben,'f',6)+"万元";
    ouit2= "净核减:"+ouit2.setNum(res_jinhejian,'f',6)+"万元";
    ui->textBrowser->setText(init3+"\n"+ouit1+"\n"+ouit2);

}

