//前缀和逆运算 差分

//其中定义两个数组
//a[i]=b[1]+b[2]+b[3]+...+b[i]; b[n]=a[n]-a[n-1]

//想一个 b[i] 在这里的话，让a是b的前缀和
//构造并不重要 作用更加重要

//O(n)时间让b数组还原a数组(对b数组求前缀和) 用差分做到 O(1)

//实际上b数组是a数组的相邻两个数之差(b[1]=a[1])
//考虑到有一些数组操作会重合，那么如果产生差值，很必要

//【代码部分】
#include <iostream>

using namespace std;
const int N=1000010;

int n,m;
int a[N],b[N];

//b[n]=a[n]-a[n-1] 求b差分
void insert(int l,int r,int c){
    b[l]+=c;   
    b[r+1]-=c;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++) insert(i,i,a[i]); //插入a

    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }

    for(int i=1;i<=n;i++) b[i]+=b[i-1];  //把b数组变成自己的前缀和

    for(int i=0;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}