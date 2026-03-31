//指针变量的计算方式
#include <iostream>
using namespace std;
//内存地址 n*类型大小 的加减

int main(){
    int v[]={1,2,3,4,5};
    int *p=v;
    cout << "1\\" << *p << endl;
    *(p+1)=9;
    cout << "2\\" << *(p+1) << endl;

    return 0;
}