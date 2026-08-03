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