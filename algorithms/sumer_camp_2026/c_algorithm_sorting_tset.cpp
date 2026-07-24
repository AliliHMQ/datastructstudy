/*算法分析与排序*/

/*
排序示例
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5;

struct Node{
    int n;
    bool operator<(const Node &other) const{         //operator。这是 C++ 关键字，必须完全正确拼写
        return n<other.n;
    }
};

bool cmp(const Node &a,const Node &b){
    return a.n>b.n;                         //降序       
}

int main(){
    Node arr[N]={{1},{4},{3},{7},{5}};

    //方法一 用默认的operator
    sort(arr,arr+N);
    cout<<"升序 ";
    for(int i=0;i<N;i++) cout<<arr[i].n<<" ";
    cout<<endl;

    //方法二 用比较函数cmp
    //sort(arr,arr+N,cmp);
    cout<<"降序 ";
    for(int i=0;i<N;i++) cout<<arr[i].n<<" ";
    cout<<endl;
    return 0;
}


//计数排，桶排序
/*计数排序
适用情况
当我们要排序的数方差不大，而又特别多的情况下，此时使用时
间复杂度为 nlog(n)) 的排序会超时，我们可以考虑使用计数排
序。计数排序由于不是比较排序，故其时间复杂度能够突破比较
排序的下限 O(nlog(n)) 达到 O(n)。*/


/** A - SORT AGAIN HDU - 2523 **/

/*现在请你计算第K大的组合数是哪个
一个组合数为第K大是指有K-1个不同的组合数小于它
不重复的话，输入无法重复的两两之差，set insert() 排序且不重复实现

1.对输入数组排序 然后求差值放入set  双循环的话，怕太慢了            //但是意外成功了，本质上还是在暴力喵
然后判断有没有k个数，没有继续加入set里面的前缀和，输出

n*(n-1)/2
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n,k;
        cin>>n>>k;

        vector<int> a;
        set<int> w;
        for(int &x:a) cin>>x;
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                w.insert(abs(a[j]-a[i]));
            }
        }
        for(int i=0;i<k-1 && !w.empty();i++){
            w.erase(w.begin());
        }
        cout<<*w.begin()<<endl;

    }
    return 0;
}


/* B - sort HDU - 1425 */

/*
对每组测试数据按从大到小的顺序输出前m大的数。
*/
//请用 VC/VC++ 提交

//STL捷径了 换成桶排序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x,y;
    while(cin>>x>>y){
        vector<int> a(x);
        for(int &n:a) cin>>n;

        sort(a.begin(),a.end());
        for(int i=0;i<y-1;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}

/*
所以，用计数标记并不是“走捷径”，
而是基于题目特性设计的最优算法，
也正是出题人希望看到的基础能力——根据约束设计数据结构，
而不是直接套用通用库函数。
*/
//我们只需要“前 m 大”，而不是全部排序

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        vector<bool> a(1000001,false);  //节省空间，记录数据
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x+500000]=true;          //加上偏移量
        }
        int cont=0;
        for(int i=1000000;i>=0;i--){
            if(a[i]==true){
                cout<<i-500000<<" ";
                cont++;
            }
            if(cont==m){
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}


////其他的都在超时
//研究一下这个，再过一遍                                                          *******************************

#include <cstdio>       // 用 scanf / printf 更快
#include <algorithm>    // 为了 max
using namespace std;

const int OFFSET = 500000;
const int MAX_IDX = 1000000;
int vis[MAX_IDX + 1];   // 全局数组，初始全0
int tag = 0;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        ++tag;                 // 新的时间戳
        int maxVal = -500000;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            int idx = x + OFFSET;
            vis[idx] = tag;    // 打上当前组的标记
            if (x > maxVal) maxVal = x;
        }

        int cnt = 0;
        // 从最大值往下扫描
        for (int i = maxVal + OFFSET; i >= 0 && cnt < m; --i) {
            if (vis[i] == tag) {
                if (cnt) putchar(' ');
                printf("%d", i - OFFSET);
                ++cnt;
            }
        }
        putchar('\n');
    }
    return 0;
}


/*C - 前m大的数 HDU - 1280 */

/*
给定一个包含N(N<=3000)个正整数的序列，
每个数不超过5000，
对它们两两相加得到的N*(N-1)/2个和，
求出其中前M大的数(M<=1000)并按从大到小的顺序排列。
*/

#include <iostream>
using namespace std;

const int N=1e5+10;
int a[N],b[N];

void quick_sort(int q[],int l,int r,int k){
    if(l>=r) return;
    int i=l-1;
    int j=r+1;
    int x=q[(l+r)/2];
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    if(k>j){
        quick_sort(q,j+1,r,k);
    }else{
        quick_sort(q,l,j,k);
    }
}

int main(){
    

    int n,k;
    while(cin >> n >> k){

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int re=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;i<n;i++){
            b[re]=a[i]+a[j];
            re++;
        }
    }
    int sum=(n*(n-1))/2;
    quick_sort(b,0,sum-1,k-1);
    for(int i=0;i<k;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
return 0;
}


/*
如果我把 450 万个和全部存进数组，
然后调用快排(O(PlogP)，P=450万)，
计算量约为 4.5×10^6×22≈1×10^8。
这在 C++ 里勉强压线

正确判断是：我完全不需要排序全部，
只需要维护一个大小为 1000 的小根堆（或最小堆）。
每次生成一个和，跟堆顶比，比堆顶大就踢掉堆顶并插入。

看数值范围（隐藏的大杀器）
数据：每个数 ≤ 5000。
隐藏信息：两两相加，最大的和不会超过 10000。
空间/时间判断（桶排序/计数排序）：
既然和的最大值只有 10000，
我根本不需要管 N 是多少，直接开一个长度为 10001 的数组（桶）。


综上所述，运用桶排序是最佳选择
*/

#include <bits/stdc++.h>
using namespace std;

const int N=10010;

int main(){
    int a[N];
    int n,m;
    while(cin>>n>>m){
        int max0=0;
        int b[N]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                b[a[i]+a[j]]++;
                if(a[i]+a[j]>max0){
                    max0=a[i]+a[j];
                }
            }
        }
        int re=m;
        for(int i=max0;i>=0;i--){
            if(re==0) break;
            if(b[i]>0){
                int cnt=min(b[i],re);
                for(int j=0;j<cnt;j++){        // 关键点：到底打印几个？取 b[i] 和 re 中较小的那个
                    cout<<i<<" ";
                }
                re-=cnt;
            }
        }
        cout<<endl;
    }
    return 0;
}



/*D - 水果 HDU - 1263 */

/*水果先按产地分类,
产地按字母顺序排列;

同一产地的水果按照名称排序,
名称按字母顺序排序.*/

/*
map 的成员访问方式：

mp[place] 返回内层 map<string,int>，
你需要用 [name] 来操作水果计数，而不是 .name（不存在）。

输出时，map 没有 key() 方法，需要迭代器获取键值。
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<string,map<string,int>> mp;

        for(int i=0;i<n;i++){
            string name,place;
            int n1;
            cin>>name>>place>>n1;
            mp[place][name]+=n1;
        }
        //正确做法：使用迭代器或范围 for 循环
        for(auto &other:mp){
            cout<<other.first<<endl;
            for(auto &inner : other.second){
                cout<<"   |----"<<inner.first<<"("<<inner.second<<")"<<endl;
            }
        }
    }
    return 0;
}




/*E - 求解顺序 HDU - 5702 */

/*
每种情况都需要输出一条线。应该有字符串代表你选择的求解顺序。
又想用map，毕竟有序 但是倒序输出有点麻烦

但是呢，实际上
对于任何两种气球，它们的数量是不同的。
那么实际上 数量上是固定的不同的
毕竟选择桶排序更加合适
*/

#include <iostream>
#include <string>
using namespace std;

const int N=110;       //桶数目

int main(){
    int t;
    cin>>t;
    while(t--){
        string b[N];   //字符串数组
        bool c[N]={0};
        int n;
        cin>>n;
        int m=n;
        int num_max=-1;
        while(n--){
            string s1;
            int num;
            cin>>s1>>num;
            b[num]=s1;
            c[num]=1;
            if(num>num_max){
                num_max=num;
            }
        }
        int re=m;
        for(int i=num_max;i>=0;i--){
            if(re==0) break;
            if(c[i]){
                cout<<b[i]<<" ";
                re--;
            }
        }
        cout<<endl;
    }
    return 0;
}



/*F - PM2.5 HDU - 5182 */

/*
我们通过PM2.5内容量的两次测量差来排序这些城市
（第一次测量C，第二次测量），
按递叠顺序排列，
如果有平局，按第二次测量按发送顺序排列;
如果也是平局，则按输入顺序排列。           也就是说不用按照第一次排序
*/
/*
2
100 1   -99    城市0
1 2      1   城市1

3
100 50  -50
3 4     1
1 2     1  2<4     结果是 0 2 1           差值越小，排序越前
*/

//数据比较少，用三组vector sort一下 关键是还需要记录一个差值对应的序号 输出的是编号
//如果说差值是桶，那么就可以把编号当成值

//可以把每个城市封装成 pair<int, pair<int, int>>，
//其中第一层是差值，第二层是第二次测量值，第三层是编号。
//pair 天生支持 字典序比较：先比 first，相等再比 second

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>  

using namespace std;


int main(){
    int n;
    while(cin>>n){
        vector<pair<int,pair<int,int>>> cities;           //一个pair只是一对对应组，内部有序，但是只是一个变量，若要产生一组pair需要加在数组里面
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b;
            c=b-a;
            cities.push_back({c,{b,i}});                  //花括号初始pair
        }
        sort(cities.begin(),cities.end());
        for(int i=0;i<n;i++){
            cout<<cities[i].second.second<<" ";           //first second 访问成员
        }
        cout<<endl;
    }
    return 0;
}

/*当字段超过 3 个，或字段含义不直观时，建议用 struct 定义明确的成员名*/

/*
你现在已经成功写出了嵌套 pair 的代码，说明你已掌握了 第四步。接下来可以：
1.手动模拟排序过程：取几个样本，自己按字典序比一比，看输出是否和预期一致。
2.去掉嵌套，改用 struct 写一遍，对比两种写法的优缺点，加深对 pair 适用场景的理解。
3.尝试用 tuple 重写，看看 tuple 的比较规则与 pair 相同，但可以容纳更多字段。
*/




/*G - 排名 HDU - 1236 */

/*
最后通过分数线的考生，并将他们的成绩按降序打印。

//如何计算总分，我觉得可以把题号当成桶 分数是值 之后遍历计算总分

//对于每一个考生来说最重要的是考号和总分过线了就加进去 计数的话没有问题 
想要用vector pair解决，（map实际上也是可以的）先存储总分之后已经小到大排序 倒序输出
但是现在的问题是同分数怎么处理把大的放到前面

若有多名考生分数相同，则按他们考号的升序输出。
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int N=12;
const int N2=1010;

//所以需要自定义比较函数
bool cmp(const pair<long long, string>& a, const pair<long long, string>& b){
    if(a.first != b.first) return a.first > b.first;     //分数降序
    return a.second < b.second;                          //考号升序
}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
long long g;
while(cin>>n && n!=0){
    cin>>m>>g;
    vector<pair<long long,string>> students;
        long long b[N]={0};
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
    for(int j=0;j<n;j++){
        bool s[N]={0};
        string nam;
        int n0;
        cin>>nam>>n0;
        for(int j=0;j<n0;j++){
            int x0;
            cin>>x0;
            s[x0]=true;
        }

        long long score=0;              //每个学生的总分
        for(int i=1;i<=m;i++){
            if(s[i]){
                score+=b[i];
            }
        }
        if(score>=g){
            students.push_back({score,nam});
        }
    }
    cout<<students.size()<<endl;
    //sort(students.begin(), students.end(),cmp);
    for(int i=0;i<students.size();i++){
        cout<<students[i].second<<" "<<students[i].first<<endl;
    }

    }
    return 0;
}

///////////////////////////////////////////测试
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string id;
    int score;
};

// 自定义排序：按分数降序，分数相同按 id 升序
bool cmp(const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    int N, M, G;
    while (cin >> N && N) {          // N = 0 时结束
        cin >> M >> G;
        vector<int> score(M + 1);    // 题号从 1 开始
        for (int i = 1; i <= M; ++i) {
            cin >> score[i];
        }

        vector<Student> pass;        // 存放过线的考生
        for (int i = 0; i < N; ++i) {
            string id;
            int m;
            cin >> id >> m;
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                sum += score[x];
            }
            if (sum >= G) {
                pass.push_back({id, sum});
            }
        }

        //sort(pass.begin(), pass.end(), cmp);

        cout << pass.size() << endl;
        for (const auto& s : pass) {
            cout << s.id << " " << s.score << endl;
        }
    }
    return 0;
}




/*H - 考试排名 HDU - 2093 */

/*
输出一个实时排名。
实时排名显然先按AC题数的多少排，多的在前，
再按时间分的多少排，少的在前，
如果凑巧前两者都相等，则按名字的字典序排，小的在前。

输出名字（10个字符宽），
做出的题数（2个字符宽，右对齐）和时间分（4个字符宽，右对齐）。
名字、题数和时间分相互之间有一个空格。

*/

/*
很难办 输入时是这样子的 感觉很混乱

1.按照AC数目来排  统计正数
2.统计做出来的时间 
3.没有AC的忽略罚时

所以，记录AC个数就是判断正数个数，然后计算时间，放进结构体里面，之后写个排序函数，完成了

8 20
Smith	  -1	-16	8	0	0	120	39	0
John	  116	-2	11	0	0	82	55(1)	0
Josephus  72(3)	126	10	-3	0	47	21(2)	-2
Bush	  0	-1	-8	0	0	0	0	0
Alice	  -2	67(2)	13	-1	0	133	79(1)	-1
Bob	  0	0	57(5)	0	0	168	-7	0

关键难点在于解析每个题目的字符串，尤其是带括号的格式，例如 72(3)。

解析字符串 token 的步骤
1.如果 token 是负数（以 '-' 开头）或 "0"，则该题未 AC，直接跳过。

2.否则是正数（可能带括号）：

    查找 '(' 是否存在。
    若存在，用 substr 分别提取括号前的数字（AC耗时）和括号内的数字（错误提交次数）。
    若不存在，整个字符串就是耗时，错误次数为 0。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct stu{
    string name;
    int ac=0;
    int tim=0;

    // 默认构造函数（可选，但为了安全）
    /*
    stu() : name(""), ac(0), tim(0) {}
    // 带参数的构造函数
    stu(const string& n, int a, int t) : name(n), ac(a), tim(t) {}
    */
};

bool cmp(const stu&a,const stu&b){
    if(a.ac!=b.ac) return a.ac>b.ac;
    else if(a.tim!=b.tim) return a.tim<b.tim;
    return a.name<b.name;
}

int zhuan(string a,int x,int y){
    int re=0;
    for(int i=x;i<y;i++){
        re=re*10+a[i]-'0';
    }
    return re;
}

int main(){
    int n,m;
    cin>>n>>m;
    string nam;
    vector<stu> people;
while(cin>>nam){
    int time=0,nac=0;
    for(int ai=0;ai<n;ai++){
        string a;
        cin>>a;
        if(a[0]=='-' || a[0]=='0'){
            continue;
        }
        int re=0;
        int re1=0;
        int re2=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='('){
                re=1;
                re1=i;
            }
            if(a[i]==')'){
                re2=i;
            }
        }
        int x=0,y=0;
        if(re){
            nac++;
            x=zhuan(a,0,re1);
            y=zhuan(a,re1+1,re2);
        }else{
            nac++;
            x=zhuan(a,0,a.size());
        }
        time+=x;
        time+=y*m;
    }
    people.push_back({nam, nac, time});
}
    //sort(people.begin(),people.end(),cmp);
    for(int i=0;i<people.size();i++){
        cout << left << setw(10) << people[i].name << " " << right << setw(2) << people[i].ac << " " << right << setw(4) << people[i].tim << endl;
    }


    return 0;
}

/*I - 轻如A+B HDU - 1040 */

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
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        stable_sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


/*J - 排序 HDU - 1106 */

/*
输入一行数字，
如果我们把这行数字中的‘5’都看成空格，
那么就得到一行用空格分割的若干非负整数
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int zhuan1(string& a,int x,int y){
    int re=0;
    for(int i=x;i<y;i++){
        re=re*10+a[i]-'0';
    }
    return re;
}

int main(){
    string a;
    while(cin>>a){
        vector<int> num;
        int start=0;                        //注意首尾下标改成 start 一个去判断就可以去掉5555为空格的情况
        for(int i=0;i<a.size();i++){
            if(a[i]=='5'){
                if(start<i){
                    num.push_back(zhuan1(a,start,i));
                }
                start=i+1;
            }
        }
        if(start<a.size()){
            num.push_back(zhuan1(a,start,a.size()));
        }
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}