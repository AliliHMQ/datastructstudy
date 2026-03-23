//1.人品 向上取整
//n 道难度为 m
//模板
/*#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    //输入
    long long n,m,re1,re2;
    double re;
    scanf("%lld %lld",&n,&m);
    re=0.8*m; //整数和小数部分
    long long a=(int)re;//re的整数部分
    //处理小数部分
    if(re-a==0){
        re1=a;
    }else{
        re1=a+1;
    }
    re2=re1*n;
    printf("%lld\n",re2);
    return 0;
}

                                                       //第一题题解
/*#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 998244353;
void solve() {
    i64 n, m; cin >> n >> m;
    i64 ans = (m + 1) * 4 / 5 * n;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
//     std::cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}*/

//2.林尼变牌
/*#include <iostream>
using namespace std;

int main(){
    //n组数据
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        //建牌堆
        int a[x];
        int b[x];
        //两个牌堆的差值
        int dis[x];
        for(int j=0;j<x;j++){
            scanf("%d",&a[j]);
        }
        for(int j=0;j<x;j++){
            scanf("%d",&b[j]);
        }
        for(int j=0;j<x;j++){
            dis[j]=b[j]-a[j];
        }
        //判断 后面减去前面一定会抵消
        //这个数学相消法我也不知怎么来的miao
        int re=dis[0];
        for(int j=1;j<x;j++){
            re=dis[j]-re;
        }
        if(re==0){
            printf("%d Yes\n",re);
        }else{
            printf("%d No\n",re);
        }
    }
    return 0;
}*/

//3.小猴子喜欢大猴子，桶排序
/*#include <iostream>
using namespace std;

/*void quick_sort(int q[],int l,int r,int k){
    if(l>=r) return;
    int i=l-1,j=r+1,x=q[(l+r) >> 1];
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    if(k <= j) return quick_sort(q,l, j, k);  
    else return quick_sort(q,j+ 1, r, k);

}*/

//找到 第一大和第二大的数 怎么做

/*int main(){
    //n只小猴子，m只大猴子
    int n,m;
    scanf("%d %d",&n,&m);
    //桶初始化
    int q[m+1]={0};  //修改数组大小，避免越界    //当 m 和 n 达到 10^5 时，栈空间不足就会导致段错误。而这一题就是这样
    int a[n],b[n];//保存喜好
    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i], &b[i]);
        q[a[i]]++;
        q[b[i]]++;
    }
    int max=0;    //票数最多的大猴子
    int max_2=0;  //第二多的
    int re1,re2,sum;   //出现了 重复喜欢 的问题
    for(int i=0;i<m;i++){
        if(q[i]>max){
            max=q[i];
            re1=i;
        }
    }
    sum=q[re1];
    q[re1]=0;
    for(int i=0;i<m;i++){
        if(q[i]>max_2){
            max_2=q[i];
            re2=i;
        }
    }
    int dup=0;   // 重复计数
    for(int i=0;i<n;i++) {
    if((a[i]==re1 && b[i]==re2) || (a[i]==re2 && b[i]==re1) )
        dup++;
    }
    sum=sum+q[re2]-dup;
    //printf("%d %d",re1,re2);
    printf("%d",sum);
    return 0;
}*/

//动态数组解决，但是存在逻辑问题
/*#include <iostream>
#include <vector>   // 添加 vector 头文件
using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    // 使用 vector 代替静态数组，下标从 1 开始，所以大小 m+1
    vector<int> q(m+1, 0);
    
    // 保存每只小猴子的喜好，用于后续统计重复
    vector<int> a(n), b(n);
    
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
        q[a[i]]++;
        q[b[i]]++;
    }
    
    int max=0;    // 票数最多的大猴子
    int max_2=0;  // 第二多的
    int re1,re2,sum;
    
    // 找第一只大王（票数最多）
    for(int i=1;i<=m;i++){   // 注意从1开始
        if(q[i]>max){
            max=q[i];
            re1=i;
        }
    }
    sum=q[re1];
    
    // 临时清除第一只大王的票数，再找第二只大王
    q[re1]=0;
    for(int i=1;i<=m;i++){
        if(q[i]>max_2){
            max_2=q[i];
            re2=i;
        }
    }
    sum+=q[re2];
    
    // 统计同时喜欢 re1 和 re2 的小猴子数
    int dup=0;   // 重复计数
    for(int i=0;i<n;i++) {
    if((a[i]==re1 && b[i]==re2) || (a[i]==re2 && b[i]==re1) )
        dup++;
    }
    printf("%d\n", sum - dup);
    
    return 0;
}*/

//可悲，超时 (Q _ Q?)
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<int> k(m + 1, 0);          // 票数
    vector<int> a(n), b(n);           // 小猴子的喜好
    
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        k[a[i]]++;
        k[b[i]]++;
    }
    
    // 找出最大值和次大值
    int max_k = 0, second_max_k = 0;
    for (int i = 1; i <= m; ++i) {
        if (k[i] > max_k) {
            second_max_k = max_k;
            max_k = k[i];
        } else if (k[i] > second_max_k && k[i] != max_k) {
            second_max_k = k[i];
        }
    }
    
    // 收集最大集合和次大集合
    vector<int> max_set, second_set;
    for (int i = 1; i <= m; ++i) {
        if (k[i] == max_k) max_set.push_back(i);
        else if (k[i] == second_max_k) second_set.push_back(i);
    }
    
    int ans = 0;
    
    // 情况1：最大集合只有一只猴子
    if (max_set.size() == 1) {
        int X = max_set[0];
        // 对于次大集合中的每个候选 y，计算满意数
        int best = 0;
        for (int y : second_set) {
            // 统计同时喜欢 X 和 y 的小猴子数
            int dup = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i] == X && b[i] == y) || (a[i] == y && b[i] == X))
                    dup++;
            }
            int cur = k[X] + k[y] - dup;
            if (cur > best) best = cur;
        }
        ans = best;
    } 
    // 情况2：最大集合有多只猴子
    else {
        // 如果最大集合足够大，一定能找到一对没有共同喜欢的小猴子
        long long pair_cnt = (long long)max_set.size() * (max_set.size() - 1) / 2;
        if (pair_cnt > n) {
            ans = 2 * max_k;
        } else {
            // 枚举所有不同的对，找出共同喜欢数最少的
            int min_dup = n + 1;
            for (size_t i = 0; i < max_set.size(); ++i) {
                for (size_t j = i + 1; j < max_set.size(); ++j) {
                    int x = max_set[i], y = max_set[j];
                    int dup = 0;
                    for (int t = 0; t < n; ++t) {
                        if ((a[t] == x && b[t] == y) || (a[t] == y && b[t] == x))
                            dup++;
                    }
                    if (dup < min_dup) min_dup = dup;
                }
            }
            ans = 2 * max_k - min_dup;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}*/

//Ai题解
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<int> k(m + 1, 0);
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        k[a[i]]++;
        k[b[i]]++;
    }
    
    // 找最大值和次大值
    int max_k = 0, second_max_k = 0;
    for (int i = 1; i <= m; ++i) {
        if (k[i] > max_k) {
            second_max_k = max_k;
            max_k = k[i];
        } else if (k[i] > second_max_k && k[i] != max_k) {
            second_max_k = k[i];
        }
    }
    
    // 收集最大集合和次大集合
    vector<int> max_set, second_set;
    for (int i = 1; i <= m; ++i) {
        if (k[i] == max_k) max_set.push_back(i);
        else if (k[i] == second_max_k) second_set.push_back(i);
    }
    
    int ans = 0;
    
    if (max_set.size() == 1) {
        // 唯一最大：第一只固定，第二只从次大集合中选
        int X = max_set[0];
        unordered_map<int, int> dup;  // 记录每个 y 与 X 的共同喜欢数
        for (int i = 0; i < n; ++i) {
            if (a[i] == X) {
                int y = b[i];
                if (k[y] == second_max_k) dup[y]++;
            } else if (b[i] == X) {
                int y = a[i];
                if (k[y] == second_max_k) dup[y]++;
            }
        }
        for (int y : second_set) {
            int cur = k[X] + k[y] - dup[y];
            if (cur > ans) ans = cur;
        }
    } 
    else {
        // 多个最大：两只都从最大集合中选
        long long pair_cnt = (long long)max_set.size() * (max_set.size() - 1) / 2;
        if (pair_cnt > n) {
            ans = 2 * max_k;  // 一定存在一对没有共同喜欢的小猴子
        } else {
            // 枚举所有不同的对，找共同喜欢数最小的
            unordered_map<long long, int> dup;
            auto key = [&](int x, int y) {
                if (x > y) swap(x, y);
                return (long long)x * (m + 1) + y;
            };
            for (int i = 0; i < n; ++i) {
                int x = a[i], y = b[i];
                if (k[x] == max_k && k[y] == max_k) {
                    dup[key(x, y)]++;
                }
            }
            int min_dup = n + 1;
            for (size_t i = 0; i < max_set.size(); ++i) {
                for (size_t j = i + 1; j < max_set.size(); ++j) {
                    int x = max_set[i], y = max_set[j];
                    int c = dup[key(x, y)];
                    if (c < min_dup) min_dup = c;
                }
            }
            ans = 2 * max_k - min_dup;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
//用 int q[m]，这是变长数组，在 C++ 标准中不推荐，并且当 m=10⁵ 时容易栈溢出。