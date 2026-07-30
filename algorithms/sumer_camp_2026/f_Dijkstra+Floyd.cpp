//2026-6：Dijkstra+Floyd
#include <stdio.h>
#include <limits.h> // 用于 INT_MAX（代表无穷大）

#define V_NUM 7    // 顶点总数（v0~v6）
#define INF INT_MAX // 用int最大值表示无穷大

/* -------------------------- 子函数声明 -------------------------- */
// 1. 初始化邻接矩阵（根据题目给的图）
void initGraph(int graph[V_NUM][V_NUM]);
// 2. Dijkstra 核心算法（从源点v0出发）
void dijkstra(int graph[V_NUM][V_NUM], int start, int dist[V_NUM], int prev[V_NUM]);
// 3. 打印最终结果（最短路径长度 + 路径）
void printResult(int dist[V_NUM], int prev[V_NUM], int start);
// 4. 辅助：打印从源点到目标点的路径（递归回溯）
void printPath(int prev[V_NUM], int target);

/* -------------------------- 主函数 -------------------------- */
int main() {
    int graph[V_NUM][V_NUM]; // 邻接矩阵
    int dist[V_NUM];         // 存储v0到各点的最短距离
    int prev[V_NUM];         // 存储路径前驱结点，用于回溯路径

    // 1. 初始化图
    initGraph(graph);

    // 2. 执行Dijkstra算法，源点为v0（编号0）
    dijkstra(graph, 0, dist, prev);

    // 3. 打印结果
    printf("===== 从v0出发的最短路径结果 =====\n");
    printResult(dist, prev, 0);

    return 0;
}

/* -------------------------- 子函数实现 -------------------------- */

/**
 * @brief 初始化邻接矩阵，根据题目中的图设置权值
 * @param graph 邻接矩阵数组
 */
void initGraph(int graph[V_NUM][V_NUM]) {
    // 第一步：全部初始化为 INF（无边）
    for (int i = 0; i < V_NUM; i++) {
        for (int j = 0; j < V_NUM; j++) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0; // 自己到自己的距离为0
    }

    // 第二步：按图设置边的权值
    // v0
    graph[0][1] = 13;
    graph[0][2] = 8;
    graph[0][6] = 32;
    // v1
    graph[1][5] = 9;
    graph[1][6] = 7;
    // v2
    graph[2][3] = 5;
    // v3
    graph[3][4] = 6;
    // v4
    graph[4][0] = 30;
    graph[4][5] = 2;
    // v5
    graph[5][6] = 17;
}

/**
 * @brief Dijkstra算法实现，求start到所有点的最短路径
 * @param graph 邻接矩阵
 * @param start 源点编号
 * @param dist 输出：各点到源点的最短距离
 * @param prev 输出：各点的前驱结点，用于回溯路径
 */
void dijkstra(int graph[V_NUM][V_NUM], int start, int dist[V_NUM], int prev[V_NUM]) {
    int visited[V_NUM] = {0}; // 标记结点是否已确定最短路径（S集合）

    // 1. 初始化dist数组：dist[i] = graph[start][i]
    for (int i = 0; i < V_NUM; i++) {
        dist[i] = graph[start][i];
        prev[i] = (dist[i] != INF && dist[i] != 0) ? start : -1; // 前驱结点初始化为start（可达的）
    }
    visited[start] = 1; // 源点直接加入S集合
    dist[start] = 0;    // 源点到自己距离为0

    // 2. 循环V_NUM-1次，每次选一个结点加入S集合
    for (int i = 1; i < V_NUM; i++) {
        // --- 步骤1：从T集合中找距离最小的结点u ---
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < V_NUM; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // 没有可达结点了，提前退出
        visited[u] = 1;     // 加入S集合

        // --- 步骤2：用u作为中间结点，更新T集合中结点的距离 ---
        for (int v = 0; v < V_NUM; v++) {
            // 如果v未被访问，且u到v有边，且经过u的路径更短
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; // 更新距离
                prev[v] = u;                     // 更新前驱结点
            }
        }
    }
}

/**
 * @brief 递归打印从start到target的路径
 * @param prev 前驱结点数组
 * @param target 目标结点
 */
void printPath(int prev[V_NUM], int target) {
    if (prev[target] == -1) {
        printf("v%d", target);
        return;
    }
    printPath(prev, prev[target]);
    printf(" -> v%d", target);
}

/**
 * @brief 打印所有结点的最短距离和路径
 * @param dist 最短距离数组
 * @param prev 前驱结点数组
 * @param start 源点
 */
void printResult(int dist[V_NUM], int prev[V_NUM], int start) {
    for (int i = 0; i < V_NUM; i++) {
        printf("v%d -> v%d: 距离 = ", start, i);
        if (dist[i] == INF) {
            printf("不可达\n");
        } else {
            printf("%-3d 路径: ", dist[i]);
            printPath(prev, i);
            printf("\n");
        }
    }
}

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
        e[a][b]=min(e[a][b],w);  //处理重边！！！！
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



/* test 2 */

/* C - Chocolate Giving S */

/*
* 1.两次最短一定是全局最短，一定会经过农场 1
* 2.调用两次dijskra 堆化版本

* 1.两次最短一定是全局最短，一定会经过农场 1
问题进行转化，将农场1作为起点，dist数组只有一个固定下来！
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int N=5e4+10;
int n,m;
vector<vector<PII>> g(N);
long long dist[N];
bool st[N];

priority_queue<PII,vector<PII>,greater<PII>> pq;

void dijkstra(int s){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[s]=0;
    pq.push({0,s});

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

    int num;
    cin>>n>>m>>num;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b, w});   //依次添加在队尾，相同也不会覆盖掉，图的所有边
        g[b].push_back({a, w});
    }
    dijkstra(1);          //！！！（问题转化）图是固定下来的，选择农场为起点，在无向图里面直接加就好了，也就是说dist数组只有一个
    while(num--){
        int x,y;
        cin>>x>>y;
        cout<<dist[x]+dist[y]<<endl;
    }

    return 0;
}


/* E - 【模板】单源最短路2 */
/* 数据在 N=5010 可以使用朴素版
无重边或自环,无负数
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,int> PII;

const int N=50010;
int n,m;
vector<vector<PII>> g(N);
long long dist[N];
bool st[N];

priority_queue<PII,vector<PII>,greater<PII>> pq;

void dijkstra(int s){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[s]=0;
    pq.push({0,s});

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
        g[a].push_back({b, w});   //依次添加在队尾，相同也不会覆盖掉，图的所有边
        g[b].push_back({a, w});
    }
    dijkstra(1);       
    //dist 是 long long 数组
    if(dist[n]==0x3f3f3f3f3f3f3f3f){
        cout<<-1<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}



/* G - 租用游艇 */

//Floyd Warshal算法模板
/*
#include <bits/stdc++.h>
using namespace std;

//从游艇出租站 1 到 n 所需的最少租金。

const int N=210;
int g[N][N];
int n;

int main(){
    memset(g,0x3f,sizeof g);
    cin>>n;
    for(int i=1;i<n;){
        for(int j=i+1;j<=n;j++){
            cin>>g[i][j];
        }
        i++;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);  //注意这里的向量很容易写错
            }
        }
    }

    cout<<g[1][n]<<endl;

    return 0;
}
*/

/* H - 邮递员送信 */

//因此所有的道路都是单行的

//这个邮递员每次只能带一样东西，
//并且运送每件物品过后必须返回邮局。
//分析得出是以邮局为定点的 Dijkstra算法 用堆和矩阵都可以 用堆吧，复习一下

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e3+10;
int n,m;
vector<vector<PII>> g(N);
int dist[N];
bool st[N];
priority_queue<PII,vector<PII>,greater<PII>> pq;

void dijkstra(int s){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto[mn,id]=pq.top();
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
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
    dijkstra(1);
    long long re=0;
    for(int i=2;i<=n;i++){
        //不能简单相乘，同一条路不能有来有回
        re+=dist[i];  //出去的路程
    }
    for(int i=2;i<=n;i++){            //这里其实是改变了初始点，每次回去为源点到 邮局 的最短距离
        dijkstra(i);                  //其实真的很害怕调用这么多次，不过效果看上去还是可以的，过了
        re+=dist[1];
    }
    cout<<re<<endl;
    return 0;
}
//不过呢，在这里时间超限了。。。

/*
回程：从每个节点 i 回到邮局 1 的最短路径，
等价于在反向图（所有边反向）上

从 1 到每个节点 i 的最短路径。
因此只需再对反向图运行一次 Dijkstra，得到 dist2[i]。
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e3+10;
int n,m;
vector<vector<PII>> gra(N);   //正边图
vector<vector<PII>> rg(N);   //反边图
int dist[N];
bool st[N];


void dijkstra(int s,vector<vector<PII>> & g){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>> pq; //局部优先队列
    pq.push({0,s});
    while(!pq.empty()){
        auto[mn,id]=pq.top();
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
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        gra[a].push_back({b,w});
        rg[b].push_back({a,w});
    }
    dijkstra(1,gra);
    long long re=0;
    for(int i=2;i<=n;i++){
        //不能简单相乘，同一条路不能有来有回
        re+=dist[i];  //出去的路程
    }
    dijkstra(1,rg);
    for(int i=2;i<=n;i++){
        re+=dist[i]; 
    }
    
    cout<<re<<endl;
    return 0;
}

/* D - Cow Hurdles S */

/*
显然，对于一头奶牛跳过几个矮栏是很容易的，但是高栏却很难。
于是，奶牛们总是关心路径上最高的栏的高度。

1.奶牛的训练场中有 N 个站台
2.所有站台之间有 M 条单向路径

3.你的任务就是写一个程序，
计算出路径上最高的栏的高度的最小值。

第 i 行包含两个空格隔开的整数，表示任务 i 的起始站台和目标站台
边权就变成了这一条路上 最大边的值 

想法，再开一个high的数组，记录每次加到边里面最高的栏高度
*/

/*
#include <bits/stdc++.h>
using namespace std;

const int N=310;
const int INF=0x3f3f3f3f;
int g[N][N];
int high[N];
bool st[N];
int n,m;

void Dijkstra(int s){
    fill(high, high + N, INF);
    fill(st, st + N, false);
    high[s] = 0;

    for(int i=1;i<=n-1;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t==-1 || high[j] < high[t])){
                t=j;
            }
        }

        for(int j=1;j<=n;j++){
            if(!st[j] && g[t][j] < INF){
                int x = max(high[t], g[t][j]);
                high[j] = min(high[j], x);
            }
        }
    }
}

int main(){
    int t;
    cin>>n>>m>>t;

    while(m--){
        int a,b,h;
        cin>>a>>b>>h;
        g[a][b]=h;
    }
    /*
    *你的代码使用了每次查询单独运行一次改进版 Dijkstra 的做法，
    *在数据范围（N=300, M=25000, T=40000）下会严重超时。
    *同时代码还存在一些细节问题，导致输出可能不正确。
    *下面指出问题并给出正确的解法。

    *如果无法到达，输出 -1。无法完成
    
    while(t--){
        int x,y;
        cin>>x>>y;
        Dijkstra(x);
        cout<<high[y]<<endl;
    }
    
    return 0;
}

*/

//尝试用 Floyd解决 正确
/*
#include <bits/stdc++.h>
using namespace std;

const int N=310;
int g[N][N];
const int INF=0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,t;
    cin>>n>>m>>t;
    memset(g,0x3f,sizeof g);
    //对角线初始化为0 防止起点终点为一致时候输出INF
    for(int i=1;i<=n;i++) g[i][i]=0;

    while(m--){
        int a,b,h;
        cin>>a>>b>>h;
        g[a][b]=min(g[a][b],h);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(g[i][k]==INF) continue;               //中转点特别高那就跳过
            for(int j=1;j<=n;j++){
                if(g[k][j]<INF){
                    int x = max(g[i][k], g[k][j]);  //下一个可能方案里面的最大值
                    g[i][j] = min(g[i][j], x);      //两个方案的最大值比较选择最小的那个
                }
            }
        }
    }
    while(t--){
        int x,y;
        cin>>x>>y;
        if(g[x][y]==INF) cout<<-1<<endl;
        else cout<<g[x][y]<<endl;
    }
    return 0;
}
*/



//dijstra算法基于贪心思想，当有负权边时，局部最优不一定是全局最优

//Bellman 算法
/*
#include<iostream>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

struct Edge { //使用结构体存储边，不用定义一大堆数组去加边
    int a;
    int b;
    int w;
} e[M];//把每个边保存下来即可
int dist[N];
int back[N];//备份数组防止串联
int n, m, k;//k代表最短路径最多包涵k条边

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist); //dist初始化位无穷，八字节3f3f3f3f大于1e9
    dist[1] = 0;
    for (int i = 0; i < k; i++) {//k次循环
        memcpy(back, dist, sizeof dist);//
        for (int j = 0; j < m; j++) {//遍历所有边，而dijkstra是遍历所有顶点n*n
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], back[a] + w);
            //使用backup:避免给a更新后立马更新b, 这样b一次性最短路径就多了两条边出来
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    bellman_ford();
    if(dist[n]>0x3f3f3f3f/2) puts("impossible");
    else printf("%d",dist[n]);
    return 0;
}

*/


/* F - Job Hunt S */

/*
第 2 到第 P+1 行：第 i+1 行包含 2 个用空格分开的整数，
表示一条从城市 Ai​  到城市 Bi 的单向路径。
如果赚的钱也不会出现限制，就输出 −1

就是路径最大值
*/





/* I - 赚钱 */
//P 条单向路径连接 zzy 可以从任何一个城市出发开始赚钱，
//分析

/*
1.图上面有环 且环的价值大于0，那么输出orz 
2.如果没有输出dist数组最大值
*/

/*
请求帮忙学习

是的，这道题应该用 最长路 + 正环判定，
也就是 Bellman-Ford / SPFA 的思路。
*/


/*
Bellman_Ford算法
1.初始化距离
2.执行v-1轮松弛操作 遍历所有的边
3.检测负权环 额外遍历一次检测
*/