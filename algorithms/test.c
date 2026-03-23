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
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if((n%4==0 && n%100!=0) || n%400==0){
        printf("闰年\n");
    }else{
        printf("不是闰年\n");
    }
    return 0;
}