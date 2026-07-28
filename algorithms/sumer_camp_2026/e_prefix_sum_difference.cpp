//前缀和与差分


/*一维和二维场景为例子*/

//1.相互为逆运算，如何体现的
/*
一维
定义上来看，
    1.1 pre[n]  pre[i]=pre[i-1]+a[i] 前缀和快速求出任意区间 [l, r] 的和，时间复杂度 O(1)。
    1.2 diff[n] diff[i]=a[i+1]-a[i] 差分解决的是快速对一个区间统一加上一个数c，同样的时间复杂度 O(1)。

    ***你要给 [l, r] 区间加 val，意思就是：                                         diff[i]具有对于后续数据的影响性
        在 l 的位置竖个牌子：“从这里开始，每个数都多加 val”（d[l] += val）
        在 r+1 的位置竖个牌子：“到这里结束，后面别再给我多加 val”（d[r+1] -= val） 

*/

/*
二维
定义上来看，
    1.1 pre[n]  pre[i][j]=a[i][j]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1] 前缀和快速求出任意区间 [l, r] 的和，时间复杂度 O(1)。
    1.2 diff[n]  差分解决的是快速对一个区间统一加上一个数c，同样的时间复杂度 O(1)。


*/


//练习

/* 模板 */
/*
一维前缀和     https://ac.nowcoder.com/acm/problem/226282
一维差分        https://ac.nowcoder.com/acm/problem/226303
二维前缀和     https://ac.nowcoder.com/acm/problem/226333
二维差分        https://ac.nowcoder.com/acm/problem/226337
*/


//一维前缀和
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int main(){
    int num,con;
    cin>>num>>con;
    long long a[N];
    long long sum[N];                               

    sum[0]=0;                                //一般来讲，前缀和差分的下标都是从1开始的，但是为了以防万一加一个
    for(int i=1;i<=num;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];                //这里的求和，是靠加上前面的累加值获得的，不要再写+=了
    }
    
    while(con--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;         //子段和公式
    }
    return 0;
}


//一维差分
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];                  //定义在全部函数外面的静态区 初始值为0
long long diff[N];
long long re[N];

int main(){
    int n,m;
    cin>>n>>m;
    
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        diff[i]+=a[i];
        diff[i+1]-=a[i];
    }
    
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        diff[l]+=k;
        diff[r+1]-=k;
    }
    
    for(int i=1;i<=n;i++){
        re[i]=re[i-1]+diff[i];
    }
    for(int i=1;i<=n;i++){
        cout<<re[i]<<" ";
    }
    
    return 0;
}

//二维前缀和
/*
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N][N];                              //注意这里的二维数组不要开太大了，会编译报错。
long long sum[N][N]; 

int main(){
    int n,w,con;
    cin>>n>>w>>con;
                        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    
    while(con--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<endl;
    }
    return 0;
}
*/


//二维差分
/*
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N][N];                              //注意这里的二维数组不要开太大了，会编译报错。
long long diff[N][N]; 
long long re[N][N]; 

void insret(int x1,int y1,int x2,int y2,int k){
    diff[x1][y1]+=k;
    diff[x2+1][y1]-=k;
    diff[x1][y2+1]-=k;
    diff[x2+1][y2+1]+=k;                    //前缀和边界维护全部在下一位操作
}

int main(){
    int n,w,con;
    cin>>n>>w>>con;
                        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
            insret(i,j,i,j,a[i][j]);            //在（i,j）这个位置加上a[i][j]符合insret函数要求
        }
    }
    
    while(con--){
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        insret(x1,y1,x2,y2,k);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            re[i][j]=diff[i][j]+re[i-1][j]+re[i][j-1]-re[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            cout<<re[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/



/* 练习 */
/* A */
/*给定 n 个整数 求它们两两相乘再相加的和*/

//可以，还是得好好学，一遍过，可以的

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N];
long long sum[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long re=0;
    for(int i=1;i<=n;i++){
        long long x=sum[n]-sum[i];
        re+=a[i]*x;
    }
    cout<<re<<endl;
    return 0;
}


/* B - 领地选择 */
/* 
1.正方形  土地价值和最高
2.已知地图的宽和长以及首都的边长  N,M<=1e3
3.表示了地图上每个地块的价值

(一行两个整数 X,Y，表示首都左上角的坐标。保证最优解是唯一的。)

*/

/*
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N][N];
long long sum[N][N];

int main(){
    int n,m,c;
    cin>>n>>m>>c;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    long long resum=0;            // resum 为 0，但价值可能全为负数

    bool is_first=1;              //标记第一次计算

    int rex=0,rey=0;
    for(int x=1;x<=n-c+1;x++){
        for(int y=1;y<=m-c+1;y++){
            long long nosum=sum[x+c-1][y+c-1]-sum[c+x-1][y-1]-sum[x-1][y+c-1]+sum[x-1][y-1];
            if(is_first || nosum>resum){
                resum=nosum;      //记得要记录最大值！
                rex=x;
                rey=y;
                is_first=0;
            }
        }
    }
    cout<<rex<<" "<<rey<<endl;
    return 0;
}
*/

/* C - 地毯 加强版 */

/*问每个点被多少个地毯覆盖。*/

/* 
1.数据范围有 n≤5000，m≤2×10^5
*/

/*
// 核心运算：C++ 中用 ^ 表示按位异或
    int result = a ^ b;
*/
/*
//用差分，加和
#include <bits/stdc++.h>
using namespace std;

const int N=5010;
int diff[N][N];
long long re[N][N];

void inser(int x1,int y1,int x2,int y2)
{
    diff[x1][y1]+=1;
    diff[x2+1][y1]-=1;
    diff[x1][y2+1]-=1;
    diff[x2+1][y2+1]+=1;
}

int main(){
    int n,m;
    cin>>n>>m;

    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        inser(x1,y1,x2,y2);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            re[i][j]=diff[i][j]+re[i-1][j]+re[i][j-1]-re[i-1][j-1];
            ans+=(i+j) ^ re[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/




/* D - 加和游戏 CodeForces - 1920B  */
//每个测试用例的第一行包含三个整数

//一维差分吗 感觉不像

//输出一个整数——双方都最优操作后数组的元素和。
//游戏分为两个步骤


//有大小的话先排序吧
//第一步的话 移除元素数目留给后面的全是正数的话 会选择移除k个最大的数
//第二步里面 由于面对的全是正数 那么就想要挑选前x大的数为负数 之后相加

//第一步的分析错误

#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int a[N];
long long sum[N];

int main(){


    return 0;
}


/*
典型解法是先排序，
枚举Alice移除的数量（0到k），
然后计算Bob操作后的最小和，取最大值。
*/

//枚举去掉的数然后对每次产生的前缀和数组找最大值

#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
long long sum[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        bool f=1;
        long long re=0;
        sort(a.begin(),a.end());
        for(int i=0;i<=k;i++){
            long long nsum=sum[n-i]-2*(sum[n-i]-sum[max(0,n-i-x)]);
            if(f || re<nsum){
                re=nsum;
                f=0;
            }
        }
        cout<<re<<endl;
    }

    return 0;
}
