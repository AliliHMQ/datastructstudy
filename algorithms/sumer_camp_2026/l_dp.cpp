//动态规划


#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int v[N];
int w[N];
int f[N][N];
int n,m;



int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<v[i]){
                f[i][j]=f[i-1][j];
            }else{
                f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[n][m]<<'\n';
    
    return 0;
}

//完全背包

#include <bits/stdc++.h>
using namespace std;

int t,m;

int main(){
    cin>>t>>m;            
    vector<long long> dp(t+1,0);  
    vector<int> v(1);  //时间
    vector<int> w(1);  //价值
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(x);
        w.push_back(y);
    }
    
    for(int i=1;i<=m;i++){
        for(int j=v[i];j<=t;j++){   
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[t]<<'\n';
    
    return 0;
}


//纸币
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin>>n>>w;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    const int INF=1e9;
    vector<int> dp(w+1,INF);
    dp[0]=0;

    for(int i=0;i<n;i++){
        for(int j=a[i];j<=w;j++){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }

    cout<<dp[w]<<'\n';
    return 0;
}



//回文字符串
#include <bits/stdc++.h>
using namespace std;

const int maxn=1007;
int f[maxn][maxn];
char s[maxn];
int len;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s+1;    // 输入字符串，第一个字母在s[1]
    len=strlen(s+1);

    //每一个只有一个字符的字符串而言 它必是回文
    for(int i=1;i<=len;i++){
        f[i][i]=0;
    }

    for(int k=1;k<len;k++){
        //枚举起点
        for(int i=1;i<=len-k;i++){
            int j=i+k; //终点坐标
            if(s[i]==s[j]){
                f[i][j]=f[i+1][j-1];
            }else{
                f[i][j]=min(f[i+1][j],f[i][j-1])+1;
            }
        }
    }
    cout<<f[1][len];
    return 0;
}

//合并后与这两堆石子相邻的石子将和新堆相邻
