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
        a.push_back(0);
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        bool f=1;
        long long re=0;

        sort(a.begin(),a.end());
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }

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