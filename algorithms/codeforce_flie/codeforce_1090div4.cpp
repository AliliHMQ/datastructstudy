//好困啊这个时间点好阴间，请不要吸引bug
/*
#include <iostream>
using namespace std;

int main(){

   return 0;
}
*/

//1、

/*#include <iostream>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    if(x==67) printf("67\n");
    else printf("%d\n",x+1);
   }
   return 0;
}*/


//2
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
    sum=sum+2*max;
    printf("%d\n",sum);
   }
   return 0;
}*/

//3.

/*#include <iostream>
using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        //小数i+1
        printf("%d ",i+1);
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
#include <iostream>
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
}
