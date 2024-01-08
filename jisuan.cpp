#include "jisuan.h"

const double low100 =0.34/100;
const double equal_100=100*low100;
QString h100="0-100万元：100×3.4‰=0.34万元";
const double low500 =0.3/100;
const double equal_500=equal_100+400*low500;
QString h500="100-500万元：400×3.00‰=1.2万元";
const double low1000 =0.26/100;
const double equal_1000=equal_500+500*low1000;
QString h1000="500-1000万元：500×2.60‰=1.3万元";
const double low2000 =0.23/100;
const double equal_2000=equal_1000+1000*low2000;
QString h2000="1000-2000万元：1000×2.30‰=2.3万元";
const double low5000 =0.21/100;
const double equal_5000=equal_2000+3000*low5000;
QString h5000="2000-5000万元：3000×2.10‰=6.3万元";
const double low10000 =0.18/100;
const double equal_10000=equal_5000+5000*low10000;
QString h10000="5000-10000万元：5000×1.80‰=9万元";
const double low50000 =0.15/100;
const double equal_50000=equal_10000+40000*low50000;
QString h50000="10000-50000万元：40000×1.50‰=60万元";
const double lowmax =0.12/100;




Jisuan::Jisuan(double n1,double n2) {
    double jd=n1;
    QString f1,f2;
    f1=f1.setNum(jd,'f',6);
    f2=f2.setNum(jibenfei(jd),'f',6)+"万元";
    if(jd<=100){finalresult="0-100万元："+f1+"×3.4‰="+f2;}
    if(jd>100&jd<=500){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if(jd>500&jd<=1000 ){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if (jd>1000&jd<=2000){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if (jd>2000&jd<=5000){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if (jd>5000&jd<=10000){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if (jd>10000&jd<=50000){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}
    if (jd>50000){finalresult=h100+"\n"+"100-500万元:"+f1.setNum(jd-500,'f',6)+"×3.0‰="+f2;}



}
double Jisuan::jibenfei(double a){
    double aa=a;
    if(aa<=100){aa=a*low100;}
    if(aa>100&aa<=500){aa=equal_100+(aa-100)*low500;}
    if(aa>500&aa<=1000 ){aa=equal_500+(aa-500)*low1000;}
    if (aa>1000&aa<=2000){aa=equal_1000+(aa-1000)*low2000;}
    if (aa>2000&aa<=5000){aa=equal_2000+(aa-2000)*low5000;}
    if (aa>5000&aa<=10000){aa=equal_5000+(aa-5000)*low10000;}
    if (aa>10000&aa<=50000){aa=equal_10000+(aa-10000)*low50000;}
    if (aa>50000){aa=equal_50000+(aa-50000)*lowmax;}
    return aa;
}
double Jisuan::jinhejiane(double c,double b,double d){
    double bb,cc;
    bb=c-b-d;
    cc=bb*0.05;
    return cc;
}
