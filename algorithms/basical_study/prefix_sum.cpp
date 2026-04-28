//前缀和是什么
//常用的小技巧
//123 4 ——>1234

//前缀和 和 差分是互为逆运算

//原数组 a[n];
//前缀和数组 s[i]=a[1]+a[2]+...+a[i];  //下标一定从1开始 s[0]变成0

//求s[i] //s[i]的作用

//其实可以使用循环 

//s[i]的作用：求一段数的和 比如 l_r O(n)变到O(1);
/*
#include <iostream>
using namespace std;

const int N=100000+10;
int n,m;
//s是前缀和数组
int a[N],s[N]={};

int main(){
    //这个东西的作用就是输入输出不同步，cin速度变快
    //数据大于10,000,000 用scanf而不是cin
    ios::sync_with_stdio(false); //不能使用scanf了 
    cin >> n >> m;
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);//初始化 这里首元就是1

    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }

    return 0;
}
*/

//二维前缀和 左上角方块全部的和
#include <iostream>
using namespace std;

const int N=1010;
int n,m,q;
int a[N][N],s[N][N];

int main(){
    scanf("%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]+s[i-1][j-1]+a[i][j]; //将计算变成一个值 //求前缀和
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);  //集合算法 //计算范围之和
    }
    return 0;
}

