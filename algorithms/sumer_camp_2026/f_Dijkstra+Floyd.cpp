//2026-6：Dijkstra+Floyd

/* 模板 */

/* 简单版本 */
//数据不可过大
/*
#include <bits/stdc++.h>
using namespace std;

const int N=510;   //不可过于大了
int n,m,s;

long long g[N][N];  //边
long long dis[N];
bool st[N];

long long Dijkstra(int strat){
    memset(dis,0x3f,sizeof dis);
    dis[strat]=0;
    for(int i=1;i<=n-1;i++){
        int t=-1;
        for(int j=1;j<=n-1;j++){
            if(!st[j] &&(t==-1 || dis[t]>dis[j])){   //运算符优先级问题
                t=j;                             //找到总和最短点进行下一步开始松弛
            }
        }

        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],dis[t]+g[t][j]);   //其余点到这一点的距离最小值
        }
        st[t]=1;
    }
    //if(dis[n]==0x3f3f3f3f) return -1;             //?long long之下还是太小了
    // 在 Dijkstra 函数最后
    if (dis[n]>0x3f3f3f3f3f3f3f3f/2) // 通常用 INF/2 判断不可达
    return -1;

    return dis[n];                                //返回的是起点 s 到顶点 n（即最后一个节点）的最短路径长度
}

int main(){
    cin>>n>>m>>s;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b;
        long long w;
        cin>>a>>b>>w;
        g[a][b]=min(g[a][b],w);
    }
    cout<<Dijkstra(s);
    return 0;
}
*/


//堆优化版本
/*
这份代码在给定的数据范围
（n ≤ 1e5，m ≤ 2e5，边权和 ≤ 1e9）下可以正常工作，
没有明显的溢出或超时风险。
*/
//题目保证 ∑w_i ≤ 1e9，但不影响代码，只是让距离更小

#include <bits/stdc++.h>
using namespace std;


typedef pair<long long,int> PII;     //边长，node

const int N=100000+5;
//const long long INF=LLONG_MAX/2;
int n,m,s;
vector<vector<PII>> g(N);

long long dist[N];
bool st[N];

priority_queue<PII,vector<PII>,greater<PII>> pq;  //优先队列

void dijkstra(int fi){
    memset(dist,0x3f,sizeof dist);
    /*
    memset 按字节填充，INF 是 LLONG_MAX/2（一个很大的数），
    但 memset 只会把每个字节都设为 INF 的低字节，
    并不会把每个 long long 元素赋值为 INF。0x3f3f3f3f是int的无穷大，对于long long，用0x3f会得到0x3f3f3f3f3f3f3f3f
    */
    /*
    但实际填充 0x3f 后每个 long long 变为 0x3f3f3f3f3f3f3f3f，
    这是一个合法的极大值。不过为了让代码更清晰，
    建议改用 fill(dist, dist + N, INF)（需提前定义 const long long INF = 4e18;）。
    */
    //fill(dist,dist+N,INF);
    dist[fi]=0;
    pq.push({0,fi});
    while(!pq.empty()){
        auto[mn,id]=pq.top();
        pq.pop();
        if(st[id]) continue;
        st[id]=1;

        for(auto [to,w] : g[id]){        //设置队列元素
            if(dist[to] > dist[id] + w){
                dist[to] = dist[id] + w;
                pq.push({dist[to], to});  //更新新值 dist(to),to
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>m>>s;

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}


/* 练习 */

/* B - Heat Wave G */

/* 分析 这一题呢是无向边集合 那么就是两两相通

其实全是边的话会有 3123750 条，现在最多6200条，用堆的话可能也行，但是不能保证是不是稀疏图

数据不大先试试邻接矩阵吧
边长总和最多是 2500000<10^9 用int吧
*/

#include <bits/stdc++.h>
using namespace std;

const int N=2510;
int n,m,s,endd;
int e[N][N];
int dist[N];
bool st[N];

int Dijkstra(int start){
    //初始化
    memset(dist,0x3f,sizeof dist);
    dist[start]=0;
    //找中转点n-1次
    for(int i=1;i<=n-1;i++){
        int t=-1;
        //注意里面的节点编号全部都需要是遍历到n才行
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1 || dist[t]>dist[j])){         //这个点t呢，必须要初始化
                t=j;
            }
        }
        for(int j=1;j<=n;j++){         
            dist[j]=min(dist[j],dist[t]+e[t][j]);
        }
        st[t]=1;
    }
    return dist[endd];
}

int main(){
    cin>>n>>m>>s>>endd;
    //注意有两次无穷初始化，一次是dist距离一次是图里面边值
    memset(e,0x3f,sizeof e);
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        e[a][b]=w;
        e[b][a]=w;
    }
    int re=Dijkstra(s);
    cout<<re<<endl;
    return 0;
}
//一会再用一下堆好了




/* C - Transfusion */
//保证所有测试用例的 n 之和不超过 2*10^5 。

/*
我现在没思路，嗯把它们想象成边，隔一个边（不是起始边或末尾边）才能均衡，
嗯，这样的话，有什么办法呢

嗯问题不要复杂化，分为两组奇数和偶数，求出它们的平均值/两组和能否相等
1.总和能否整除n个数
2.奇数和是否是总和一半

所以说实现 奇数下标和数组平均值 等于 偶数下标和数组平均值 就可以，并没有用今天的知识啊
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;
        long long sum1=0,sum2=0,re=0;
        for(int i=0;i<n;i++){
            sum1+=a[i];
            if(i%2==0){
                sum2+=a[i];
                re++;
            }
        }
        if(sum1%n==0 && sum1/n==sum2/re && sum2%re==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}




/* D - Crafting */
/*
1.某个缺一项 需要其他所有元素都多一项获得
2.转化为 记录a[i]-b[i]=c[i]
3.c[0]=-a 那么接下来全部减去a让c[i]变为0 （此时遍历c[i]<0的就可以了）
4.如果 0-（i-1）其中一项减a小于0 那么直接NO
5.遍历完全部i结束。成功则YES

（3~5）
6.负数之和*n-1 与 正数之和比较大小就可以了 不对
因为对于操作“一种材料 +1，其他材料 -1”，
判断条件并不是简单的“缺额总量乘以 (n-1) ≤ 盈余总量”。
这个条件只考虑了总和，忽略了每个材料个体必须满足的不等式，
导致错误判定（比如样例 2 会误判为 YES）。

//
如果初始资源不足的材料（ai​<bi​ ）超过 1 个，则直接无解；
那么整体上来看就是 一开始两个及两个以上负数直接无解
负数为0就是一定有解
一个负数则记录，看看最小正值能不能大于它
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;

        vector<int> b(n);
        for(int &x:b) cin>>x;

        long long sum1=0;

        long long min_surplus=LLONG_MAX;        //记录所有非负差值中的最小值
        int cnt=0;
        for(int i=0;i<n;i++){
            long long w=a[i]-b[i];
            if(w<0){
                sum1-=w;
                cnt++;
            }else{
                min_surplus=min(min_surplus,w);
            }
        }
        if(cnt==0){
            cout<<"YES"<<endl;
        }else if(cnt>=2){
            cout<<"NO"<<endl;
        }else{
            if(min_surplus>=sum1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

///错了

//1.增加一种、减少其他的操作是不正确的。
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;

        vector<int> b(n);
        for(int &y:b) cin>>y;

        long long sum1=0;

        long long min_surplus=LLONG_MAX;        //记录所有非负差值中的最小值
        int cnt=0;
        for(int i=0;i<n;i++){
            long long w=a[i]-b[i];
            if(w<0){
                sum1-=w;
                cnt++;
            }else{
                min_surplus=min(min_surplus,w);
            }
        }
        if(cnt==0){
            cout<<"YES"<<endl;
        }else if(cnt>=2){
            cout<<"NO"<<endl;
        }else{
            if(min_surplus>=sum1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}



/* E - Digital string maximization */

/*
由从 0 到 9 的数字组成。
在一次操作中，您可以选择这个字符串中的任何数字，
除了 0 或最左边的数字，将其减少 1，然后与左侧的数字交换。
交换 swap
获得的字典序最大字符串。
*/

#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<i+9;j++){
                if(s[j]=='0') continue;
                if((int)s[i]<(int)s[j]-j){
                    char m=s[i];
                    s[i]=s[j]-j;
                    s[j]=m;
                }
            }
        }

        cout<<s<<endl;
    }

    return 0;
}

/* 题解 */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        /*
        for(int i=0;i<(int)s.size();i++){
            for(int j=i+1;j<i+9 && j<(int)s.size();j++){
                if(s[j]=='0') continue;
                
                //没有考虑中间字符的变化，
                //因为这种操作涉及连续交换，不是一次性跳跃。
                if((int)s[i]<(int)(s[j])-j){
                    char m=s[i];
                    s[i]=s[j]-j;
                    s[j]=m;
                }
                //只考虑相邻交换!!!
            }
        }*/
        for(int i=1;i<s.size();){
            /*
            这个循环判断控制非常巧妙是的，
            如果最后一位 i = n-1 处发生交换，
            那么 i 会回退到 n-2，然后检查 (n-3, n-2)，
            如果还能交换就继续回退，直到不能交换或回到 i=1 检查 (0,1)。
            这个过程可能会一路回退到最前面，但每个数字最多只能向左移动 9 次（因为每次移动减 1，
            减到 0 就无法再移动），所以回退的次数是有限的，不会无限循环。
            */
            if(s[i]>'0' && s[i-1]<s[i]-1){
                char m=s[i]-1;
                s[i]=s[i-1];
                s[i-1]=m;
                /*
                整个过程就像“冒泡”一样，把较大的数字（经过减 1 后）不断向左移动，
                直到不能再移动为止。
                */
                if(i>1) --i;        // 回退一步，检查之前是否还能改善
            }else{
                ++i;                // 当前位不能改善，继续向后
                /*
                因为我们要贪心地反复检查相邻位置，
                每做一次交换，左边那个位置的值变了，
                它可能又和左边的数形成“可改善对”，
                所以我们不能简单地直接向后移动，
                而是需要回退一步，
                看看刚才的位置（i-1）是否还能被更左边的数改善。
                */
            }
        }
        std::cout<<s<<std::endl;
    }

    return 0;
}








/* Acwing 模板*/
#include <bits/stdc++.h>
using namespace std;

const int N=510;
int e[N][N];
int dist[N];
bool st[N];
int n,m,s;

int Dijkstra(int start){
    memset(dist,0x3f,sizeof dist);
    //memset(st,0,sizeof st);   // 重置标记
    dist[start]=0;
    
    for(int i=1;i<=n-1;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1 || dist[j]<dist[t])){
                t=j;
            }
        }
        
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+e[t][j]);
        }
        st[t]=1;
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin>>n>>m;
    memset(e,0x3f,sizeof e);
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        e[a][b]=min(e[a][b],w);
    }
    cout<<Dijkstra(1);
    return 0;
} 

/* 堆优化版本模板 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int N=2e5+10;
int n,m;
int dist[N];
bool st[N];

vector<vector<PII>> g(N);
priority_queue<PII,vector<PII>,greater<PII>> pq;

void dijkstra(int fi){
    memset(dist,0x3f,sizeof dist);
    dist[fi]=0;
    pq.push({0,fi});
    
    while(!pq.empty()){
        auto [mn,id]=pq.top();
        pq.pop();
        if(st[id]) continue;
        st[id]=1;
        
        for(auto [to,w]:g[id]){
            if(dist[to]>dist[id]+w){
                dist[to]=dist[id]+w;
                pq.push({dist[to],to});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    dijkstra(1);
    if(dist[n]==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<dist[n]<<endl;
    return 0;
}