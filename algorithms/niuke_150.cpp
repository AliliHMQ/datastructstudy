//1、宝石
/*#include <iostream>
using namespace std;

const int N=1e5+10;
int q[N]={};

void quick_sort(int q[], int l, int r)   //当数组是空的时候，可以说是一个指针； 
{
    if (l >= r) return;  //函数返回值； 

    int i = l - 1, j = r + 1, x = q[l + r >> 1]; //x = q[l + r >> 1]; 数学上等于（l+r）/2；这种写法在处理大数组时是安全的，因为 >> 1 不会像 /2 那样可能产生浮点数的问题。 
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);//递归//每一次的首元都会变化，解决了数组中间最小值问题； 
	quick_sort(q, j + 1, r);//左右对称； 
}
int main(){
    int n;
    scanf("%d",&n);
    int a[N]={}; //偶数；
    int b[N]={}; //奇数 //红色
    int a1=0,b2=0;

    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);     //处理输入
        if(q[i]%2==0) a[a1++] = q[i];
        else b[b2++] = q[i];
    }

    quick_sort(a,0,a1-1);
    quick_sort(b,0,b2-1);
    
    long long red_sum=(b2>0)?b[b2-1]:0;
    long long blue_sum=(a1>0)?a[a1-1]:0;

    printf("%lld ",max(red_sum,blue_sum));

    int i=b2-1;  //奇数数组下标 红色
    int j=a1-1;  //偶数数组下标

    for(int k=1;k<n;k++){
        //选择宝石并且累加
        //每轮执行一组
        if(i>=0){
            red_sum+=b[i];   //奇数
            i--;
        }else{
            red_sum=0;
        }

        if(j>=0){
            blue_sum+=a[j];  //偶数4
            j--;
        }else{
            blue_sum=0;
        }
        printf("%lld",max(red_sum,blue_sum));
        if(k<n-1){
            printf(" ");
        }
    }
    return 0;
}*/

//1、宝石
/*#include <iostream>
using namespace std;

const int N=1e5+10;
int q[N]={};

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    int n;
    scanf("%d",&n);
    int a[N]={}; // 偶蓝队
    int b[N]={}; // 奇红队
    int a1=0, b2=0;

    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
        if(q[i]%2==0) a[a1++] = q[i];
        else b[b2++] = q[i];
    }

    quick_sort(a, 0, a1-1);
    quick_sort(b, 0, b2-1);
    
    long long red_sum = (b2>0) ? b[b2-1] : 0;
    long long blue_sum = (a1>0) ? a[a1-1] : 0;

    printf("%lld", max(red_sum, blue_sum));

    int i = b2 - 1;  // 奇数
    int j = a1 - 1;  // 偶数

    for(int k=1; k<n; k++){
        // 红队从蓝队取最重宝石
        if(j >= 0){
            red_sum += a[j];
            j--;
        } else {
            red_sum = 0;
        }

        // 蓝队从红队取最重宝石
        if(i >= 0){
            blue_sum += b[i];
            i--;
        } else {
            blue_sum = 0;
        }

        printf(" %lld", max(red_sum, blue_sum));
    }
    printf("\n");
    return 0;
}*/

//数论迷城 数字很大
//n 组数，n个区间

/*#include <iostream>
using namespace std;

const int N=1e5+10,N1=1e19;
long long q[N]={};

long long gcd(long long l,long long r){
    long long max=0;
    for(long long k=l;k<=r;k++){  //每组数里面的每一个正整数
        for(long long j=1;j<=r;j++){
            if(k%j==0){
                max=j;
            }
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    long long re=1;
    for(int i=0;i<n;i++){
        int x1,x2;
        scanf("%d %d",&x1,&x2);
        if(re>)
    }

    return 0;
}*/

//改
/*#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    bool has_range = false;   // 是否存在长度≥2的区间
    ll g = 0;                 // 单点区间的gcd

    for (int i = 0; i < n; i++) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        if (l < r) {
            has_range = true;   // 存在连续整数，答案必为1
        }
        // 只有当所有区间都是单点时，才需要计算gcd
        if (!has_range) {
            if (g == 0) g = l;
            else g = gcd(g, l);
        }
    }

    if (has_range) {
        printf("1\n");
    } else {
        printf("%lld\n", g);
    }
    return 0;
}*/

//更加能够理解
//数论迷城 数字很大
//n 组数，n个区间
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    // 辗转相除法求最大公约数
    while (b!=0) {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main() {
    int n;
    scanf("%d",&n);
    long long re=0;      // 用于记录所有单点区间的 gcd
    int flag=0;          // 标记是否存在长度 ≥2 的区间

    for (int i=0;i<n;i++) {
        long long l,r;
        scanf("%lld %lld",&l,&r);
        if(l<r){
            flag=1;      
        }
        if(!flag){
            if (re==0)re=l;      // 第一个单点
            else re=gcd(re,l);     // 与后面的单点求gcd
        }
    }
    if (flag) printf("1\n");
    else printf("%lld\n",re);

    return 0;
}


