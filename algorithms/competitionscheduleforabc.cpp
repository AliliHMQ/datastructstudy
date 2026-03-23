//链接：https://ac.nowcoder.com/acm/contest/128937/A
#include <iostream>
using namespace std;

long long x(long long a,long long b,long long sum){
    if(a-b<0){
        sum=-1*(a-b);
    }else{
        sum=a-b;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long sum1=0,sum2=0,sum3=0;
        if(c>=a && b>=a){
            sum1=a;
            sum2=x(b,sum1,0);   //差值1
            sum3=x(c,sum1,0);   //差值2
        }else if(b>=c && a>=c){
            sum1=c;
            sum2=x(a,sum1,0);
            sum3=x(b,sum1,0);
        }else{
            sum1=b;
            sum2=x(a,sum1,0);
            sum3=x(c,sum1,0);
        }
        if(sum2==0 && sum3<=1){
            cout << "YES"<<endl;
        }else if(sum2<=1 && sum3==0){
            cout << "YES"<<endl;
        }else if(sum2==1 && sum3==1){
            cout << "YES"<<endl;
        }else{
            cout << "NO"<<endl;
        }
    }
    return 0;
}