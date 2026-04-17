//取余
/*
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int w=0;  //每个数是否合适
    int a;
    cin >> a;
    int p=1;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        for(int j=x;j>0;j--){
            if(x%j>=p){ //但题目要求的是数本身严格递增，而不是余数关系。
                w++;
                p=x%j;
                break;
            }
        }
    }
    //cout << w << endl;
    if(w==n-1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long re=0; //下一个需要的最小值
    bool ok=1;
    for(int i=0;i<n;i++){
        long long a;
        cin >> a;
        //合适的贪心策略
        long long t=(a-1)/2;
        if(re<=t){
            re=re+1;
        }else if(a>=re){
            re=a+1;
        }else{
            ok=0;
            break;
        }
    }
    cout << (ok?"YES":"NO")<< endl;
    return 0;
}