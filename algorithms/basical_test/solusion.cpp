//组合方案
//魔法竹 健身房 - 101350D

/*
证明 你的思路正确：只需要判断所有 h_i 的奇偶性是否相同（也就是所有相邻差都是偶数）。

理由：
一次操作会使每根竹子的高度奇偶性都翻转，所以任意两根竹子高度之差的奇偶性永远不变。最终相等时高度差为 0（偶数），因此初始任意两根高度差必须为偶数，即所有 h_i 同奇偶。
反过来，如果所有 h_i 同奇偶，可以通过每次推当前最高的竹子等方法把差值调节为 0，所以条件充分。

*/

/*
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n-1);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int w=0;
        for(int i=0;i<n-1;i++){
            b[i]=a[i+1]-a[i];
            if(b[i]%2!=0){
                w=1;
            }
        }
        if(w){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}*/

//F - 食品采购 CodeForces - 1296B 
/*分析，要让人类的花出去的钱最大化
比如 10元花出10+10*0.1的效果 10~11
那20元呢，先花10元得到1元 第二轮在画10元得到1元 一共是22元
但是一起花呢，花20元得到2元 一共22元，一样的

区别在于，28元，分整数花，回报2元 之后10元变成11元 一共花成31元效果
那么 37——41
199 先花100 回10元再花100 回10元 再花10回1 再花10回1 一共221 花去的加上最后回的

从高到低，依次累加，对每次花出去的金额求和，加上最后一次回的
*/
//方法一 公式法
/*
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        long long ans=0;
        ans=s+(s-1)/9;
        cout<<ans<<endl;
    }
    return 0;
}*/
/*方法二，进行模拟
每次花掉最大的 10 的倍数
（即 s / 10 * 10），返现 s / 10，更新余额，
直到余额小于 10，最后把剩余的钱全部花掉。
*/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long s=0,ans=0;
        cin>>s;
        while(s>=10){
            long long spend=(s/10)*10;
            ans+=spend;
            s=s-spend+spend/10;
        }
        ans+=s;
        cout<<ans<<endl;
    }
    return 0;
}

//I - Assigning to Classes CodeForces - 1300B 
