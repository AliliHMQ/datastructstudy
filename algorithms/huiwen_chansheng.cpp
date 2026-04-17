//产生回文数
#include <iostream>
using namespace std;

void solve(){
    for(int i=200;i<=3000;i++){
        int x=i;
        int reverse=0;
        while(x>0){
            reverse=reverse*10+x%10;//权重递增
            x/=10;
        }
        if(reverse==i){
            printf("%d\n",i);
        }
    }

}

int main(){
    solve();
    return 0;
}

/*
亲密数
#include<iostream>
using namespace std;


// 计算 n 的所有真因子之和（不包括 n 本身）
int sumOfFactors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    for (int a = 2; a <= 3000; a++) {
        int b = sumOfFactors(a);
        // 避免重复输出，只输出 a < b 的情况，且 b 也在 3000 以内
        if (b > a && b <= 3000 && sumOfFactors(b) == a) {
            cout << "(" << a << "," << b << ")";
        }
    }
    return 0;
}

*/
/*
#include<stdio.h>
void solve(){
    int sum(int n){
        int sum=0;
        for (int i=1;i<=n/2;i++) {
            if (n%i==0) {
                sum+=i;
            }
        }
        return sum;
    }
    for (int a=2; a<3000; a++) {
        int b=sum(a);
        if (b>a && b<3000 && sum(b)==a) {
            printf("(%d,%d)", a,b);
        }
    }
}
int main(void)
{  
    solve();
    return 0;
}
*/
