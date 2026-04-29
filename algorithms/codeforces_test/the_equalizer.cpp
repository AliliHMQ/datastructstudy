//2217A
//A. The Equalizer

//包含 n 个整数的数组 a 上玩一个游戏
//最后执行操作的人获胜。
//Shaunak 先手,和Yash
//在玩家的回合中，他可以选择某个 a_i > 0 并将其减少 1。

//Shaunak 被允许在整个游戏过程中最多使用一次特殊操作。
//该操作会  替换他的正常回合。
//使用时，所有元素 a_i（1 ≤ i ≤ n）都会被设置为一个给定的特殊值 k。

//如果 Shaunak 总能获胜，则输出 "YES"，否则输出 "NO"

//我想先求和，数组求和，S先的话，最后减一成功那么和为奇数就能赢
// 一个数最小变为0，

//特殊的情况的话，
//普通操作+S先手换成全部化为n*k的和+Y先手 && S结尾，之后n*k需要是2的倍数
//这里我们发现无论前面是否有普通操作，最后就是Y先手 只需要判断 n*k是否能被2整除

#include <iostream>
using namespace std;

const int N=101;
int a[N];

/*int s(int *a,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}*/

int main(){
    int n;
    cin >> n;
    while(n--){
        int x,k;
        cin >> x >> k;
        int sum=0;
        for(int i=0;i<x;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%2==1 || (k*x)%2==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}