//区间和并与快速幂

//模幂
/*
mod 在运算过程中持续“取余”，
防止数字溢出（超出long long范围），
同时保证每一步的数学等价性。

*/

/*
如果 mod 是质数，根据费马小定理可以对指数取模（b %= mod-1），
但那属于算法优化，与防止溢出无关，这段代码没有做这个优化。
*/

#include <bits/stdc++.h>
using namespace std;

long long fast(long long a,long long b,long long mod){
    long long result=1;
    //1.取模等效吗:模运算满足乘法分配律,但是在计算机里面如果你“算完再取”（即算完 result * a 整个大数再 % mod），中间的大数会变得无限大，直接溢出 long long 导致程序报错或输出乱码。
    a=a%mod;
    while(b){
        if(b&1){
            result=result*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return result;
}

int main(){
    long long a,b,mod;
    cin>>a>>b>>mod;
    cout<<a<<'^'<<b<<" "<<"mod"<<" "<<mod<<"="<<fast(a,b,mod);
    return 0;
}

//2.凡是涉及“乘法”或“幂运算”，且运算在循环中反复累积，必须在每一步乘法后立即取模。凡是仅涉及“加法/减法”且项数较少，可以先加总再取模（但要留意溢出）。


/*B - 人见人爱A^B*/

#include <bits/stdc++.h>
using namespace std;

long long fast(long long a,long long b){
    long long result=1;
    while(b){
        if(b&1){
            result=result*a;
        }
        a*=a;
        b>>=1;
    }
    return result;
}

int main(){
    long long a,b;
    while((cin>>a>>b)){
        if(a==0 && b==0){
            continue;
        }
        cout<<fast(a,b)<<'\n';
    }

    return 0;
}


//保留答案的后三位==对1000取余数 
//改
#include <bits/stdc++.h>
using namespace std;

long long fast(long long a,long long b){
    long long result=1;
    a=a%1000;
    while(b){
        if(b&1){
            result=result*a%1000;
        }
        a=a*a%1000;
        b>>=1;
    }
    return result;
}

int main(){
    long long a,b;
    while((cin>>a>>b)){
        if(a==0 && b==0){
            continue;
        }
        cout<<fast(a,b)<<'\n';
    }

    return 0;
}


//C - 区间合并
/*
1.将所有区间按左端点从小到大排序。
2.依次遍历，维护当前合并区间的右端点 curR。
3.若当前区间的左端点 ≤ curR，说明与前一个区间有重叠或相接，可以合并，更新 curR = max(curR, 当前区间右端点)。
4.若当前区间的左端点 > curR，则出现空隙，无法合并成一个区间，直接输出 "no"。
5.若全部区间都能合并，最终 curL 就是第一个区间的左端点（排序后最小），curR 为最大右端点。
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=5e4+10;
vector<PII> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    // 按左端点升序排序
    sort(a.begin(),a.end());
    //初始化合并区间是第一个区间
    int curl=a[0].first;
    int curr=a[0].second;

    for(int i=1;i<n;i++){
        if(curr>=a[i].first){
            curr=max(curr,a[i].second);
        }else{
            cout<<"no"<<'\n';
            return 0;
        }
    }
    cout<<curl<<" "<<curr<<'\n';
    return 0;
}