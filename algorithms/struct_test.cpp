//结构体刷题记录
//洛谷


//函数刷题
#include <iostream>
#include <cmath>
using namespace std;

double f(double x,double y){
    //差值？
    double re=sqrt(x*x+y*y);
    return re;
}

int main(){
    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    double c=f(x1-x2,y1-y2)+f(x2-x3,y2-y3)+f(x1-x3,y1-y3);
    printf("%.2f",c);
    return 0;
}