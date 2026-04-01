//指针动态分配内存
#include <iostream>
using namespace std;

/*int main(){
    int *p=new int;
    *p=10;
    cout <<"动态（手动）分配了4个字节的内存存储了：" <<*p << endl;
    delete p;
    return 0;
}*/

int main(){
    int *p=new int[10];
    //说实话这样写非常无聊喵，一个一个加进去
    /**p=1;
    *(p+1)=2;*/

    for(int i=0;i<10;i++){
        *(p+i)=i;
    }
    //cout << *p <<" " << *(p+1) << endl; 
    for(int i=0;i<10;i++){
        cout << *(p+i) << endl;
    }
    delete p;
    return 0;
}