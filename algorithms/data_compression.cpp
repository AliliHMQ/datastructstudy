#include <iostream>
using namespace std;

const int A=220;

int main(){
    int n;
    scanf("%d",&n);
    int a[A*A]={};  //一长串数字
    int p=0;
    int cur=0;          // 当前要填充的数字，从0开始
    while(p < n*n){       // 填满为止，不固定循环次数
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            a[p++]=cur;
        }
        cur = 1 - cur;    // 交替0和1，这一步非常妙，我很喜欢
    }
     //赋值完成
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",a[i*n+j]);
        }
        printf("\n");
    }
    return 0;
}