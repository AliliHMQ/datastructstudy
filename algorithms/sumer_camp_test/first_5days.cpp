//第五天赛

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

/***************** A - pairs ********************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long asum(vector<long long> &place,long long k){           //滑动窗口计算对数
    long long count=0;
    long long l=0;
    for(int r=0;r<place.size();r++){
        while(place[r]-place[l]>k) l++;
        count+=r-l;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        vector<long long> place(n);
        for(long long &x:place) cin>>x;

        sort(place.begin(),place.end());

        cout<<asum(place,k)<<endl;
    }
    return 0;
}



/*题解*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> place(n);
        for(long long &x:place) cin>>x;

        sort(place.begin(),place.end());
        long long re=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n && place[j+1]-place[i]<=k){
                j++;
            }
            re+=j-i;
        }
        cout<<re<<endl;
    }

    return 0;
}
/******************** B *************************/


//R进制转换
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long a;
    int b;
    while(cin>>a>>b){
        if(a<0){
            a=-a;
            cout<<"-";
        }
        vector<char> num;
        long long re=0;
        while(a>0){
            re=a%b;
            char x;
            if(re<10){
                x=re+'0';
            }else{
                x='A'+re-10;
            }
            num.push_back(x);
            a/=b;
        }
        for(int i=num.size()-1;i>=0;i--){
            cout<<num[i];
        }
        cout<<endl;

    }
    return 0;
}

/************** G - 首字母变大写 ***************/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    while(getline(cin,a)){
        a[0]=a[0]+'A'-'a';
        for(int i=0;i<a.size()-1;i++){
            if(a[i]==' '){
                a[i+1]=a[i+1]+'A'-'a';
            }
        }
        cout<<a<<endl;
    }
    return 0;
}

/**************** H - 进击的奶牛 Aggressive Cows G ********************/

/* 贪心+二分查找 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long> &place,long long x,int m){
    long long re=1;
    long long last=0;
    for(int i=0;i<place.size();i++){
        if(place[i]-place[last]>=x){
            re++;
            last=i;
            if(re>=m) return true;
        }
    }
    return false;
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<long long> place(N);
    for(auto &x:place) cin>>x;
    sort(place.begin(),place.end());
    long long low=0,hi=place[N-1]-place[0];
    long long re=0;

    while(low<=hi){
        long long mid=(low+hi)>>1;
        if(check(place,mid,M)){
            re=mid;
            low=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<re<<endl;
    return 0;
}

/******************E - 奇偶排序****************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n),b(n);
        for(long long &x:a) cin>>x;
        for(int i=0;i<n;i++){
            b[i]=a[i];
        }
        sort(a.begin(),a.end());
        int re=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=b[i]%2){
                re=1;
                break;
            }
        }
        if(re){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

/************ C - Number Replacement ***************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,char> mp;

        vector<int> a(n);
        for(auto &x:a) cin>>x;
        string b;
        cin>>b;

        int re=0;
        for(int i=0;i<n;i++){
            int num=a[i];
            char c=b[i];
            if(mp.count(num)){
                if(mp[num]!=c){
                    re=1;
                    break;
                }
            }else{
                mp[num]=c;
            }
        }
        if(re){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

/***********  D - 是猫吗？ ***************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> a;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            a[i]=tolower(x);
        }
        a.erase((a.begin(),a.end()),a.end());
        string re;
        for(int i=0;i<a.size();i++){
            re+=a[i];
        }   
        if(re=="meow"){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}



/************** L - 最大子段和 *****************/
//给出一个长度为 n 的序列 a，选出其中连续且非空的一段使得这段和最大。
/*  完全没有思路*/

/*
Kadane算法（卡丹算法）是用于解决最大子数组和（Maximum Subarray Sum）问题的最优算法。简单来说，它的目标是在一个数组中，找出一个连续的子数组，使其元素之和最大。
虽然Kadane算法通常被归为“贪心/扫描”思想，但它的核心逻辑完全符合动态规划（DP）的定义，是DP中“状态压缩”的经典范例。

核心：制造一个 ans有一个峰值保存的滞后刷新性

那像这样运用循环求解特殊最值的例子还有那些
1. 最大子数组乘积（Maximum Product Subarray）—— “双状态”版
    1.1 状态变量：max_ending（当前最大积）、min_ending（当前最小积）。
    1.2 重置/延续逻辑：遇到 0 时，子数组必须断裂重置。
    1.3 滞后变量：ans 负责记录历史上出现过的最大乘积。

// 核心转移（遇到当前数 x 时）
// 由于 x 可能是负数，交换 max 和 min
int temp_max = max({x, max_ending * x, min_ending * x});
int temp_min = min({x, max_ending * x, min_ending * x});
max_ending = temp_max;
min_ending = temp_min;
ans = max(ans, max_ending); // 这里的 ans 就是滞后记忆

2. 买卖股票的最佳时机（一次交易）—— “最低点重置”版
给定股票价格数组，只能买卖一次，求最大利润。
    2.1 状态变量：min_price（截至当前的最低价）。
    2.2 重置/延续逻辑：如果当前价格 x 比 min_price 还低，就重置买入点（min_price = x），因为更低的成本必然带来更高利润。
    2.3 滞后变量：ans（最大利润）。当价格下跌时，ans 不会改变，滞后地保留着之前峰值的利润。

int min_price = 1e9, ans = 0;
for (int x : prices) {
    if (x < min_price) {
        min_price = x;   // 重置买入点（抛弃前面更高的成本）
    } else {
        ans = max(ans, x - min_price); // 滞后记忆，只保留最大差价
    }
}

3. 加油站（Gas Station）—— “负总量重置”版
判断能否绕环路一圈，并返回起点索引。核心是判断油量 gas - cost。
    3.1 状态变量：current_gas（当前油箱剩余油量）。
    3.2 重置/延续逻辑：如果 current_gas 累加后变成负数，说明从上一个起点出发到当前位置走不通。此时将 current_gas 重置为 0，并把起点设为下一个位置（相当于抛弃前面这一段）。
    3.3 滞后变量：total_gas（全局总油量）。循环结束后，若 total_gas < 0 直接返回 -1；否则返回滞后记录的起点。

int total = 0, current = 0, start = 0;
for (int i = 0; i < n; i++) {
    total += gas[i] - cost[i];
    current += gas[i] - cost[i];
    if (current < 0) {
        current = 0;   // 抛弃前面这段“负资产”（和 Kadane 清零如出一辙）
        start = i + 1; // 滞后记录新的起点
    }
}
return total < 0 ? -1 : start;

4. 最长湍流子数组（Longest Turbulent Subarray）—— “比较符号”版
求最长连续子数组，使得相邻数字的大小关系严格交替（如 > < > 或 < > <）。

状态变量：current_len（当前满足条件的长度），以及前一次的符号 prev_sign。

重置/延续逻辑：如果当前比较符号和上一次相同或出现相等，则无法延续，重置为长度为 2（或 1）。

滞后变量：ans 记录全局最大长度。

cpp
int ans = 1, current_len = 1;
for (int i = 1; i < n; i++) {
    int sign = (arr[i] > arr[i-1]) ? 1 : (arr[i] < arr[i-1]) ? -1 : 0;
    if (sign == 0) {
        current_len = 1; // 相等，直接重置
    } else if (i == 1 || sign == -prev_sign) {
        current_len++;   // 交替成功，延续
    } else {
        current_len = 2; // 符号重复，重置为 2（当前两个数构成新起点）
    }
    prev_sign = sign;
    ans = max(ans, current_len); // 滞后记忆
}
*/
//发现是动态规划，找前缀和

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    int ans=-1e9,sum=0;
    for(int i=0;i<n;i++){
        int w=a[i];                 
        sum+=a[i];                  //当前值
        ans=max(ans,sum);           //ans有一个峰值保存的滞后刷新值
        if(sum<0) sum=0;
    }
    cout<<ans<<endl;
    return 0;
}

/*举一反三*/
/////////////////////P2569 [SCOI2010] 股票交易








/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> a(n);
    for(int &x:a) cin>>x;

    int nmin=a[0];
    int nmax=a[0];
    
    for(int i=0;i<n;i++){
        if(a[i]<nmin){
            nmin=a[i];
        }
        if(nmax<a[i]){
            nmax=a[i];
        }
    }
    
    return 0;
}*/




/************** M - 跳跳！*********************/

/*你决定跳到每个石头上各一次，并最终停在任意一块石头*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> place(n);
    for(int &x:place) cin>>x;

    sort(place.begin(),place.end());

    int l=0,r=n-1;
    long long re=place[n-1]*place[n-1];
    while(l<=r){
        re+=(place[r]-place[l])*(place[r]-place[l]);
        r--;
        int tmp=l;
        l=r;
        r=tmp;
    }
    cout<<re<<endl;
    return 0;
}

/************* 双端队列*************/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    deque<int> place;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        place.push_back(x);
    }

    sort(place.begin(),place.end());

    long long re=place.back()*place.back();
    while(place.size()>=2){
        re+=(place.back()-place.front())*(place.back()-place.front());
        place.pop_back();
        if(!place.empty()){                                                            //这个判断奇数不影响吗
            re+=(place.back()-place.front())*(place.back()-place.front());
            place.pop_front();
        }
    }
    cout<<re<<endl;
    
    return 0;
}


/************** I - 人工智能项目开发 ************/


/////////////////////////////向上取整函数
int ceilDiv(int a, int b) {
 return (a + b - 1) / b;
}
///////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        double n,x,y,z;
        cin>>n>>x>>y>>z;
        if(x>n || y>n){
            cout<<"1"<<endl;
            continue;
        }
        double re1=0,re2=0;
        re1=(n/(x+y));
        re2=((n+10*y*z)/(x+10*y));
        
        int re=min((int)ceil(re1),(int)ceil(re2));
        cout<<re<<endl;
    }
    return 0;
}




/************** J - 伊斯坎德尔与绘画****************/

//线条最长子段

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int lmax=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                int r=1;
                for(int j=i+1;j<n;j++){
                    if(s[j]=='#'){
                        r++;
                    }else{
                        break;
                    }
                }
                if(r>lmax){
                    lmax=r;
                }
            }
        }
        int re=0;
        if(lmax%2!=0){
            re=lmax/2+1;
        }else{
            re=lmax/2;
        }
        cout<<re<<endl;
    }
    return 0;
}

/*题解*/
//最长擦除序列

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> c(n);
        for(char &x:c) cin>>x;

        int re=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(c[i]=='*'){
                sum=0;
            }else{
                sum++;
                re=max(re,(sum+1)/2);
            }
        }
        cout<<re<<endl;
    }


    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;
        vector<int> sum;
        int re=a[0];
        for(int i=1;i<n;i++){
            re+=a[i];
            if(re)
        }
    }

    return 0;
}
*/