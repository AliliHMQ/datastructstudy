//H - 非零 CodeForces - 1300A 
/*
他们可以添加1对阵列中的任意元素。
*/
/*
分析，求和以及统计0的个数
1.如果求和为零 统计没有0 那么加一就可；统计有n个0，刚好加上n个一就可
2.求和不为0，主要是同时存在n个0，如果加上n和为零，那么还要加1；如果加上n和不为零，那么加上n就行（如果求和不为零，统计没有0，那么正常，n为0。）；
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z=0,sum=0,re=0;
        cin>>n;

        vector<int> a(n);
        for(auto &x:a) cin>>x;

        for(int i=0;i<n;i++){
            if(a[i]==0){
                z++;
            }
            sum+=a[i];
        }
        if(sum==0){
            if(z==0){
                re=1;
            }else{
                re=z;
            }
        }else{
            if(z+sum==0){
                re=z+1;
            }else{
                re=z;
            }
        }
        cout<<re<<endl;
    }
    return 0;
}