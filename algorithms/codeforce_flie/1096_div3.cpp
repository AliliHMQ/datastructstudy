//A题 A. Koshary

//Yousef 位于坐标 (0,0)，想要到达一盘科沙里所在的位置 (x,y)。
//从任意点 (a,b) 出发，
//一个大步会将他移动到：(a+2, b) 或 (a, b+2)

//最多只能走一次小步
// Yousef 能否恰好到达科沙里所在的位置 (x,y)

//准备算 x和y需要的距离
//只能用一次 +1
//两个不同时为奇数就可以
/*
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(x%2==1 && y%2==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
*/

//B. Party Monster
//长度为 n 的字符串 s
//最多可以执行一次以下操作
//选择一个字符串 s 的子串 ∗ 并将其删除
//将删除的字符逐个重新插入到剩下的字符串中 字符可以独立地插入到任意位置

//是否有可能在执行最多一次操作后，得到一个正则括号序列
//正则括号序列是一种括号序列，
//可以通过在原序列的字符之间插入字符 将其转换为正确的算术表达式

//正则括号 1、成对 然后正括号都在反括号前 最后不能以正括号结尾

//由于操作带来的便利，只要不成对出现，那就不对

/*
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x=0;
        cin>>x;
        string a;
        cin>>a;
        int x1=0,x2=0;
        for(int i=0;i<x;i++){
            if(a[i]=='('){
                x1++;
            }else{
                x2++;
            }
        }
        if(x1==x2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
*/

//C. Snowfall

//给了你一个由 n 个正整数组成的数组 a

//f(a) 表示数组 a 中所有
//乘积能被 6 整除的子数组∗ 的
//个数
//你的任务是重新排列数组 a 的元素，使得 f(a) 最小

//前缀 乘积?

//首先，数组里面本来就是 6 的倍数的数是固定最小的f(a)数目
//现在需要解决的问题就是 我感觉需要把连续的不被6整除的数放一起 
//实际上可以一起产生2和3的也不行
//把2的倍数全部放前面 3的倍数放最后面 其他的数字放中间


//1、先把全部6整除的数放前面  
//2、把是2的倍数的数放前面 3的倍数放最后
//3、其他的数放中间
/*
#include <iostream>
using namespace std;

const int N=1e6;
int a[N],s[N];

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        //输入数组
        for(int i=0;i<x;i++){
            scanf("%d",&a[i]);
        }
        int re=0;
        for(int i=0;i<x;i++){
            if(a[i]%6==0){
                s[re]=a[i];
                re++;
                a[i]=0;
            }
        }
        for(int i=0;i<x;i++){
            if(a[i]!=0 && a[i]%2==0){
                s[re]=a[i];
                re++;
                a[i]=0;
            }
        }
        int re2=x-1;
        for(int i=0;i<x;i++){
            if(a[i]!=0 && a[i]%3==0){
                s[re2]=a[i];
                re2--;
                a[i]=0;
            }
        }
        for(int i=0;i<x;i++){
            if(a[i]!=0 && re2>=re){
                s[re]=a[i];
                re++;
                a[i]=0;
            }
        }
        for(int i=0;i<x;i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/

//D. Palindromex
//D. 回文最大 mex

//了你一个由 2n 个整数组成的数组 a
//每个是 0-（n-1）每个出现两次

//任务
//该子数组是一个回文
//mex定义为没有出现在数组中的最小非负整数 0-n 
//mex范围 0-n


//输出 任意回文子数组的最大 mex 值
//最小的k使得数字k的两个位置之间的区间包含了某个数字j<k的两次出现中的一次

//每个数字恰好出现两次，
//因此任何偶数长度的回文子数组
//必定以某个数字的两个出现位置为端点。
//我们需要检查这些区间是否为回文。
/*
#include <iostream>
using namespace std;
//要求最大mex的回文子数组
const int N=1e6;
int a[N],s[N],w[N];

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        for(int i=0;i<2*x;i++){
            scanf("%d",&a[i]);
        }
        
    }
    return 0;
}
*/
//贪心 没有非常简单的数学方法，但可以通过栈匹配和贪心在 O(n) 内解决

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(2*n);
        for(int i=0;i<2*n;++i) cin>>a[i];

        vector<int> first(n,-1),last(n,-1);
        for(int i=0;i<2*n;++i){
            if(first[a[i]]==-1) first[a[i]]==i;
            else last[a[i]]=i;
        }
        int ans=1;
        int L=first[0],R=last[0];
        for(int i=1;i<n;++i){
            int l=first[i],r=last[i];
            if(l<L && r<R){
                ++ans;
            }else{
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}