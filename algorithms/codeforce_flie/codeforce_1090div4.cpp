//好困啊这个时间点好阴间，请不要吸引bug
/*
#include <iostream>
using namespace std;

int main(){

   return 0;
}
*/

//1、A. The 67th Integer Problem
//integer y such that the value of min(x,y)∗ is maximized. 这个地方很迷
//在之后WA了，因为！Y超出范围了  题目要求：整数y(−67≤y≤67） 使得min（x，y)是最大化的。

/*#include <iostream>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    if(x==67) printf("67\n"); //在这里改了一下，其实整体 x==y 也行
    else printf("%d\n",x+1);
   }
   return 0;
}*/


//2、B. The 67th 6-7 Integer Problem
//这个很简单啊，数里面找最大，当然最后算和的时候用数学方法简直是绝妙

/*#include <iostream>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   int max;
   for(int j=0;j<n;j++){
    //每行求和
    int sum=0;
    for(int i=0;i<7;i++){
    int x;
    scanf("%d",&x);
    if(i==0){
        max=x;
    }else{
        if(max<x){
            max=x;
        }
    }
    sum+=-1*x;
    }
    // I like this!
    sum=sum+2*max;
    printf("%d\n",sum);
   }
   return 0;
}*/

//3.C. The 67th Permutation Problem
// you must construct a permutation pof length 3nsuch that ∑n−1i=0median(a3i+1,a3i+2,a3i+3) is maximised.
//这种分组找每组中位数之后求整体最大值的题目真的很神奇！！！
//当然是需要用到构造啦
//但是我发现构造还是需要有 数学原理 根据每一组三个数的大小规律去求简直是太棒啦!

/*#include <iostream>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        //根据每一组三个数的大小规律去求简直是太棒啦 这里

        //小数i+1                     前x项很小
        printf("%d ",i+1);
        //中间和最大的进行分配最好啦    这里的话就是在 第二组数之后分 一中间数，一最大数，轮流
        printf("%d ",x+i*2+1);
        //大数 比中间数大1              
        printf("%d ",x+i*2+2);
    }
    printf("\n");
   }
   return 0;
}*/

//4\构造数组让所有的相邻两个数的最大公约数不同
//构造，让gcd=1,2,3,4,5,6

/*#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        printf("1");
        for(long long j=2;j<=x;j++){
            printf(" %lld",(j-1)*j);
        }
        printf("\n");
    }
    return 0;
}错了*/

//改
//这个质数表需要思考ing
#include <stdio.h>
#include <stdbool.h>
#define M 10005
#define MA 200000
long long p[M];
//写出质数表
void gen(){
    bool ip[MA]={0};
    int c=0;
    for(int i=2;i<MA&&c<M;i++){
        if(!ip[i]){
            p[c++]=i;
            for(int j=i*2;j<MA;j+=i) ip[j]=1;
        }
    }
}
int main(){
    gen();
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
        printf("%lld%c",p[i]*p[i+1],i==n-1?'\n':' ');
    }
}
    return 0;
}