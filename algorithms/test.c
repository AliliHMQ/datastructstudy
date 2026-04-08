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

//S=1!+2!+...+n!
#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
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
	  /*********End**********/ 
       return 0;
	}

//水仙花数
#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
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
	  
	  /*********End**********/ 
       return 0;
	}
//完数
#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
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
	  /*********End**********/ 
       return 0;
	}
