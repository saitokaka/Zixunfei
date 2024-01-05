#include "jisuan.h"
#include "QString"

const double low100 =0.34/100;
const double low500 =0.3/100;
const double low1000 =0.26/100;
const double low2000 =0.23/100;
const double low5000 =0.21/100;
const double low10000 =0.18/100;
const double low50000 =0.15/100;
const double lowmax =0.12/100;
QString l100="0-100万元";

Jisuan::Jisuan(double n1,double n2) {



}
double Jisuan::jibenfei(double a){
    double aa=a;
    if(aa<=100){aa=a*low100;}
    if(aa>100&aa<=500){aa=100*low100+(aa-100)*low500;}
    if(aa>500&aa<=1000 ){aa=100*low100+400*low500+(aa-500)*low1000;}
    if (aa>1000&aa<=2000){aa=100*low100+400*low500+500*low1000+(aa-1000)*low2000;}
    if (aa>2000&aa<=5000){aa=100*low100+400*low500+500*low1000+1000*low2000+(aa-2000)*low5000;}
    if (aa>5000&aa<=10000){aa=100*low100+400*low500+500*low1000+1000*low2000+3000*low5000+(aa-5000)*low10000;}
    if (aa>10000&aa<=50000){aa=100*low100+400*low500+500*low1000+1000*low2000+3000*low5000+5000*low10000+(aa-10000)*low50000;}
    if (aa>50000){aa=100*low100+400*low500+500*low1000+1000*low2000+3000*low5000+5000*low10000+40000*low50000+(aa-50000)*lowmax;}
    return aa;
}
double Jisuan::jinhejiane(double c,double b){
    double bb,cc,x;
    bb=c-b;
    x=bb/c;
    if(x>0.05){cc=(bb-c*0.05)*0.05;}
    else {cc=bb*0.05;}
    return cc;
}
