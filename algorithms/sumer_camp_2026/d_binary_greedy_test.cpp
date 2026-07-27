/*****************二分********************/
/*在二分搜索过程中，每次都把查找的区间减半，因此对于一个长
度为 n 的数组，至多会进行 log(n) 次查找。*/

/*
 三个常用函数
binary_search (a,a+n,key)
// 返 回 是 否 存 在 值 bool 型的 查找 key 是否存在
lower_bound (a,a+n,key)// 下 面 两 个 都 是 指 针 型 的
// 返 回 第 一 个 指 向 大 于 等 于 key 的 元 素 的 指 针
upper_bound (a,a+n,key)// 返 回 第 一 个 指 向 大 于 key 的 元 素 的 指 针


 */

 /*
 实数二分

bool check(double mid)
{
    if ( 满足题意 ) return true;
    else return false; 
}

double bsearch(double left , double right)
{
    //1. 为什么不用 while(low < high)？
    //这是整数二分的习惯，但千万不能在实数里这么写！
    //整数：low=1, high=2，如果 mid=1，你移动 low=mid+1，区间就没了，循环结束。
    //实数：low=0.0, high=1.0，mid=0.5。如果条件成立，你让 high=mid（变成0.5）。

    //此时区间变成 [0, 0.5]，它们永远不可能相等（因为实数可以无限细分，0.000...0001 总是存在）。
    //如果你用 while(low < high)，这个循环会死循环，或者因为浮点精度误差随机跳出，导致答案错误。
    //你的解法（固定循环100次）是实数二分中最稳妥、最专业的写法！ 直接避免了判断相等的烦恼。

    for (int i = 0; i < 100; i++)
    {
        mid = (left + right) / 2;
        if (check(mid ))                  //没有判断是否相等，而是用了check函数
            left = mid;
        else
            right = mid;
}

return
 */

/*A - Trailing Zeroes (III)*/

/*
1.找到对应的0的个数的N阶乘 的数N
    1.1 能生成N的阶乘的末尾0的数目的函数number0
    1.2 能进行判断大循环里面有没有N是否符合要求
    复杂度太高了 线性查找会超时
*/

/*询问思路
1.末尾零的来源：
N! 中末尾零的个数等于因子 10 的个数，而 10 = 2 × 5。由于因子 2 的个数远多于因子 5，所以零的个数只取决于因子 5 的个数。
记函数 f(N) = N! 中因子 5 的个数，则
f(N) = ⌊N/5⌋ + ⌊N/25⌋ + ⌊N/125⌋ + …

2.因此可以用二分查找来定位最小的 N 使得 f(N) ≥ Q。
*/


//方案一 自己想的按照步骤判断

#include <bits/stdc++.h>
using namespace std;


//此函数太烂了
/*
1. 阶乘计算会溢出（致命问题）
你写的 sum *= i 会迅速产生巨大的数，远超 long long 能容纳的范围（long long 最大约 9.22e18）。
例如，当 n = 20 时，20! 已经是 2.43e18，接近上限；n = 21 时 21! = 5.1e19，已经溢出。而你二分查找的 mid 可能达到几亿，根本不可能计算其阶乘。
一旦溢出，结果就是未定义行为，得到错误答案甚至程序崩溃。

2. 时间复杂度不可接受
即使不溢出，计算 mid! 需要 O(mid) 次乘法，而二分查找要进行约 30 次，每次 mid 可能很大（例如 5e8），这根本无法在时限内完成。
题目 T ≤ 10000，要求快速求解，显然不能这样暴力。
*/
int number0(int n){
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    int num0=0;
    while(sum>=10){
        if(sum%10==0){
            num0++;
            sum/=10;
        }
    }
    return num0;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int N;
        cin>>N;
        int re;
        int low=0,high=5*N;
        while(low<high){
            int mid=(low+high)>>1;
            if(number0(mid)>=N){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        re=low;
        if(number0(re)==N){
            cout<<"Case "<<i+1<<": "<<re<<endl;
        }else{
            cout<<"Case "<<i+1<<": "<<"impossible"<<endl;
        }
    }
    return 0;
}




//果然还是使用方程最快了 数学很好用

#include <bits/stdc++.h>
using namespace std;

int count0(long long num){            //记数字num里面为5的倍数的因子个数~数0个数
    int ans=0;
    while(num>0){
        num/=5;
        ans+=num;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int Q;
        cin>>Q;                     //目标尾0个数

        long long low=0,high=5*Q;  //// 保证 f(high) >= Q
        while(low<high){
            long long mid=(low+high)>>1;
            if(count0(mid)>=Q){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        long long num=low;

        if(count0(num)==Q){
            cout<<"Case "<<i+1<<": "<<num<<endl;
        }else{
            cout<<"Case "<<i+1<<": "<<"impossible"<<endl;
        }
    }


    return 0;
}






 /******************贪心*******************/

 /*贪心算法是指，在对问题求解时，总是做出在当前看来是最好的
选择。也就是说，不从整体最优上加以考虑，他所做出的是在某
种意义上的局部最优解。*/

/*全局最优解：动态规划求最优解*/

/*如果一个问题确定用贪心法能得到最优解，那么应该使用
它。那么，如何判断一个题目能用贪心法?*/

/*
1.最优子结构性质。
2.贪心选择性质。贪心策略必须具备无后效性，即某个状态以
后的过程不会影响以前的状态, 只与当前状态有关
*/

/*比如 看最多的电视节目*/
/*
解题的关键在于选择什么贪心策略才能安排尽量多的活动。由于
活动有开始时间和结束时间，考虑下面 3 种贪心策略:

1.最早开始时间。
1.最早结束时间。
3.用时最少。

经过分析发现, 第 1 种策略是错误的, 因为如果一个活动迟迟不
终止, 后面的活动就无法开始。第 2 种策略是合理的，一个尽快
终止的活动可以容纳更多的后续活动。第 3 种策略也是错误的。
*/

/*
struct node {
    int start ,end;
}record[MAXN ];

bool cmp(const node& a,const node &b){
    return a.end < b.end;
}

for(int i=0;i<n;i++) {
    scanf("%d %d" ,&record[i].start ,& record[i]. end );
}
sort(record ,record + n,cmp );// 按 节 目 结 束 时 间 排 序

int count = 0,lastend = -1;
// 看 完 整 节 目 数 量 ， 上 一 个 节 目 结 束 时 间
for(int i=0,i<n;i++){
    if(record[i].start >= lastend ){
        // 节 目 的 开 始 时 间 一 定 要 在 上 一 个 节 目 结 束 之 后
        count ++;
        lastend = record[i]. end;
    }
} 

printf("%d\n",count );
*/




/*B - 奇异的表现*/

/*
现在，这里有一个函数：
F（x） = 6 * x^7+8*x^6+7*x^3+5*x^2-y*x （0 <= x <=100）
你能找到当x在0和100之间时的最小值吗？

输入的第一行包含一个整数 T（1<=T<=100），表示测试用例的数量。
接着是T直线，每条直线只有一个实数Y。（0 < Y <1e10）

找到6*x^7+8*x^6+7*x^3+5*x^2 减去 y*x 的最小值

在 [0,x0]之间 其中6*x0^6+8*x0^5+7*x0^2+5*x0==y 取得最小值
*/

/*
果然还是数学吗
这个问题其实是一个单变量凸函数求最小值的问题。
你提到“最小值可以在mid左边也可能在右边”，
这说明你在考虑直接对函数值进行二分，但函数值本身不是单调的，
所以直接用二分找最小值是不对的——二分法只能用于单调函数找零点或边界。

不过，由于这个函数是凸函数（二阶导恒正），
它的最小值点恰好是导数为零的点，而导数函数是单调递增的，
所以可以用二分法求导数的零点。

即导数的零点就是方程的极小值点

*/




#include <bits/stdc++.h>
using namespace std;

double funct(double x){
    double re;
    re=42*x*x*x*x*x*x+48*x*x*x*x*x+21*x*x+10*x;
    return re;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        double y;
        cin>>y;
        double low=0,hight=100;
        double re=0;
        //循环100次 这时候 low 和 high 的差值就是0，已经是绝对精度了。
        for(int i=0;i<100;i++){
            double mid=(low+hight)/2.0;
            if(funct(mid)-y>0){
                hight=mid;
            }else{
                low=mid;
            }
        }
        re=low;
        double res=re*re*re*re*re*re*re*6.0+re*re*re*re*re*re*8.0+re*re*re*7.0+5.0*re*re-y*re;
        printf("%.4f\n",res);
    }

    return 0;
}




/* C - 馅饼 */

/*
1.不止一个派，我有好几个N派，口味和大小各异
2.所有馅饼都是圆柱形，高度都一样算尺寸可以忽略高度，但馅饼的半径可能不同。

//V=pi*n1*n1+pi*n2*n2
样例1是怎么回事 
不理解
每人都拿到一块派。
这应该是一块派的一块，而不是好几块小块，因为那样看起来很乱。
不过这块也可以是一整块。

我们能得到的最大尺寸是多少？

所以我们不能直接用“总面积/人数”来算，必须通过检查每个馅饼能切出多少块。
*/

/*
确定寻找一个 V 符合二分
1.确定v的范围
    1.1下界 low：0（或者一个很小的正数，比如 1e-10）。
    1.2上界 high：最大的单个馅饼面积 π * max_radius²。
因为任何一块馅饼都不可能超过最大的那个馅饼，如果 V 比最大面积还大，那么连一个整块都切不出来，肯定不可行。

2.确定判断函数 最大的v切出来的饼的数目==朋友数+1
*/

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);

bool canCut(const vector<double>& area, double piece, int need) {
    long long cnt = 0;
    for (double s : area) {
        cnt += (long long)(s / piece);          // 去掉 + EPS
        if (cnt >= need) return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, F;
        scanf("%d%d", &N, &F);
        vector<double> area(N);
        double maxArea = 0.0;
        for (int i = 0; i < N; ++i) {
            int r;
            scanf("%d", &r);
            area[i] = PI * r * r;
            maxArea = max(maxArea, area[i]);
        }

        int people = F + 1;
        double low = 0.0, high = maxArea;        // 上界用最大派面积即可

        for (int iter = 0; iter < 100; ++iter) {
            double mid = (low + high) / 2.0;
            if (canCut(area, mid, people))
                low = mid;
            else
                high = mid;
        }
        printf("%.4f\n", low);                   // 与样例格式一致
    }
    return 0;
}




/*D - 最佳牛系列*/

/* 错误方案 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    deque<char> name;               //双端队列
    for(int i=0;i<N;i++){
        char x;
        cin>>x;
        name.push_back(x);
    }
    queue<char> res;
    while(name.size()){
        //贪心策略错误 —— 只比较当前首尾字符，
        //当它们相等时无法做出正确选择，
        //会导致最终字符串不是最小字典序。
        if(name.front()<=name.back()){
            res.push(name.front());
            name.pop_front();
        }else{
            res.push(name.back());
            name.pop_back();
        }
    }
    string re;
    for(int i=0;i<N;i++){
        re+=res.front();
        res.pop();
    }
    cout<<re<<endl;
    return 0;
}

/*正确贪心策略*/
/**************双指针*****************/
/*
每一步，设当前剩余字符串为 S（从位置 l 到 r），将其与逆序 reverse(S) 比较
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    //使用字符串比较 双端指针
    string name;
    for(int i=0;i<N;i++){
        char x;
        cin>>x;
        name+=x;
    }
    string result;
    int l=0,r=N-1;
    while(l<=r){                   
        string s1,s2;
        for(int i=l;i<=r;i++){
            s1+=name[i];
        }
        for(int i=r;i>=l;i--){
            s2+=name[i];
        }
        if(s1<s2){
            result+=s1[0];
            l++;
        }else{
            result+=s2[0];
            r--;
        }
    }
    for (size_t i = 0; i <result.length(); i += 80) {
        std::cout << result.substr(i, 80) << '\n';
    }
    
    return 0;
}


/*E - The Frog's Games*/

/*
1.河的宽度为 L（1 ≤ L ≤ 1,000,000,000）   //好大的数据
2.河中有 n（0 ≤ n ≤ 500,000）块石头
3.青蛙只能跳着过河，但可以落在石头上。
如果掉进河里，就会被淘汰。
4.如果要成功跳过河，他们至少需要具备多大的跳跃能力
（即青蛙的最长跳跃距离）

三个正整数 L、n 和 m。接下来 n 行，
每行给出一个整数，表示该石头距离起始岸边的距离。
*/
#include <iostream>














/*****************贪心+二分*****************/

/*J - 攻击性牛*/

/*
N个位置C头牛
间隔最远分开 求最短距离
*/

/*
贪心加二分

check函数里面用贪心
""
二分找最佳方案

number==C（每个间隔里面放牛数目能否>C）为判断标准
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long mid,vector<long long>& place,int C){
    long long re=1;
    long long last=place[0];              //注意这里判断的是上一个牛所在的位置
    for(int i=1;i<place.size();i++){
        if(place[i]-last>=mid){
            re++;
            last=place[i];
            if(re>=C) return true;
        }
    }
    return false;
}

int main(){
    int N,C;
    cin>>N>>C;
    vector<long long> place(N);
    for(auto &x:place) cin>>x;
    sort(place.begin(),place.end());

    long long low=0,high=place[N-1]-place[0];
    long long ans=0;                            //整数二分是有答案变量的

    while(low<=high){                          //循环结束条件！
        long long mid=(low+high)>>1;
        if(check(mid,place,C)){               // 能放下，说明距离还可以更大，记录答案，往右边（大的）找，直到两个边界逼近快相等才退出得到最终答案 mid
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

