/*********************************************/

#include <bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

/*********************************************/
#include <iostream>
#include <vector>
using namespace std;

int main(){

    return 0;
}


//A
/*
每个任务必须且只能执行一次，你可以自由决定执行顺序。
因此只要执行前满足门槛，执行后就不会立刻变成负数。

初始能量       //初始门槛能量 遍历 不够再加呗
初始门槛能量
变化能量
门槛能量
*/

/*
数据大小，long long
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int> PII;

priority_queue<PII,vector<PII>,greater<PII>> pq;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        pq.push({a,b});
    }
    ll senr=0;
    ll fienr=0;
    ll ex=0;
    auto [f,s]=pq.top();
    pq.pop();
    fienr=f;
    ex=s;
    senr=f;
    for(int i=1;i<t;i++){
        fienr=fienr+ex;      //变化后能量
        auto [f,s]=pq.top();       //初始门槛能量f
        ex=s;                      //本轮变化能量s
        pq.pop();
        if(fienr<f){
            long long m=f-fienr;
            fienr+=m;
            senr+=m;
        }
    }
    cout<<senr<<'\n';
    return 0;
}


//J
#include <bits/stdc++.h>
using namespace std;

string ex(string x){
    int re=0;
    for(int i=0;i<x.size();i++){
        re+=x[i]-'0';
    }
    string w;
    while(re>0){
        w+=re/10+'0';
        re/=10;
    }
    return w;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        long long cnt=0;
        while(a.size()>1){
            a=ex(a);
            cnt++;
        }
        cout<<cnt<<" "<<a<<'\n';
    }

    return 0;
}


//H
//使用魔法的次数不能超过物品总数的一半


//E
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int sum[N];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sum[0]=s[0]-'0';
    for(int i=1;i<n;i++){
        int x=s[i]-'1';
        sum[i]=sum[i-1]+x;
    }
    long long re=0;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            if(sum[r]-sum[l]==0 && r-l>re){
                re=r-l;
            }
        }
    }
    cout<<re<<endl;
    return 0;
}



//A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<ll,ll>> t(n);
    for(int i=0;i<n;++i) {
        cin>>t[i].first>>t[i].second;
    }

    sort(t.begin(),t.end(),[](auto &a, auto &b) {
        bool a_p=a.second>=0;
        bool b_p=b.second>=0;
        if(a_p!=b_p)return a_p>b_p; 
        if(a_p)return a.first<b.first;      
        else return a.first+a.second>b.first+b.second; 
    });
    
    ll cur=0;
    ll ans=0;

    for(auto&[h,d]:t) {
        if(cur<h) {
            ans+=h-cur;
            cur=h;
        }
        cur+=d;
    }

    cout<<ans<<'\n';
    return 0;
}


//G
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<bool> u;

bool isPrime(int x){
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2) {
        if(x%i==0) return false;
    }
    return true;
}

void dfs(int pos){
    if(pos==n){
        for(int x:p)cout<<x<<' ';
        cout<<'\n';
        return;
    }
    for (int i=1;i<=n;i++){
        if(!u[i]){
            if(pos==0||isPrime(p.back()+i)) {
                u[i]=true;
                p.push_back(i);
                dfs(pos+1);
                p.pop_back();
                u[i]=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    u.assign(n+1,false);
    dfs(0);

    return 0;
}

//C
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin>>n>>s;

    map<pair<int,int>,int> f;
    f[{0,0}]=0;

    int n0=0,n1=0,n2=0;
    int ans=0;

    for(int i=1;i<=n;i++){
        char ch=s[i-1];
        if(ch=='0')n0++;
        else if(ch=='1')n1++;
        else n2++;

        int diff1=n0-n1;
        int diff2=n0-n2;
        auto s=make_pair(diff1,diff2);

        if(f.count(s)){  //有相等可以相消
            ans=max(ans,i-f[s]);
        }else{
            f[s]=i;  //末尾加入一组对应插值
        }
    }

    cout<<ans<<'\n';
    return 0;
}

//E 并查集 传话数节点
//答案就是最大弱连通块的大小

#include <bits/stdc++.h>
using namespace std;


const long long N=2e5+5;
int fa[N],sz[N];

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        fa[i]=i;    //初始化并查集
        sz[i]=1;
    }

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int a=find(i),b=find(x);
        if(a==b) continue;
        if(sz[a]<sz[b]) swap(a,b);
        fa[b]=a;
        sz[a]+=sz[b];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(fa[i]==i) ans=max(ans,sz[i]);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return 0;
}