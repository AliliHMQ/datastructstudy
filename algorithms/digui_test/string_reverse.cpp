//用递归法将一个整数n转换成字符串
/*
样例输入：
483
样例输出：
4 8 3 
*/
#include<stdio.h>
void solve(int n){
    int temp=n%10;
    /*********Begin*********/
    if (n/10!=0)  //注意此处的递归终止条件
    solve(n/10);
    
    /*********End**********/
    if(n)
        printf(" %d", temp);
    else
        printf("%d", temp);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}
