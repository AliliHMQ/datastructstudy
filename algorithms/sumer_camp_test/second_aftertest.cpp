//补题

/* A */
//区间完全平方和 子区间个数

//直接寻址表 优化
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int num[N*11];  //前缀和最大值 为数组的大小（直接寻址表）
int a[N];
long long sum[N];

int main(){
    int n;
    cin>>n;
    //初始化前缀和数组
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
        sum[i]=sum[i-1]+x;
    }
    num[0]=1;   //初始化起点
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1000;j++){
            if(sum[i]-j*j<0) break;   //无负数开始的子区间前缀和起点
            ans+=num[sum[i]-j*j];     //子区间前缀和起点个数(含有0所以有可能有多个)
        }
        num[sum[i]]++;   //加入已经作为终点的前缀和 能够作为未来区间和终点的起始点 ***必须同时添加，具有不可重复性。
    }
    cout<<ans<<endl;
    return 0;
}

/*
*关于num[0]=1的初始化是为了展现出 从起点开始，差值为0的含义是有和从0开始的子区间能够构造出一个完全平方数序列
计算 target = 4 - 4 = 0。
执行 ans += num[0]，即 ans += 0。
最终输出 0。错了！
*/


/* O */
//Meet-in-the-Middle（折半枚举）
//四变量问题转化为两个二变量子问题

/*
查找部分设计
auto it = cnt.find(need);      // 去柜子里翻找一遍，把找到的位置记下来
if (it != cnt.end())           // 如果找到了（it不是结束标记）
    ans += it->second;         // 直接拿着刚才记下的位置，把里面的东西拿出来
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b,c,d,e,l,r;
    cin>>a>>b>>c>>d>>e>>l>>r;

    map<ll,ll> cnt;

    for(ll x1=l;x1<=r;x1++){
        for(ll x2=l;x2<=r;x2++){
            cnt[a*x1+b*x2]++;
        }
    }
    ll ans=0;
    for(int x3=l;x3<=r;x3++){
        for(int x4=l;x4<=r;x4++){
            ll need=e-(c*x3+d*x4);
            auto it=cnt.find(need);
            if(it!=cnt.end()){
                ans+=it->second;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}