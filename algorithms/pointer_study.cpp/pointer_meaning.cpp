//指针基本使用方式

//指针函数求n个学生最高分 传入数组
/*
#include <iostream>
using namespace std;

int f(int * p,int n){
    int re=p[0];
    for(int i=0;i<n;i++){
        if(p[i]>re){
            re=p[i];
        }
    }
    return re;
}

int main(){
    int n,a[1001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans;
    ans=f(a,n);
    printf("%d",ans);
    return 0;
}
*/

//采用指针变量表示地址的方法 输入输出数组中的个元素
/*
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int *p=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));  //这里就像 scanf("%s",a);一样，后面放地址哦
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
    delete p;
    return 0;
}
*/

//指针实现数组循环移动
#include<iostream>
using namespace std;
int *solve(int *s,int n,int m){  //指针类型函数？！
    //每个数的指针后移动 m 个
    //求相对位置 x
    int p[10001]; //复制一个p数组  //真的复制到了？
    //下面这个成，每个必须安排到，数组思想
    for(int i=0;i<n;i++){
        p[i]=*(s+i);
    }
    while(m>n){
        m-=n;
    }
    if(m==0) return s;//无需移动
    for(int i=0;i<n-m;i++){
        *(s+i+m)=*(p+i);
    }
    for(int i=0;i<m;i++){
        *(s+i)=*(p+n-m+i);  //修改循环逻辑
    }
    return s;
}
int main(void)
{
    int n,m,s[110];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    int *ans;  //新的指针？
    ans=solve(s,n,m);
    
    for(int i=0;i<n;i++){
        if(i==0)    printf("%d",*ans++ );
        else    printf(" %d",*ans++ );
    }
    return 0;
}


//野指针
void f(int *p1,int *p2){
    int p;
    p=*p1;
    *p1=*p2;
    *p2=p;
}

//改
void f(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//指针不野
void f(int *p1, int *p2) {
    int temp;
    int *p=&temp;
    *p=*p1;
    *p1 = *p2;
    *p2 = *p;
}
//空
void f(int *p1, int *p2) {
    int *p=NULL;
    *p=*p1;
    *p1 = *p2;
    *p2 = *p;
}

//报数
//n人围成一圈，报数3退出，求最后留下的人的初始编号
//约瑟夫环问题
#include<iostream>
using namespace std;

int main()
{
    /*********Begin*********/
    int n;
    scanf("%d", &n);
    
    int last = 0;  // 当只有1人时，幸存者编号为0（0-based）
    for (int i = 2; i <= n; i++) {
        last = (last + 3) % i;  // 步长为3
    }
    
    printf("%d\n", last + 1);   // 转换为1-based编号
    /*********End**********/
    return 0;
}

//同类型内存加减法
//用一个函数实现两个字符串的比较，即自己写一个strcmp函数
#include <iostream>
using namespace std;
int strcmp(char *p1,char *p2){
	/*********Begin*********/
    return *p1-*p2;
	/*********End**********/
}
int main(void)
{
	char a[110],b[110];
	scanf("%s%s",a,b);
	if(strcmp(a,b)>0)
		printf("%s", a);
	else
		printf("%s", b);


    return 0;
}