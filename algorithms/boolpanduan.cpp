//如果遇到数字中含有数字 4 或数字是 4 的倍数，则跳过这个数字报下一个
#include <iostream>
using namespace std;

bool panduan(int n){        //构建 bool 判断函数 (判断是否含有数字 4)
    while(n>0){
        if(n%10==4){
            return true;
        }
        n/=10;
    }
    return false;
}

int main() {
    int n;
    cin >>n;
    for(int i=1;i<=n;i++){
        if(i%4!=0 && panduan(i)!=true){
            cout << i <<endl;
        }
    }
    return 0;
}
