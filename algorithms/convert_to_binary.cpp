//十进制转二进制
/*#include <iostream>
#include <bitset>    //进制转换
#include <cstring>  //字符 存
using namespace std;

int amin(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       int x;
       scanf("%d",&x);
       bitset<10> bits(x);  //进制转换
       string binStr = bits.to_string();

       char a[530000]={};
       strcpy(a,binStr.c_str()); //复制到字符数组



    }
    return 0;
}*/

//每次检查最低位是否为 1，然后右移一位，直到数字变为 0
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int sum=0;
        while(x){
            //两行代码是统计整数二进制中 1 的个数的经典方法(“按位与”就是直接操作二进制位)
            sum+=x&1;//所以 N & 1 的结果就是 N 的二进制最低位（最右边的一位）的值（0 或 1）。
            x >>=1; //将 N 的二进制表示整体向右移动一位。原来的最低位被丢弃，原来的第二位变成新的最低位
        }
        printf("%d\n",sum);
    }
    return 0;
}