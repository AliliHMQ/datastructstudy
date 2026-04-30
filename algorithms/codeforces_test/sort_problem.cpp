//C. 第67个排列问题
//给你一个整数 n。你需要构造一个长度为 3n 的排列 ，

//使得把这个排列划分成 n 个连续的三元组块后，

//这些块的中位数 之和最大。
//最大数之和放在中间就可以,和上次比赛的题非常像
//包含一个整数 数据范围在 1e5 范围里面

//n个不同整数
/*
//2218B 构造中位数最大
#include <iostream>
using namespace std;

const int N=1e6+10;
int a[N]={};

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        
        //for(int i=1;i<=x;i++) a[i]=i; //构造 1-3*x
        for(int i=1;i<=x;i++){
            //分成n份，每份3个
            //正确的构造应该是每组输出最小值、次大值、最大值
            //但题目要求最大化中位数之和。
            //最优策略不是简单地把数字按连续区间分组，而是让每个三元组的“中位数”尽量大。
            //printf("%d %d %d ",3*i-2,3*i-1,3*i);
            printf("%d %d %d ",i,i+x,i+2*x);
        }
        printf("\n");
    }
    return 0;
}
*/
//所以你写的输出方法（按列优先取数）没有达到最大和，
//2218C

//我去蠢死了交到221B去了 我服了 怪不得次次 WA

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        for(int i=1;i<=x;i++){
            //每组的中位数是 2i+n-1
            //最小数分到每组，其次剩下的数分成 x 份。每份两个，较小的作为中位数
            printf("%d %d %d",i,i+x+i-1,i+x+i);
            if(i<x) cout<< " ";
        }
        printf("\n");
    }
    return 0;
}