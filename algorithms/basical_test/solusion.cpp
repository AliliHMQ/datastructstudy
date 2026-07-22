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



//J - 显示号码 
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x%2==0){
            int j=x/2;
            for(int i=0;i<j;i++){
                cout<<'1';
            }
            cout<<endl;
        }else{
            
            cout<<'7';
            for(int i=0;i<(x-3)/2;i++){
                cout<<'1';
            }
            cout<<endl;
        }
    }
    return 0;
}

//I - Assigning to Classes CodeForces - 1300B 
