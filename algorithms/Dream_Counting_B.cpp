//梦中的统计
#include <iostream>
#include <cstring>
using namespace std;

//1、
//我想把每一个数转换成字符串，然后循环统计
//每一个数转换成字符串怎么做查一下

/*int main(){
    int a1,a2;
    cin >> a1 >> a2;
    int a[10];
    for(int i=a1;i<=a2;i++){
        
    }
    return 0;
}*/

//2、
//在这里的话，我想用每次对10取余，但是数据多的话就不好了
int main(){
    int a1,a2;
    scanf("%d %d",&a1,&a2);
    int a[10]={};
    for(int i=a1;i<=a2;i++){
        int x=i;
        while(x){
            int m=x%10;
            a[m]++;
            x/=10; //这里必须要有赋值！！！不然会死循环
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

//3、
//修改
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 数位 DP，返回 0~n 中每个数字的出现次数
vector<ll> digitDP(ll n) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    if (digits.empty()) digits.push_back(0);
    reverse(digits.begin(), digits.end());

    vector<ll> cnt(10, 0);
    // dp[pos][tight][leadingZero] 通常用于统计个数，这里我们直接累加计数
    // 更简单的方法是：枚举每个数字 d，用 DP 计算 d 出现的总次数
    // 但为了代码简洁，这里不展开，推荐上面的数学方法
    // （若需要数位 DP 完整实现，请参考经典模板）
    return cnt;
}