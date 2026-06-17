/*#include <stdio.h>

int main(){
    double a,b,c,sum,re;
    scanf("%lf %lf %lf",&a,&b,&c);
    sum=a+b+c;
    re=sum/3.0;
    printf("%.1f",re);
    return 0;
}
    
#include <stdio.h>

int main(){
    double a,re;
    scanf("%lf",&a);
    re=a/1.60934;
    printf("%.3f",re);
    return 0;
}*/
/*#include <stdio.h>

int main(){
    double q[10];
    int n1=0,n2=0,n3=0;               //计数
    double N1=0.0,N2=0.0,sum1=0.0,sum2=0.0,re1=0.0,re2=0.0;      //算平均数
    for(int i=0;i<10;i++){
        scanf("%lf",&q[i]);
        if(q[i]<0){
            n2++;
            sum2+=q[i];
        }else if(q[i]>0){
            n1++;
            sum1+=q[i];
        }else{
            n3++;
        }
    }
    N1=n1;
    N2=n2;
    re1=sum1/N1;
    re2=sum2/N2;
    printf("%d\n%d\n%d\n",n1,n2,n3);
    if(n1==0){
        printf("0\n");
    }else{
        printf("%.2f\n",re1);
    }
    if(n2==0){
        printf("0\n");
    }else{
        printf("%.2f\n",re2);
    }
    return 0;
}*/

//求 sqrt a
/*#include <stdio.h>
#include <math.h>
int main(){
    double n,a=0.0,b=0.0,dis=1e-5;
    scanf("%lf",&n);
    a=n/2.0;//初始
    do{
       b=0.5*(a+n/a);
       if(abs(a-b)<dis){
        break;
       }
       a=b;
    }while(1); //只要不break就不会出循环
    printf("sqrt(%f) = %.8f\n",n,a);
    return 0;
}*/

/*#include <stdio.h>
int main(){
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int max=a[0];
    for(int i=0;i<3;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("%d",max);
    return 0;
}*/

/*#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("even");
    }else{
        printf("odd");
    }
    return 0;
}*/

//逻辑判断是否为闰年
/*#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if((n%4==0 && n%100!=0) || n%400==0){
        printf("闰年\n");
    }else{
        printf("不是闰年\n");
    }
    return 0;
}*/

//韩信点兵
/*#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    //枚举
    for(x=1;x<3000;x++){
        if(x%5==1 && x%6==5 && x%7==4 && x%11==10){
            printf("x1=%8d\n",x);
        }
    }

   //break妙用
   for(x=1;x<3000;x++){
        if(x%5==1 && x%6==5 && x%7==4 && x%11==10){
            printf("x2=%8d\n",x);
            break;
        }
    }

   //#include <stdlib.h>里面的exit(0);语句
   for(x=1; ;x++)
   {
        if(x%5==1 && x%6==5 && x%7==4 && x%11==10){
            printf("x3=%8d\n",x);
            exit(0);
        }
    }

    //计数数值
    int find=0;
    for(x=1;find!=0;x++)
    {
        if(x%5==1 && x%6==5 && x%7==4 && x%11==10){
            printf("x4=%8d\n",x);
            find=1;
        }
    }

    //bool条件赋值
    int a=0;
    do
    {
        x++;
        a=(x%5==1 && x%6==5 && x%7==4 && x%11==10);
        printf("x5=%8d\n",x);
    } while (!a);

    //do...while...
    do{
        x++;
        printf("x6=%8d\n",x);
    }while(!x%5==1 && x%6==5 && x%7==4 && x%11==10);

    //return 0大法
    for(int i=1; ;i++)
    {
        if(i%5==1 && i%6==5 && i%7==4 && i%11==10){
            printf("x7=%8d\n",i);
            return 0;
        }
    }
    return 0;
}*/

/*#include <stdio.h>

int main(){
    int n;
    for(n=100;n<=300;n++){
        if(n%3==0) continue;
        printf("%d ",n);
    }
    //printf("\n");
    return 0;
}*/

/*
#include<stdio.h>
int main(void)
{
    
    const int N=1e4;
    int q[N];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    int m;
    scanf("%d",&m);
    int re=0;
    for(int i=0;i<n;i++){
        if(q[i]==m){
           re++;
        }
    }
    printf("%d",re);
    
    return 0;
}

//这个数组需要注意，非常神奇
#include<stdio.h>
int main(void)
{
    
    int n1,n2;
    int q[11][11]={};
    scanf("%d %d",&n1,&n2)
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            scanf("%d",&q[i][j]);
        }
    }
    int max[11]; //每行最大的数
    int a[11];   //每行最大数对应的列坐标
    for(int i=0;i<n1;i++){
        max[i]=q[i][0];
        a[i]=0;
        for(int j=0;j<n2;j++){
            if(q[i][j]>max[i]){
                max[i]=q[i][j];
                a[i]=j;
            }
        }
    }
    int found=0;   // 是否找到鞍点
    for(int i=0;i<n1;i++){
        int col=a[i];          // 最大值所在的列
        int col_min=1;      // 假设是列最小
        for(int k=0;k<n1;k++){
            if(q[k][col]<max[i]){   // 如果有比它小的，则不是列最小
                col_min=0;
                break;
            }
        }
        if(col_min){
            printf("Array[%d][%d]=%d",i,col,max[i]);
            found=1;
            break;   // 题目保证最多一个鞍点
        }
    }
    if(!found){
        printf("None");
    }
    
    return 0;
}

//杨辉三角
#include<stdio.h>
int main(void)
{
    
    int q[10][10]={};
    q[0][0]=1;
    for(int i=1;i<10;i++){
        q[i][0]=1;
        q[i][i]=1;
        for(int j=1;j<i;j++){
             q[i][j]=q[i-1][j-1]+q[i-1][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",q[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}

*/

//2026.4.8恢复
/*#include <stdio.h>

int main(){
    //编写一个程序，输入学生人数和每个人的成绩，计算平均成绩。
    double a,b,c,sum;
    scanf("%lf %lf %lf",&a,&b,&c);
    sum=(a+b+c)/3.0;
    if(sum<=0){
      printf("the number of students:the scores:average=0.00");
    }else{
        printf("the number of students:the scores:average=%.2f",sum);
    }
    return 0;
}
*/

//有一些事情会让你重新选择，看到你内心真正想要的，无所畏惧地坚持自己
//或许七八月份你能选择它
/*#include<stdio.h>
	int main(void)
	{  
	  
	  int re=1;
      int n;
      scanf("%d",&n);
      while(n>0){
          int x;
          x=n%10;
          re*=x;
          n/=10;
      }
      printf("%d",re);
	  
       return 0;
}
*/
/*
//S=1!+2!+...+n!
#include<stdio.h>
	int main(void)
	{  
	  
	  int n;
      scanf("%d",&n);
      int sum=0;
      if(n>0){
          for(int i=1;i<=n;i++){
              int x=1;
              for(int j=1;j<=i;j++){
                  x*=j;
              }
              sum+=x;
          }
      }else if(n==0){
          sum=1;
      }else{
          sum=0;
      }
	  printf("%d",sum);
	  
       return 0;
	}

//水仙花数
#include<stdio.h>
	int main(void)
	{ 
      int n;
      scanf("%d",&n);
	  for(int i=100;i<999;i++){
          int a,b,c;
          a=i%10;
          b=((int)(i/10))%10;
          c=(int)(i/100);
          if(c*c*c+a*a*a+b*b*b==i){
             printf("%d ",i);
          }
      }
	  
	    
       return 0;
	}
//完数
#include<stdio.h>
	int main(void)
	{  
	        
	  int n;
      scanf("%d",&n);
      for(int i=2;i<=n;i++){
          int x=i;
          int sum=0;
          for(int j=1;j<x;j++){
              if(x%j==0){
                  sum+=j;
              }
          }
          if(sum==x){
              printf("%d\n",x);
          }
      }
	       
       return 0;
	}
//分数求和
#include<stdio.h>
	int main(void)
	{  
	    
	  double n,sum=1;
      for(int i=2;i<101;i++){
          if(i%2==0){
              sum+=-1*(1.0/i);
          }else{
              sum+=1*(1.0/i);
          }
      }
	  printf("%.3f",sum);
	    
       return 0;
	}
//小球高度
#include<stdio.h>
	int main(void)
	{  
	    
	  double h,n;
      scanf("%lf %lf",&h,&n);
      double sum=h;
      for(int i=0;i<n;i++){
          h/=2.0;
          sum+=h*2;
      }
      sum=sum-2*h;
      printf("%.2f %.2f",h,sum);
	    
       return 0;
}

//求其最大公约数和最小公倍数。
#include<stdio.h>
	int main(void)
	{  
	    
	  int n,m;
      int re1=1,re2=1;
      scanf("%d %d",&n,&m);
      for(int i=1;i<=n*m;i++){
          if(n%i==0 && m%i==0 && i<=n && i<=m){
             re1=i;
          }
      }
      re2=re1*(n/re1)*(m/re1);
      printf("最大公约数是:%d\n",re1);
	  printf("最小公倍数是:%d\n",re2);
	    
       return 0;
	}
//字符串统计
#include<stdio.h>
#include <ctype.h>
	int main(void)
	{  
	    
	  int letter = 0, digit = 0, space = 0, other = 0;
    char ch;

    // 逐字符读取，直到换行符
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            letter++;
        } else if (isdigit(ch)) {
            digit++;
        } else if (ch == ' ') {
            space++;
        } else {
            other++;
        }
    }

    printf("%d %d %d %d\n", letter, digit, space, other);
	  
	    
       return 0;
	}
//s=a+aa+aaa+aaaa+aa...a
#include<stdio.h>
	int main(void)
        {  
        
	  int x,n;
      int sum=0;
      scanf("%d %d",&x,&n);
      int p=1;
      for(int i=0;i<n-1;i++){
          p*=10;
      }
      for(int i=1;i<=n;i++){
          sum+=i*p*x;
          p/=10;
      }
	  printf("%d",sum);
	    
       return 0;
	}
//数组
#include<stdio.h>
int main(void)
{
    
    int x,y;
    int a[11][11]={};
    scanf("%d,%d",&x,&y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int max=a[0][0];
    int w=0,b=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a[i][j]>max){
                max=a[i][j];
                w=i;
                b=j;
            }
        }
    }
    printf("Input m, n:Input %d*%d array:\n",x,y);
    printf("max=%d, row=%d, col=%d",max,w+1,b+1);
    
    return 0;
}
*/

//作业练习
//递归，我又不会了
/*
#include <stdio.h>

int f(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        //return f(n)*f(n-1);//在 else 分支里调用了 f(n) * f(n-1)，其中 f(n) 会再次调用自身且参数 n 没有减小，导致无限递归，最终栈溢出。
        return n*f(n-1);
        }
}

int main(){
    int n;
    scanf("%d",&n);
    int re=f(n);
    printf("%d",re);
    return 0;
}
*/

//递归找最大的实数
/*
#include<stdio.h>

int main(){
    int n;
    double a[1001]={};
    scanf("%d",&n);
    scanf("%lf",&a[0]);
    double max=a[0];
    int m=0;
    for(int i=1;i<n;i++){      //循环去找，过不了，不知 -(T_T)-?
        scanf("%lf",&a[i]);
        if(a[i]>max){
            max=a[i];
            m=i;
        }
    }
    printf("%.3f %d",max,m);
    return 0;
}
*/

/*
#include <stdio.h>

double max_v;
int max_p;

void search(double a[], int i, int n) {
    if (i>=n) return;
    if (a[i]>max_v) {
        max_v=a[i];
        max_p=i;
    }
    search(a,i+1,n);  //移动到下一个比较
}

int main() {
    int n;
    double a[1001];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    
    max_v=a[0];
    max_p=0;
    search(a,1,n);   //从第一个数开始比较
    
    printf("%.3f %d\n", max_v, max_p);
    return 0;
}
*/
/*
//两个A之间的字符串
#include <stdio.h>

int main(){
    char a[42]={""};
    char b[42]={""};
    int re=0;
    scanf("%s",a);
    for(int i=0;i<40;i++){
        if(a[i]=='A'){
            int x=i;
            for(int j=x+1;j<41;j++){
                if(a[j]!='A'){
                    b[re]=a[j];
                    re++;
                }else{
                    break;
                }
            }
            break;
        }
    }
    printf("%d\n",re);
    printf("%s",b);
    return 0;
}

*/

//函数 strcpy

/*#include  <stdio.h>
#include <string.h>

int main(){
    char a[101];
    char s2[101];
    scanf("%s",a);
    strcpy(s2,a);
    printf("%s",s2);
    return 0;
}

//计数
#include <stdio.h>

int main(){
    char str[101];
    fgets(str,101,stdin);
    int l=0,d=0,s=0,o=0;
    for (int i=0;str[i]!='\0'&&str[i]!='\n';i++) {
        if( 'A'<=str[i] && str[i]<='z'){ 
            l++;
        }else if(48<=str[i] && str[i]<=57){ 
            d++;
        }else if(str[i]==' '){     
            s++;
        }else{
            o++;  
        }                
    }
    printf("%d %d %d %d\n",l,d,s,o);
    return 0;
}

//
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[101][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int j=i+1;j<=n;j++)
            {
            a[j][i]+=a[i][j];
            a[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",a[i][j]);
            if(j<n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

*/

//公约数与公倍数
/*#include<stdio.h>
//编写最大公约数GCD函数

int gcd(int x,int y){
    int min=x;
    if(y<x){
        min=y;
    }
    int re=1;
    for(int i=2;i<min;i++){
        if(x%i==0 && y%i==0){
            re=i;
        }
    }
    return re;
}


//编写最小公倍数LCM函数

int lcm(int x,int y){
    /*int max=x;
    if(y>x){
        max=y;
    }
    int re=1;
    for(int i=2;i<max;i++){
        if(x%i==0 && y%i==0){
            re=i;
        }
    }*/
   /* int re=gcd(x,y);
    return x/re*y;
}

int main(void)
{  
   
    int x,y;
    scanf("%d %d",&x,&y);
    int re1=gcd(x,y);
    int re2=lcm(x,y);
    printf("%d %d",re1,re2);
    
    return 0;
}


//优化
#include<stdio.h>

//编写最大公约数GCD函数

int gcd(int x, int y) {
    // 辗转相除法
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}


//编写最小公倍数LCM函数

int lcm(int x, int y) {
    return x / gcd(x, y) * y;  // 先除后乘防止溢出
}
 

int main(void)
{  
    
    int x, y;
    scanf("%d %d", &x, &y);
    int re1 = gcd(x, y);
    int re2 = lcm(x, y);
    printf("%d %d", re1, re2);
   
    return 0;
}
*/


//例题 p247 8.11  指针与二维数组
/*
#include <stdio.h>
int main(){
    //自己写一个数组
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};  //初始化3*4=12个数
    //输出方式 含分界线
    printf("-----------------\n");
    printf("%d,%d\n",*a,a);           //首元地址
    printf("%d,%d\n",a[0],*(a+0));    //0行0列元素地址
    printf("%d,%d\n",&a[0],&a[0][0]);
    printf("-----------------\n");
    printf("%d,%d\n",a[1],a+1);       //1行0列元素地址 1行起始地址
    printf("%d,%d\n",&a[1][0],*(a+1)+0); //1行0列元素地址
    printf("-----------------\n");
    printf("%d,%d\n",a[2],*(a+2));    //2行0列元素地址
    printf("%d,%d\n",&a[2],a+2);
    printf("以上每行首元地址逐个增加16 (int是4字节，每行4个int类型数字；4*4=16)\n");
    //元素值
    printf("-----------------\n");
    printf("%d,%d\n",a[1][0],*(*(a+1)+0));
    printf("%d,%d\n",*a[2],*(*(a+2)+0));
    printf("%d,%d\n",*(a[2]+1),*(*(a+2)+1));
    return 0;
}*/

//循环实验
/*
//项目1 找出最小值
#include <stdio.h>

const int N=1e5+10;  //随便取一个数据范围

int main(){
    //输入一个正整数 n, 再输入 n 个整数
    //使用数组
    int n;
    scanf("%d",&n);
    int a[N]={};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0];
    for(int i=0;i<n;i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    printf("最小数为：%d",min);
    return 0;
}
*/

//项目2 黑洞数问题
//任何一个数字不全相同的三位数
//经有限次 “重排求差”操作
//（即组成该数的数字重排后的最大数减去重排后的最小数）
//总会得到 495 。
//最后所得的 495 即为三位黑洞数，四位黑洞数为6174。

//验证
//生成全部的不同的三位数 验证是否都会回到495
/*
#include <stdio.h>


int *a(int n){
    static int x[3]; //静态全局区存储 安全可靠 如果换成int的话，就会在return时候变成悬空指针很危险
    x[0]=n/100; //百位
    x[1]=(n/10)%10; //十位
    x[2]=n%10; //个位
    return x;
}

int fmin(int *x){
    int min=x[0];
    for(int i=0;i<3;i++){
        if(min>x[i]){
            min=x[i];
        }
    }
    return min;
}

int fmax(int *x){
    int max=x[0];
    for(int i=0;i<3;i++){
        if(max<x[i]){
            max=x[i];
        }
    }
    return max;
}

int fmid(int *x,int max,int min){
    int sum=x[0]+x[1]+x[2];
    return sum-max-min;
}


int main(){
    int n;  //输入三位整数
    scanf("%d",&n);
    
    int *x=a(n); //z会变化的数组

    if (n < 100 || n > 999) {
        printf("输入不是三位数\n");
        return 1;
    }

    //判断
    if(x[0]==x[1] && x[1]==x[2]){
        printf("输入数字不正确，数字需要是不全相同的三位数");
        return 1;
    }
    int i=0;  //次数
    int re=n;
    while(re!=495){
        printf("第%d次重排求差得：",i);
        i++;
        int max=fmax(x);
        int min=fmin(x);
        int mid=fmid(x,max,min);
        int x1=max*100+mid*10+min;
        int x2=min*100+mid*10+max;
        re=x1-x2;
        printf("%d-%d=%d\n",x1,x2,re);
        x=a(re);
    }
    printf("经过 %d 次操作后到达黑洞数 495。\n",i);
    return 0;
}*/

//项目一

/*
1、输入一个正整数n（0<n<9） n个从小到大排好顺序的整数
2、再输入一个整数x
3、把x插入到这组数据中，使该组数据仍然有序
*/

/*
思考角度，加上x的数组排序，由于数据量小，选择冒泡或选择排序
*/
/*
#include <stdio.h>
const int N=20;
int q[N]={};

//优化冒泡排序
void bable_sort(int *q,int x){
    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<x-1;i++){
            if(q[i]>q[i+1]){
                flag=1;
                int p=q[i];
                q[i]=q[i+1];
                q[i+1]=p;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    scanf("%d",&q[n]);

    bable_sort(q,n+1);

    for(int i=0;i<=n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}*/


//项目二  字符串转换成十进制整数
/*
1、输入一个以#结束的字符串

2、滤去所有的非十六进制字符（不分大小写），
1-9 a-f A-F
3、组成一个新的表示十六进制数字的字符串
4、然后将其转换为十进制数后输出。
ps.如果在第一个十六进制字符之前存在字符“-” 则为负数
*/

/* 思考
1、用字符串存储
判断第一个字符 分正负
2、开一个新的字符串，判断，符合则加入
3、输出数字
*/
/*
#include <stdio.h>
#include <string.h>

const int N=1e6+10; //够大了

int main(){
    char ch;
    char a[N]={};
    char b[N]={};
    
    int re=0;
    int x=0;
    while((ch=getchar())!='#'){
        a[x++]=ch;
        if((ch>='0' && ch<='9') ||  (ch>='a' && ch<='f') || (ch>='A' && ch<='F') ){
            b[re]=ch;
            re++;
        }
    }
    long long res=0;
    for(int i=0;i<re;i++){
        char c=b[i];
        int d;
        if(c>='0'&& c<='9') d=c-'0';
        else if(c>='a' && c<='f') d=c-'a'+10;
        else if(c>='A' && c<='F') d=c-'A'+10;
        res=res*16+d;
    }
    if(a[0]=='-'){
        printf("-");
    }
    printf("%lld",res);
    return 0;
}
*/
//

/*
#include <stdio.h>

const int N = 1e6 + 10;

int main() {
    char ch;
    char b[N];
    int len=0;
    int sign=1;          // 1正 -1负
    int found=0;         // 是否已遇到第一个十六进制字符

    while ((ch=getchar())!='#') {
        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F')) {
            if (!found) {
                found=1;
            }
            b[len++]=ch;
        } else {
            if (!found && ch=='-') {
                sign=-1;   // 在第一个十六进制字符前遇到负号
            }
        }
    }
    if (len==0) {
        printf("0\n");
        return 0;
    }

    long long res=0;
    for (int i=0;i<len;i++) {
        char c=b[i];
        int d;
        if(c>='0'&& c<='9') d=c-'0';
        else if(c>='a' && c<='f') d=c-'a'+10;
        else  d=c-'A'+10;
        res=res*16+d;
    }

    printf("%lld\n", sign*res);
    return 0;
}
*/

//结构体学习
/*
#include <stdio.h>
#include <stdlib.h> //有malloc函数
#define LEN sizeof(struct student)  //每次动态开辟的空间大小，统一管理

struct student{     //创建动态单链表
    int n;
    char name[20];
    struct student * next; //链接下一个元素组的地址
};

//建立联系
int n=0; // // 全局变量记录节点个数（可保留供调试）
struct student * creat(void){ //定义函数 填写下一个元素组的地址 返回指向链表头的指针
    struct student * head=NULL;
    struct student * p1,*p2=NULL;
    
    p1=(struct student *)malloc(LEN); //开辟一个定义大小的单元
    if(p1==NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    printf("请输入学号和姓名（格式：学号,姓名），输入学号0结束：\n");
    scanf("%d,%s",&p1->n,p1->name);

    while(p1->n!=0){   //只要有输入就开辟一个加上一个链表元素
        n++;
        if(n==1){
            head=p1;        //第一个节点作为开头
        }else p2->next=p1;  //链接新节点
        //接下来
        p2=p1;      //p2指向当前最后一个有效节点
        //创建下一个节点
        p1=(struct student *)malloc(LEN);
        scanf("%d,%s",&p1->n,p1->name);
        //p2->next=NULL;
    }
    // 使最后一个有效节点的 next 指向 NULL
    if (p2 != NULL) {
        p2->next = NULL;
    }

    // 释放最后输入 n=0 的那个无用节点
    if (p1 != NULL) {
        free(p1);
    }

    return head;   // 返回链表头指针
}

int main(){
    struct student * p1;
    p1=creat();
    //printf("\nn:%d\nname:%d\n",p1->n,p1->name); //输出第一个节点的成员值 (=v=)
    if (p1 != NULL) {
        printf("\n第一个学生的信息：\n学号：%d\n姓名：%s\n", p1->n, p1->name);
    } else {
        printf("链表为空，没有输入任何有效数据。\n");
    }
    return 0;
}
*/

//学生管理系统
/*
#include<stdio.h>
#include<string.h>
int Count;
struct student{
    char sno[20],name[20];
    int math,english,chinese,sum;
};

void print(struct student stu){
    printf("%s %s %d %d %d %d\n",stu.sno,stu.name,stu.math,stu.english,stu.chinese,stu.sum);
}

void query_stu(struct student s[],char *name){
    
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].name, name) == 0) {
            print(s[i]);
        }
    }
    
}

void delete_stu(struct student s[],char *sno){
    
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].sno, sno) == 0) {
            // 将后面的元素依次前移，覆盖掉要删除的元素
            for (int j = i; j < Count - 1; j++) {
                s[j] = s[j + 1];
            }
            break;  // 学号唯一，找到后即可退出
        }
    }
   
}

void update_stu(struct student s[],char *sno,int math,int english,int chinese){
    
    for (int i = 0; i < Count; i++) {
        if (strcmp(s[i].sno, sno) == 0) {
            s[i].math = math;
            s[i].english = english;
            s[i].chinese = chinese;
            s[i].sum = math + english + chinese;
            break;
        }
    }
    
}

int main(void)
{
    int n,q;
    struct student students[50];
    scanf("%d%d",&n,&q);
    Count=n;
    for(int i=0;i<n;i++){
        
        scanf("%s %s %d %d %d", 
              students[i].sno, students[i].name, 
              &students[i].math, &students[i].english, &students[i].chinese);
        students[i].sum = students[i].math + students[i].english + students[i].chinese;
       
    }
    while(q--){
        int op;
        scanf("%d",&op);
        char sno[20],name[20];
        if(op==1){
            scanf("%s",name);
            query_stu(students,name);
        }
        else if(op==2){
            int a,b,c;
            scanf("%s%d%d%d",sno,&a,&b,&c);
            update_stu(students,sno,a,b,c);
            for(int i=0;i<Count;i++){
                print(students[i]);
            }
        }
        else{
            scanf("%s",sno);
            delete_stu(students,sno);
            for(int i=0;i<Count-1;i++)
                print(students[i]);
        }
    }
    return 0;
}
*/

//[项目一]
//利用函数计算素数个数并求和: 
//输入 2 个正整数 m 和 n（2<=m, n<=500），

//统计并输出m 到 n 之间的素数的个数

//以及这些素数的和。
//要求定义并调用函数 prime(m) 
//判断 m 是否为素数，当 m 为素数时
//返回 1，否则返回 0。
/*
#include <stdio.h>

int prime(int m){
    int re=0;
    if(m==1){
        return 0;
    }else if(m==2){
        return 1;
    }else{
        for(int i=2;i<m;i++){
            if(m%i==0){
                re++;
                return 0;
                break;
            }
        }
        if(!re){
            return 1;
        }
    }
}

int main(){
    int n,m,sum=0;
    scanf("%d %d",&n,&m);
    int re=0;
    //n到m
    for(int i=n;i<=m;i++){
        if(prime(i)){
            re++;
            sum+=i;
        }
    }
    printf("%d %d",re,sum);
    return 0;
}
*/

/*
输入年 year，输出该年 1~12 月每个月的天数。
定义并调用函数month_days(year, month)，
该函数返回 year 年 month 月的天数。
*/
/*
#include <stdio.h>

int month_days(int x,int y){
    if(y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12){
        return 31;
    }else if(y==4 || y==6 || y==9 || y==11){
        return 30;
    }else if(x%100!=0 && x%4==0 || x%400==0){
        return 29;
    }else{
        return 28;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=12;i++){
        printf("%d %d\n",n,month_days(n,i));
    }
    return 0;
}
*/

//利用指针找数组最大值：
//输入n(n<=10)个整数并存入数组中，
//利用指针操作数组元素找出最大值，输出到屏幕上。

//指针操作数组
/*
#include <stdio.h>

const int n=11;
int a[n]={};

int max(int *a,int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int re=max(a,n);
    printf("%d",re);
    return 0;
}
*/

/*
(1)求第一门课程的平均分；

（2）找出两门以上课程不及格的学生，
输出他们的全部课程成绩及平均成绩；

（3）找出平均成绩在90分以上或
全部课程成绩都在85分以上的学生，
输出他们的全部课程成绩及平均成绩。
*/

/*
编写函数实现
*/
/*
#include <stdio.h>

double re1(int (*a)[5]){
    double sum1=0;
    for(int i=0;i<4;i++){
        sum1+=a[i][0];
    }
    return sum1/4.0;
}

void sum(int (*a)[5],int x){
    int re=0;
    for(int i=0;i<5;i++){
        if(a[x][i]<=59){
            re++;
        }
    }
    if(re>=2){
        int sumre=0;
        for(int i=0;i<5;i++){
            sumre+=a[x][i];
            printf("%d ",a[x][i]);
        }
        //printf("%d %d %d %d %d ",a[x][0],a[x][1],a[x][2],a[x][3],a[x][4]);
        printf("%lf\n",sumre/5.0);
    }
}

void prin(int (*a)[5]){
    for(int i=0;i<4;i++){
        int re=0;
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=a[i][j];
            if(a[i][j]<85){
                re++;
            }
        }
        if(!re || sum>=450){
            printf("%d %d %d %d %d ",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
            printf("%lf\n",sum/5.0);
        }
    }
}

int main(){
    double re11;
    int a[4][5]={34,56,88,99,89,27,88,99,67,78,99,90,87,86,89,78,89,99,56,77};
    re11=re1(a);
    printf("%lf\n",re11);
    //不及格学生
    for(int i=0;i<4;i++){
        sum(a,i);
    }
    prin(a);
    return 0;
}
*/

/*
输入一段字符
(由空格、字母和数字几种组成，保证开头不为空格)，
里面有若干个字符串，
求这些字符串的长度和，
并输出最长字符串内容,
如果有多个输出最先出现的那个字符串。
以stop作为最后输入的字符串。
*/
/*
#include<stdio.h>
#include <string.h>
int main(void)
{
    
    char s[101],w[101],b[101];
    while(fgets(s,101,stdin)){
        s[strcspn(s,"\n")]=0;
        if(strcmp(s,"stop")==0)break;
        int sum=0,max=0;
        char *p=s;
        while(*p){
            while(*p==' ')p++;
            if(!*p)break;
            char *q=p;
            while(*q&&*q!=' ')q++;
            int len=q-p;
            sum+=len;
            if(len>max){
                max=len;
                strncpy(w,p,len);
                w[len]=0;
            }
            p=q;
        }
        printf("%d %s\n",sum,w);
    }
    return 0;

    
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char a[101],b[101],c[101];
    scanf("%100s%100s%100s",a,b,c);
    char *x=a,*y=b,*z=c;
    // 冒泡排序思想：两两比较交换指针
    if(strcmp(x,y)>0){ char *t=x; x=y; y=t; }
    if(strcmp(x,z)>0){ char *t=x; x=z; z=t; }
    if(strcmp(y,z)>0){ char *t=y; y=z; z=t; }
    printf("%s\n%s\n%s\n",x,y,z);
    
    return 0;
}
*/



//复习内容
//1.字符串函数，整体输入用 scanf("%[^\n]s",str); getchar()吃掉\n;
/*
#include <string.h>
#include <stdio.h>



int main() {
	long long n = 0;
	scanf("%lld", &n);
	getchar();
	for (long long i = 0; i < n; i++) {
		char arr[1000];
		scanf("%999[^\n]s", arr);  //标准不同会报错
		getchar();
		int len = strlen(arr);
		for (int j = len - 1; j >= 0; j--) {
			printf("%c", arr[j]);
		}
		printf("\n");
	}

	return 0;
}

//替换最后一位为 “\0”
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        char str[1010]={};
        fgets(str,sizeof(str),stdin);//会有'\n'    ''\0    '
        int a=strlen(str);
        if (a> 0 && str[a-1] == '\n')
            str[a-1] = '\0';
        for(int i=a-1;i>=0;i--){
            printf("%c",str[i]);
        }
        
        printf("\n");
    }

    return 0;
}

//密码设计
#include <stdio.h>
#include <string.h>

int a=0,b=0,c=0,d=0,e=0,w=0;

void panduan(char m[110],int x){
    if(x>=8 && x<=24){
        a=1;
    }
    for(int i=0;i<=x-1;i++){
        int g=0;
        if(m[i]>='A' && m[i]<='Z'){
            b=1;
        }else{
            g+=1;
        }
        if(m[i]>='a' && m[i]<='z'){
            c=1;
        }else{
            g+=1;
        }
        if(m[i]>='0' && m[i]<='9'){
            d=1;
        }else{
            g+=1;
        }
        if(m[i]=='.' || m[i]=='!' || m[i]=='@'||m[i]=='%'){
            e=1;
        }else{
            g+=1;
        }
        if(g==4){
            w=1;
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        a=0,b=0,c=0,d=0,e=0,w=0;
        char str[110]={};
        scanf("%s",str);
        int x=strlen(str);
        panduan(str,x);
        if(a && !w){
            if(b+c+d+e>=3){
                printf("GOOD PASSWORD\n");
            }else{
                printf("BAD PASSWORD\n");
            }
        }else{
            printf("ERROR\n");
        }
    }
    return 0;
}


//scanf(" %c", &a[i][j]) 读取一个字符（单个字符），并且在读取前会跳过所有空白字符（包括空格、换行、制表符等）
//经过旋转、拉伸、平移、缩放之后的。
//单纯正向判断，还有未考虑情况

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    while(n--){
        char a[25][25]={0};
        int x,y;
        scanf("%d %d",&x,&y);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                scanf(" %c",&a[i][j]);
            }
        }
        if(a[1][1]=='1'){
            printf("Y\n");
        }else{
            printf("O\n");
        }
     
    }
    return 0;
}

//复习牛顿迭代法



#include <stdio.h>
#include <math.h>
int main() {
     double a,b,c,d,m; 
     while(scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&m)==5){               //== 5 就是在判断：是否真的成功读到了 5 个数。
        double x=m;
         for(int i=0;i<100;i++){ 
            double fx=a*x*x*x+b*x*x+c*x+d, fpx=3*a*x*x+2*b*x+c; 
            if(fabs(fpx)<1e-12) break; 
            double nx=x-fx/fpx; 
            if(fabs(nx-x)<1e-8){ 
            x=nx;
            break;
          } 
          x=nx; 
      } 
      printf("%.3lf\n",x); 
      } 
     return 0;
 }
*/

//复习冒泡排序
#include <stdio.h>
#include <stdbool.h>

const int N=1e5+10;
int a[N];

void bubble_sort(int q[],int n){
    bool flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<n-1;i++){
            if(q[i]>q[i+1]){
                flag=1;
                int x=q[i];
                q[i]=q[i+1];
                q[i+1]=x;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}


/*
#include <stdio.h>



int main(){
    int m,n;
    int a[210][210]={};
    scanf("%d %d",&m,&n);
    for()
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            printf("%d ",a[i][0]);
        }
        for(int j=1;j<n;j++){
            printf("%d ",a[m-1][j]);
        }
        for(int i=m-2;i>0;i--){
            printf("%d ",a[i][n-1]);
        }
        for(int j=n-1;j>0;j--){
            printf("%d ",a[0][j]);
        }
    }
    return 0;
}

*/

////
#include <stdio.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int a[210][210];
    int re[40010]={};
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
    }
    
    int lt=0,rt=n-1,tp=0,bt=m-1;
    while(lt<=rt && tp<=bt){
        for(int i=tp;i<=bt;i++)
            printf("%d ",a[i][lt]);
            lt++;
         //从上到下
       
        for(int i=lt;i<=rt;i++)
            printf("%d ",a[bt][i]);
            bt--;
        //从左到右
    
        if(rt>=lt){
        for(int i=bt;i>=tp;i--)
            printf("%d ",a[i][rt]);
            rt--;
        
        }//从下到上

        if(tp<=bt){
        for(int i=rt;i>=lt;i--)
            printf("%d ",a[tp][i]); 
            tp++;
        }//从右到左
    }

    return 0;
}



//
#include <stdio.h>

int n=1e4;

int fei(int x){
    int a[n];
    int sum=0;
    a[1]=1,a[2]=1;  
    for(int i=3;i<=x;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=1;i<x;i++){
        sum+=a[i];
    }
    return sum;
}

int main(){
    int w;
    scanf("%d",&w);
    while(w--){
        int d;
        scanf("%d",&d);
        int re=0;
        while(fei(re)<=d){
            re++;
        }
        printf("%d\n",re-2);
    }
    return 0;
}


//
#include <stdio.h>

long long int fei(int x){
    if(x==1 || x==2){
        return 1;
    }else{
        return fei(x-1)+fei(x-2);
    }
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(fei(n)){
            printf("YES\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

//
#include <stdio.h>
#include <string.h>

const int N=1e4+10;

int main(){
    char s[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char a[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    /*for(int i=0;i<26;i++){
            printf("%c:\n",s[i]);
        }*/
    int re[27]={0};
    char str[1010]={};
    getchar();
    while(scanf("%s",str)!=EOF ){
        int n1=strlen(str);
        //getchar();
        for(int i=0;i<27;i++){
            for(int j=0;j<=n1;j++){
                if(s[i]==str[j] || str[j]==a[i]){
                    re[i]++;
                }
            }
        }
        for(int i=0;i<26;i++){
            printf("%c:%d\n",s[i],re[i]);
        }
    }   
    return 0;
}

//最小量，比较大小递归
#include <stdio.h>

int max(double a[], int n, int re) {
    if (n == 0) {
        return re;
    }
    double tmp = a[re];
    n--;
    if (a[n] > tmp) {
        re = n;
    }
    return max(a, n, re);
}

int main() {
    double a[1010];
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    int x0 = max(a, n, n - 1);
    printf("%.3f %d\n", a[x0]+1e-8, x0);

    return 0;
}