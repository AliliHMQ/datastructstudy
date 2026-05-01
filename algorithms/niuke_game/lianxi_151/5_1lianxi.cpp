//A\世界碎片 I
//两个不带前导零的非负二进制整数 x 和 y

//x选在其中的一个数字b 

//求出将 x 变为 y 所需的最少操作次数。
//如果无法将 x 变为 y，则输出 −1。

//两个二进制数相减
//定义两个二进制数

//减去0无意义，每次操作都是减去1 或者加上1，但是如果需要又加又减是不合理的
//因此只需要 全部加，全部减，x>y减 反之则反
//特殊情况下，x==0 && y!=0此时为-1
//学习两个二进制数相减是关键 
 
//高精度 加减法？太复杂了，应该可以二进制数相加减
/*
#include <iostream>
#include <vector>
using namespace std;


//加减函数

int main(){
    string a,b;
    cin>>a>>b;
    //判断ab大小
    int x1=atoi(a.c_str());
    int x2=atoi(b.c_str());
    int m=x1-x2;
    /*if(a[0]=='0'&& b[0]!=0){
        cout<<-1;
    }
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]);
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]);

    if(a[0]=='0'&& b[0]!=0){
        cout<<-1;
    }else if(m==0){
        cout<<0;
    }else if(m>0){ //更大，减

    }

    return 0;
}*/
/*
//二进制转十进制
#include <iostream>
#include <cstring>
using namespace std;

//转换函数

int main(){
    string a,b;
    cin>>a>>b;
    unsigned long long x,y;
    x=stoull(a,nullptr,2); //十转二
    y=stoull(b,nullptr,2);

    if(x==0&&y!=0){
        cout<<-1;
    }else if(x>y){
        cout<<x-y;
    }else if(x<y){
        cout<<y-x;
    }else{
        cout<<0;
    }
    return 0;
}
*/

//B\Dog Card

//牌堆 1-2n 排列
//技能的使用方式

//猜测，每一次猜对到没有牌就结束，否则结束
//2n!种牌堆
//在每种情况下她只使用一次技能

//分别表示牌堆总张数的一半 对m取模

//结果:总共能抽到的牌数对m取模
//什么意思啊游戏中，牌堆共有 2n 张牌 怎么抽到 4 张的 第一个样例

//1、需要2n个数的全排列？
//2、第一个数 小于第二个数 或者 大于第二个数两种情况
//3、存在全升序，全降序，抽出2*n张牌

//ps.全部暴力会不会太超时了，要很多n 
//6张牌将所有 720 种情况下的抽牌数求和，最终得到 3084

//其实吧，2、第一个数 小于等于n 或者 大于n两种情况
//第一个数 小于等于n一共有(2n!)/2种排序 连续升序才能加上
//每个逐步递减1 从 2*n递减到2
//乘上2就可以了
/*
//我知道了，升序从x=1-2*n个牌的个数是(2n)！个递减到1次 其中重复了每次后面阶乘的升序序列
#include <iostream>
using namespace std;

//求阶乘函数
long long int f(long long int n){
    if(n==1) return 1;
    else return n*f(n-1);
}


int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        long long int m;
        cin>>m;
        long long y=2*x;
        long long re1=f(y);
        
    }

    return 0;
}
*/
//动态规划按总长度分层 使用组合数和阶乘进行计数

//H.Until the Blue Moon Rises
//选择两个不同的下标 i,j 
//判断是否可以通过若干次操作使得数组 A 中的所有整数都变为质数。

//该数组总和不变
//从数学角度分析 怎么把数组总和值和能否都变为质数联系在一起
#include <iostream>
using namespace std;

bool f(int x){
    if(x<2) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3;i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int s=0;
    int w=n;
    while(w--){
        int x;
        cin>>x;
        s+=x;
    }
    if(s<2*n){
        cout<<"NO";
    }else if(n==1){
        if(f(s)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }else if(n==2){
        if(s >= 4 && (s % 2 == 0 || f(s - 2))){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }else{
        cout<<"YES";
    }
    return 0;
}

//这个过了
#include <iostream>
using namespace std;
using ll = long long;

// 判断一个数是否为质数（试除法，适用于 1e12 级别）
bool is_prime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        sum += a;
    }

    // 特判总和为 1 的情况
    if (sum == 1) {
        cout << "No\n";
        return 0;
    }

    // S=2 或 S=3 时只有 n=1 才可能
    if (sum == 2 || sum == 3) {
        cout << (n == 1 ? "Yes\n" : "No\n");
        return 0;
    }

    if (n == 1) {
        // 只有一个数，判断它是否为质数
        cout << (is_prime(sum) ? "Yes\n" : "No\n");
    } 
    else if (n == 2) {
        if (sum % 2 == 0) {
            // 偶数总和：哥德巴赫猜想保证可以分成两个质数
            cout << "Yes\n";
        } else {
            // 奇数总和必须包含 2
            cout << (is_prime(sum - 2) ? "Yes\n" : "No\n");
        }
    } 
    else { // n >= 3
        // 只要总和  >= 2n 就一定可行
        if (sum >= 2LL * n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}