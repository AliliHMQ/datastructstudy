//结构体刷题记录
//洛谷


//函数刷题
/*#include <iostream>
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
*/


//P5738 【深基7.例4】歌唱比赛

#include <iostream>
using namespace std;

int f(int q[],int m){
    int max=q[0];
    int min=q[0];
    int re=0;
    for(int i=0;i<m;i++){
        re+=q[i];
        if(max<q[i]){
            max=q[i];
        }
        if(min>q[i]){
            min=q[i];
        }
    }
    re=re-max-min;
    return re;
}

const int N=101;

int main(){
    int n,m;
    cin >> n >> m;
    //这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分
    int re[N]={};
    for(int j=0;j<n;j++){
        int a[N]={};
        for(int i=0;i<m;i++){
            cin >> a[i]; 
        }
        re[j]=f(a,m);
    }
    int maxt=re[0];
    for(int i=0;i<n;i++){
        if(re[i]>maxt){
            maxt=re[i];
        }
    }
    double re2=0;
    //cout << maxt << endl;
    re2=(double)maxt/(m-2);
    printf("%.2f",re2);
    return 0;
}
