//暑假第一场补题

//最没有思路，完全读不懂 一v一


//B题优化，规范格式，其中选择改用差分

/*
#include <bits/stdc++.h>
using namespace std;
using int64=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    vector<int64> a(n);
    for(auto &x:a) cin>>x;
    
    int64 g=0;
    for(int i=2;i<n;i++){
        int64 s_diff=a[i-2]-2LL*a[i-1]+a[i];
        g=gcd(g,llabs(s_diff));
    }
    
    if(g==0){
        cout<<-1<<endl;
        return 0;
    }
    cout<<g<<endl;
    return 0;
}
*/

//强迫症 砍树 题目化为求和
/*
可以把每棵树看成若干层。当 a[i]>a[i-1] 时，第 i 棵树比左侧相邻树多出的 a[i]-a[i-1] 层，无法由从左边延伸过来的区间操作覆盖；每一层都必须在位置 i 新开始一次区间操作。因此这些正的上升量都必须计入答案。
当高度不高于前一棵树时，不需要新开操作：先前已经开始的操作可以选择一部分继续向右延伸。于是所有上升量之和既是下界，也可以实际达到。
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<long long> a(n+1);
    a.push_back(0);
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    long long re=0;
    for(int i=1;i<n+1;i++){
        if(a[i]>a[i-1]){
            re+=a[i]-a[i-1];
        }
    }
    cout<<re<<endl;
    
    return 0;
}*/

/*
L. 小明的丹药（easy version）
题解
首先分别计算阴、阳两侧的元素总上限。

//数学原理
若总和较小一侧的数值为偶数，总和较大的一侧一定可以凑出相等的数值。 若总和较小一侧的数值为奇数： 
总和较大的一侧若拥有至少 1 份 1 点灵物，则可以凑出与较小侧相等的数值； 
总和较大的一侧若没有 1 点灵物，则最大可行解为较小侧总和减 1 的偶数。

时间复杂度：(O(T * n))，空间复杂度：(O(n))。
*/
/*
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        int yi=x1*2+x2;
        int ya=y1*2+y2;
        int an=0;
        if(yi>ya){
            if(ya%2==0){
                an=ya;
            }else{
                if(x2==0){
                    an=ya-1;
                }else{
                    an=ya;
                }
            }
        }else if(ya>yi){
            if(yi%2==0){
                an=yi;
            }else{
                if(y2==0){
                    an=yi-1;
                }else{
                    an=yi;
                }
            }
        }else{
            an=ya;
        }
        cout<<2*an<<endl;
    }
    return 0;
}*/

/*
J. 灵魂之塔
题解
将奇偶性相同的相邻元素称为一对异常相邻元素。

如果不存在异常相邻元素，原序列已经交替。
对于 n≥2，只有删除首元素或尾元素后仍然交替；删除中间元素会使原来相距两个位置、奇偶性相同的元素相邻，因此答案为 2。当 n=1 时，答案为 1。
如果恰好存在一对异常相邻元素，必须删除这一对中的某一个元素。删除任意一个都能恢复交替，因此答案为 2。
如果存在至少两对异常相邻元素，则无法通过删除一个元素全部消除。即使两对异常相邻元素首尾相接，删除中间元素后，新相邻的两个元素仍然具有相同奇偶性，因此答案为 0。

代码找到第一对异常相邻元素后，继续检查后面是否还存在异常相邻元素，即可确定答案。

时间复杂度为 O(n)，空间复杂度为 O(n)。
*/
/*#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(auto &x:a) cin>>x;
        for(int i=0;i<n;i++){
            b[i] = a[i] & 1;  //整数取模
        }
        if(a.size()==0){
            cout<<0<<endl;
            return 0;
        }else if(a.size()==1){
            cout<<1<<endl;
        }else{
            int con=0;            //坏边
            for(int i=1;i<n;i++){
                if(b[i-1]==b[i]){
                    con++;
                }
            }
            
            if(con==0){
                cout<<2<<endl;
            }else if(con==1){
                cout<<2<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
        
    return 0;
}*/

/*
H.神秘整数
正确的解题思路
根据同余的性质：若 a ≡ b (mod k)，则 k 能整除 (a - b)。
所以，对于数组中的所有数，要让它们对 k 的余数都相同，等价于：k 必须能整除所有数之间的差值。
核心代码：把所有数的差保存起来，并求所有差的公因数
我们可以先求出所有数相对于第一个数的差值，然后求出这些差值的最大公约数（GCD）。那么，所有满足条件的 k，就是这个最大公约数的所有大于1的约数。
*/

//01题解代码
#include <bits/stdc++.h>
using namespace std;

int n,a[105],maxx,ggcd;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> res;
    //与某一个数的差值也可以，排序后取相邻值只是让差值的绝对值更小，但算法上无实质区别。
    sort(a+1,a+1+n);
    ggcd=a[2]-a[1];
    for(int i=3;i<=n;i++){
        ggcd=__gcd(ggcd,a[i]-a[i-1]);
    }
    if(ggcd>1)res.push_back(ggcd);
    for(int i=2;i<=ggcd/i;i++){
        if(ggcd%i==0){
            res.push_back(i);  // 加入小因子
            /*
            当枚举因子 i 时，如果 ggcd % i == 0，那么 i 和 ggcd / i 都是 ggcd 的约数。
            但如果 i == ggcd / i（即 ggcd 是完全平方数，i 等于它的平方根），此时两个约数相等，如果同时加入就会导致重复。
            */
            if(ggcd/i!=i)res.push_back(ggcd/i);   // 立即加入大因子
        }
    }
    if(res.empty()) cout<<-1;
    sort(res.begin(),res.end());
    for(auto p:res) cout<<p<<' ';
    return 0;
}

//C最大公约数
