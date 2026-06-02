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
/*
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
*/

//P5740 【深基7.例9】最厉害的学生
/*
每名同学的信息：
姓名（不超过 8 个字符的仅有英文小写字母的字符串）、
语文、数学、英语成绩（均为不超过 150 的自然数）。
总分最高的学生就是最厉害的，

请输出最厉害的学生各项信息
（姓名、各科成绩）。
如果有多个总分相同的学生，
输出靠前的那位。
*/

/*
分析，
1、使用结构体，存储学生信息
建立学生数组
2、计算总分
3、总分排序 最多1000人，冒泡排序
*/

/*
#include <iostream>
using namespace std;

const int N=1010;

struct stu{
    char a[10]={};
    int x1=0,x2=0,x3=0,re=0;
}stu[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",stu[i].a,&stu[i].x1,&stu[i].x2,&stu[i].x3);
        stu[i].re=stu[i].x1+stu[i].x2+stu[i].x3;
    }
    int max=stu[0].re;
    int x=0;
    for(int i=0;i<n;i++){
        if(stu[i].re>max){
            max=stu[i].re;
            x=i;
        }
    }
    printf("%s %d %d %d",stu[x].a,stu[x].x1,stu[x].x2,stu[x].x3);
    return 0;
}
*/


// 6.1 儿童节快乐啊！六月全勤计划！
//P5741 【深基7.例10】旗鼓相当的对手 - 加强版


//某对学生每一科成绩的分差都不大于 5
//且总分分差不大于 10
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>   // 新增：保证 abs 函数可用
using namespace std;

const int N=1005;

struct stus{
    char nam[10];
    int num1,num2,num3;
    int sum;
}stu[N];        //结构体命名与机构体类型命名请区分开来

bool panduan(const stus& a, const stus& b){            //绝对值函数很好用哦
    if (abs(a.sum - b.sum) > 10) return false;
    // 各科分差绝对值 ≤ 5
    if (abs(a.num1 - b.num1) > 5) return false;
    if (abs(a.num2 - b.num2) > 5) return false;
    if (abs(a.num3 - b.num3) > 5) return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",stu[i].nam,&stu[i].num1,&stu[i].num2,&stu[i].num3);
        stu[i].sum=stu[i].num1+stu[i].num2+stu[i].num3;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(panduan(stu[i],stu[j])){
                printf("%s %s\n",stu[i].nam,stu[j].nam);
            }
        }
    }
    return 0;
}
*/

//P5742 【深基7.例11】评等级
//结构体里面构建函数 怎么做

//现有 N 名同学
//学号、学业成绩 素质拓展成绩、综合分数（实数）
//并且计算综合分数（分别按照 70% 和 30% 权重累加）
//还需要在结构体中定义一个成员函数，
//返回该结构体对象的  学业成绩和素质拓展成绩的总分 五个量

/*
本题存在精度误差问题，请将 a * 0.7 + b * 0.3 与 80 比较 转化为 a * 7 + b * 3 与 800 比较。
当然通过本题很容易啦，本题只是为了帮助你训练结构体的使用方法。
*/

#include <iostream>
using namespace std;

struct stu{
    int a;
    int b,c,d;
    int s(){
        return b+c;
    }
    
}students[1005];

int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    while(n--){
        scanf("%d %d %d",&students[i].a,&students[i].b,&students[i].c);
        students[i].d=students[i].b*7+students[i].c*3;
        i++;
    }
    int j=0;
    while(j<i){
        if(students[j].s()>140 && students[j].d>=800){
            printf("Excellent\n");
        }else{
            printf("Not excellent\n");
        }
        j++;
    }
    return 0;
}