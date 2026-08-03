/******************* 2026.7.27 **************************/

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


/* H */
#include <bits/stdc++.h>
using namespace std;

long long ceilDiv(int a, int b) {
 return (a + b - 1) / b;
}

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int aday=min(x,y);
    long long re=0;
    
    if(x==0 || y==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        re+=ceilDiv(x,aday);
        //cout<<(x/aday+0.5)<<endl;
    }
    
    cout<<"YES"<<endl;
    cout<<re<<endl;

    return 0;
}

/* L */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    // a: 记录从上次遗忘以来出现的次数
    map<string,int> a;
    // remembered: 当前小明记住的句子集合（用于前缀查询）
    set<string> remembered;
    while(t--){
        int x;
        string s;
        cin>>x>>s;
        if(x==1){
            // 记住并增加计数（若之前被忘记，计数从0重新开始）
            a[s]++;
            remembered.insert(s);
            cout<<a[s]<<endl;
        }else if(x==2){
            // 判断 s 是否为 remembered 中任一字符串的前缀
            bool ok = false;
            if(s.empty()){
                ok = !remembered.empty();
            }else{
                auto it = remembered.lower_bound(s);
                if(it!=remembered.end()){
                    const string &cand = *it;
                    if(cand.size()>=s.size() && cand.compare(0, s.size(), s)==0) ok = true;
                }
            }
            cout<<(ok?"YES":"NO")<<endl;
        }else if(x==3){
            // 忘掉该句（从记忆集合中移除，同时清除计数）
            remembered.erase(s);
            a.erase(s);
        }
    }
    return 0;
}

/* 阶乘加 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    if(!(cin>>a>>b)) return 0;

    // 计算 sum_{i=1..b} floor(a/i)
    // 当 i>a 时 floor(a/i)=0，因此只需遍历到 min(a,b)
    long long limit = min(a, b);
    __int128 total = 0;
    long long i = 1;                        //必须是长整数类型
    while(i <= limit){
        long long v = a / i;                // 当前值
        long long last = a / v;             // 最大 j 使得 a/j == v
        if(last > limit) last = limit;
        total += (__int128)v * (last - i + 1);
        i = last + 1;
    }

    // 输出
    long long ans = (long long)total;
    cout << ans << '\n';
    return 0;
}

 