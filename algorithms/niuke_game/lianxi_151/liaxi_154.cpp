//niuk练习赛 154 场

//A题
//可重集 S={n}，只有一个数n的集合。可重复
//当 x 
//分成a与x-a，那么当a与x-a有大于1的最大公因数时候就行
//之后就变成了a，x-a，两个。设函数能够解决分数判断问题。

#include <iostream>
using namespace std;

int fenshu(int x){
    int m=0;
    for(int i=2;i<x;i++){
        //得到两个数 i 与 x-i 这两个数进行寻找有没有大的，有,返回特征数i
        for(int j=2;j<i;j++){
            if((x-i)%j==0 && i%j==0){
                m=1;
                return i;
                break;
            }
        }
    }
    if(m==0) return m;
}

int main(){
    //输入组数
    int n;
    scanf("%d",&n);
    while(n--){
        int w;
        int re=0;
        scanf("%d",&w);
        while(fenshu(w)){
            re++;
            w=fenshu(w);
        }
        printf("%d\n",re);
    }
    return 0;
}


/*
    1.fenshu(x) 改为返回 x 的最小质因子（如果 x 是合数），否则返回 0。
    2.利用递归 solve(x) 计算一个数能拆成多少个元素：
    3.如果拆不了（质数或1）返回 1；否则拆成 p 和 x-p，分别递归求和。
    4.主函数中调用 solve(w) 得到最终元素个数，存入 re 并输出。
*/

//内存超限
#include <iostream>
#include <cmath>
using namespace std;

// 返回 x 的最小质因子（合数时），否则返回 0
int fenshu(int x) {
    if (x < 2) return 0;
    if (x % 2 == 0) return 2;               // 偶数的最小质因子是 2
    int limit = sqrt(x);
    for (int i = 3; i <= limit; i += 2) {
        if (x % i == 0) return i;
    }
    return 0;                               // x 是质数
}

// 递归计算 x 最终能分成多少个元素
int solve(int x) {
    int p = fenshu(x);
    if (p == 0) return 1;                   // 无法再分，自身就是一个元素
    // 拆成 p 和 x-p，分别继续拆分
    return solve(p) + solve(x - p);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int w;
        scanf("%d", &w);
        int re = solve(w);
        printf("%d\n", re);
    }
    return 0;
}