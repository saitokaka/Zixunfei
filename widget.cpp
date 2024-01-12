#include "widget.h"
#include "./ui_widget.h"
#include "jisuan.h"

#include <QRegularExpressionValidator>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/IMG_4779.jpeg"));

    QRegularExpression rx("[0-9\\.-]+$");
    QRegularExpression reg("^([1-9]|[1-9]\\d|100)$");
    QValidator *validator=new QRegularExpressionValidator(rx,this);
    QValidator *validator1=new QRegularExpressionValidator(reg,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator1);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_4->setText("80");
    ui->lineEdit_5->setText("0");

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(setlistvalue()));


}

Widget::~Widget()
{
    delete ui;
}



void Widget::setlistvalue()
{

    double res_jiben,res_jinhejian,finalres;
    QString init1=ui->lineEdit_2->text();
    QString init2=ui->lineEdit_3->text();
    QString init3=ui->lineEdit->text()+"工程咨询费计算如下（新收费模式）:";
    QString init4=ui->lineEdit_4->text();
    QString init5=ui->lineEdit_5->text();
    double num1=init1.toDouble();
    double num2=init2.toDouble();
    double num3=init4.toDouble();
    double num4=init5.toDouble();
    Jisuan rs(num1,num2);
    res_jiben=rs.jibenfei(num1)*num3/100;
    res_jinhejian=rs.jinhejiane(num1,num2,num4);
     if(res_jinhejian > res_jiben)
     {
         finalres=res_jinhejian;
     }
     else finalres=res_jiben;
    QString ouit1,ouit2,ouit3,ouit4;
    ouit1= "优惠后基本费:"+ouit1.setNum(res_jiben,'f',6)+"万元";
    ouit2= "按净核减计算（扣除超5%追加费）:"+ouit2.setNum(res_jinhejian,'f',6)+"万元";
    ouit3="根据合同条款按高值计取："+ouit3.setNum(finalres,'f',6)+"万元";

    ui->textBrowser->setText(init3+"\n"+rs.finalresult+"\n"+ouit1+"\n"+ouit2+"\n"+ouit3);

}

