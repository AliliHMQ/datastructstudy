//位运算和离散化
/*
程序中的所有数在计算机内存中都是以二进制的形式储存的。
位运算就是直接对整数在内存中的二进制位进行操作。
*/

/* 模板 汉明权重 */
//汉明权重
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int cnt=0;
        while(x){
            cnt+=x&1;
            x>>=1;
        }
        cout<<cnt<<" ";
    }
    return 0;
}

/*
1.按位取反 ~
2.按位与 &
3.按位或 |
4.按位异或 ^
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int x1=a&b;
    cout<<x1<<endl;
    int x2=a|b;
    cout<<x2<<endl;
    int x3=a^b;
    cout<<x3<<endl;
    int x4=~a;
    cout<<x4<<endl;
    int x5=a<<k;
    cout<<x5<<endl;
    int x6=a>>k;
    cout<<x6<<endl;
    return 0;
}

//移位 算术移位、逻辑移位、循环移位．
/*
1.逻辑移位用 0 填充空位，
2.算术右移用符号位填充空位，算术左移和逻辑左移相同，
3.循环移位用溢出位填充空位．
*/

//2的幂
/*2 的非负整数次幂：
int mulPowerOfTwo(int n, int m) {  // 计算 n*(2^m)
  return n << m;
}

int divPowerOfTwo(int n, int m) {  // 计算 n/(2^m)
  return n >> m;
}
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;
    long long re1=(long long)a<<b;  // //将 a 提前转为 long long 再进行移位：
    cout<<re1<<endl;
    int re2=a>>b;
    cout<<re1<<endl;
    int re2=a>>b;
    cout<<re2<<endl;
    bool re3=(a>>b)&1;
    cout<<re3<<endl;
    int re4=a&~(1<<b);         //将a的第b位改成0
    cout<<re4<<endl;
    int re5=a|(1<<b);         //将a的第b位改成1
    cout<<re5<<endl;
    int re6=a^(1<<b);         //将a的第b位取反
    cout<<re6<<endl;
    return 0;
}



//自己推出来这个，厉害了，多试试总是能设计出来的
#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    for(int i=1;i<=10;i++){
        int re1=20 & i;
        cout<< re1<<" ";
        int re2=20 | i;
        cout<< re2<<endl;
        cout<<re1+re2<<endl;
        //根据输出我们可以推出，或和与相加为两个数二进制相加。
    }*/
    int a;
    cin>>a;
    int re1=2025-a;
    if(re1==a&re1+a|re1){
        cout<<re1<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}




/* D - 烹饪问题 */

//请你找到契合度最高的两种食材，并输出它们的契合度。
//我们可以双重循环枚举每一种情况，但是这样会超时。

/*
首先，n^2 暴力是好写的，直接两两枚举即可。
下面我们增加两个优化：
1.枚举前从大到小排序。
2.如果当前枚举的数不超过（可以相等）目前的答案 ans，直接跳过。
*/

/*
注意到 a and b 一定不超过 a 和 b，
因此当 a 严格大于当前答案时，才有可能会使答案严格增加。
*/

#include <bits/stdc++.h>
using namespace std;
long long a[1000010];

bool cmp(long long x,long long y){
    return x>y;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long re=0;
    for(int i=0;i<n;i++){
        if(a[i]<=re) continue;          //我滴天哪，由于这一题呢，是N=1e6 稍微优化一下就很可能过了
        for(int j=0;j<n;j++){
            if(i!=j){
                re=max(re,a[i]&a[j]);
            }
        }
    }
    cout<<re<<endl;
    return 0;
}



/* E - 射箭 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    if(x+y<z || x+z<y || z+y<x){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}

//匪夷所思这一题怎么回事怎么简单但在这里？



/* F - 高低位交换 */
//其中前 16 位为高位，即 01000000000000010100；后 16 为低，
/*
通常情况下，左移一位表示将这个数乘以2，
右移一位表示将这个数除以2，向下取整.

//cout<<((x&0x0000ffff)<<16|(x&0xffff0000)>>16) ？！
//0x0000ffff 是 0000 0000 0000 0000 1111 1111 1111 1111   取后16位往左移16格
//0xffff0000 是 1111 1111 1111 1111 0000 0000 0000 0000   取前16位往后移16格
//最后用或把它们拼起来
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a;
    cin>>a;
    cout<<((a&0x0000ffff)<<16 | (a&0xffff0000)>>16);
    return 0;
}


/* G - 找筷子 */
//但是巧合的是，这些筷子中只有一只筷子是落单的，其余都成双
//可以帮 CX 找出这只落单的筷子的长度吗？
/* 
#include <bits/stdc++.h>
using namespace std;

int a[10000010]; //不可以呀，太大了

bool cmp(int x,int y){
    return x<y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1;i<=10;i++){
        int re=i&~i;
        cout<<"自己与上自己的按位取反答案验证"<<re<<endl;
    }
    //全是0
    //排序，两两一组，需要优化，N=1e7+1;
    
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>a[i];
    }

    sort(a,a+x,cmp);

    bool re=0;
    for(int i=0;i<=x-3;i+=2){
        if(a[i]&~a[i+1]){
            re=1;
            cout<<a[i]<<endl;
            break;
        }
    }
    if(!re){
        cout<<a[x-1]<<endl;
    }
    return 0;
}

*/

/*
✅ 正确解法：异或（XOR）
因为除了一个数出现奇数次（1次），其他数都出现偶数次（2次），而异或运算满足：

a ^ a = 0
0 ^ a = a

交换律、结合律

*所以把所有数全部异或起来，最终结果就是那个落单的数。*
空间复杂度 O(1)，时间复杂度 O(n)，完全满足要求。
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    int re=0;
    while(t--){
        int a;
        cin>>a;
        re^=a;
    }
    cout<<re<<endl;
    return 0;
}




/* H - 还是 N 皇后 */

// N*N 棋盘放皇后 求放置棋子的方案总数。
//此题的正解就是位运算

//此题算法:dfs+位运算


/* J - 火烧赤壁 */
//1.起点确定下来，终点选择最远的就确定了每一段长？太长了，怎么优化

/*
所以，我们得到了一个解法：分别对起点和终点进行排序，
循环加上每一条线段的长度，若与前一条线段重复减去重复部分
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> s;
    vector<int> e;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        s.push_back(a);
        e.push_back(b);
    }
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    int re=e[0]-s[0];
    for(int i=1;i<t;i++){
        re+=e[i]-s[i];
        if(s[i]<e[i-1]){
            re-=e[i-1]-s[i];
        }
    }
    cout<<re<<endl;
    return 0;
}

/* 上一题区间覆盖长度数据加强版 */
//_int128 输出练习

#include <bits/stdc++.h>
using namespace std;

void print(__int128 x) {
    /* //距离不可能为负数
    if (x<0) {
        putchar('-');
        x=-x;
    }*/
    string s;
    while(x>0){  
        s+=(x%10)+'0';
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}

int main(){
    int t;
    cin>>t;
    vector<long long> s;
    vector<long long> e;
    for(int i=0;i<t;i++){
        long long a,b;
        cin>>a>>b;
        s.push_back(a);
        e.push_back(b);
    }
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    __int128 re=(__int128)e[0]-s[0]+1;
    for(int i=1;i<t;i++){
        re+=(__int128)e[i]-s[i]+1;
        if(s[i]<e[i-1]){
            re-=(__int128)e[i-1]-s[i]+1;
        }
    }
    print(re);
    return 0;
}


/* L - Little Girl and Maximum XOR */
/*
给定两个整数 l 和 r。
考虑所有整数对 (a, b)，其中 l ≤ a ≤ b ≤ r，
计算 a xor b 的值。

你的任务是找出所有这些值中的最大值。
*/

/*完全错误！
//求出最大值的最高位是多少 换成十进制与-1的下一位异或就是最大值

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,max,min;
    unsigned re=0;

    if(a>b){
        max=a;
        b=min;
    }else{
        max=b,min=a;
    }
    int cnt=0;
    while(max){
        cnt++;
        max/=2;
    }

    re=(1<<cnt)+(1<<cnt-1);
    cout<<re<<endl;
    return 0;
}*/

//对于区间 [l, r]，
//最大异或值只取决于 l 和 r 的二进制表示中从最高位开始第一个不同的位。

/*
1.计算 x = l ^ r，异或结果中为 1 的位就是 l 和 r 不同的位。
2.找出 x 的最高位位置 k（例如 x 的最高位是第 5 位，则 k=5）。   怎么寻找最高位？
3.答案 = (1LL << (k+1)) - 1（若 x=0，则答案为 0）。
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    long long x=a^b;
    //寻找最高位
    //当 x 大于 1 时，右移一位
    int k=0;
    while(x>1){
        x>>=1;
        k++;
    }
    //类型问题：1是int类型，在大多数现代编译器中是 32 位有符号整型
    long long ans=(1LL<<(k+1))-1;   //是long long ans = (1 << (k + 1)) - 1; 换类型
    cout<<ans<<endl;
    
    return 0;
}


/* I - 数列离散化 */
//不同数字

//进行一个去重啊然后输出，就好了
//数据个数有 N=1e5个，优化一下O(n^2)应该能过

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
        vector<int> re;
        for(int i=0;i<n;i++){
            re.push_back(a[i]);        //没有分配空间要用push
        }
        sort(re.begin(),re.end());
        re.erase(unique(re.begin(),re.end()),re.end());
        /* 二分查找优化
        for(int i=0;i<n;i++){
            for(int j=0;j<re.size();j++){
                if(a[i]==re[j]){
                    cout<<j+1<<" ";
                }
            }
        }*/
        for(int i=0;i<n;i++){
            int rank=lower_bound(re.begin(),re.end(),a[i])-re.begin()+1;
            //lower_bound(...) - sorted.begin() 是两个迭代器相减，得到它们之间的距离（也就是下标索引
            cout<<rank<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/* 报数 */
/* 汉明权重 */

/* #define lowbit(x) ((x) & -(x)) */
/* cout<<n+lowbit(n)<<endl */
//这个操作总是让 n 变大，并且会消除二进制末尾连续的 1，
//并向上进位。它永远等于 n 加上一个 2 的幂次（即最低位 1 的权值）。

/*


如果数 a 满足 popcount(a)=2，就稍微麻烦一些。
我们先设数 a 在二进制表示下为 a 则可以找到 a 最右侧的 1，然后将其“加 1”即可。

通俗地讲，就是找到最右侧的 01，将其变为 10。例如：1010 的下一个合法数字为 1100。请注意，这个过程并不是真正的加 1。
*/

#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))

int popcount(long long a){
    int count=0;
    while(a){
        count+=a&1;
        a>>=1;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        int re=popcount(x);
        if(re>=3){
            cout<<"No,Commander"<<endl;
        }else if(re<=1){
            cout<<x+1<<endl;
        }else{
            cout<<x+lowbit(x)<<endl;        //就是找到最右侧的 01，将其变为 10
        }
    }
    return 0;
}


/* O - 线性基 */
/*
给定 n 个整数（数字可能重复），
求在这些数中选取任意个，
使得他们的异或和最大。

求在这些数中选取任意个
*/

/*
异或线性基 基础 而是一种数据结构
1.一堆数字中，任意的a和b，用a^b的结果代替a.b中任意一个数字，不会影响异或和的组成
2.一堆数字中，任意的a和b，如果有a^b=0，则a=b舍去一个数字不会影响异或和的组成
3.一堆数字中能否异或出0，在求出异或空间线性基之后需要单独被标记

表现形式
线性基通常维护一个数组 p[i]，
其中 i 表示最高位（bit）。
它保证 p[i] 的最高位是第 i 位，
并且整个集合是线性无关的（没有冗余）。

且它不关心原数组顺序，只关心能异或出的值域空间。

说白了就是单位矩阵一样的
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M=62;
ll p[M+1];        

//将x插入线性基
void insert(ll x){
    //从最高位到最低位寻找空位让 x 更新
    for(int i=M;i>=0;i--){
        //第i位是否是0
        if(!(x>>i&1)) continue;
        //线性基这一位是否是0 是，直接加入x
        if(!p[i]){
            p[i]=x;
            return;  //插入之后马上结束 //一次判断要加上循环终止号
        }
        //这一位是1
        x^=p[i];  //更新最简线性基
    }
}

//从最高到低异或，查询最大值
ll q(){
    ll re=0; //维持这个最大的异或值，能够通过多一位更新就变，否则不变
    for(int i=M;i>=0;i--){
        if((re^p[i])>re){
            re^=p[i];
        }
    }
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        long long a;
        cin>>a;
        insert(a);
    }
    cout<<q()<<endl;
    return 0;
}