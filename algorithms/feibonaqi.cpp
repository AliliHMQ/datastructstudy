//现定义斐波那契数列 1<=n<=48  
//一切具有通项公式的小数据结构都可以用迭代的方式求解
/*#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1 || n==2){
        cout << "1";
        return 0;
    }
    int a=1,b=1,c=0;
    for(int i=2;i<n;i++){
         c=a+b;
         a=b;
         b=c;
    }
    cout << b <<endl;
    return 0;
} */

//二维斐波那契数列
//递推关系实际上等价于从 (1,1) 走到 (n,m) 的路径数，每次只能向下或向右走一步，且边界上的格子值均为 1。这个路径数就是组合数：
//组合数的计算利用了费马小定理求逆元，时间复杂度 O(N) 预处理，O(1) 查询。

//斐波那契循环
#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    int magic=rand()%100+1;  //0~100之间随机数

    int x=0;
    int b;
    do{
        scanf("%d",&b);
        if(b<magic){
            printf("小了\n");
            x++;
        }
        if(b>magic){
            printf("大了\n");
            x++;
        }

    }while(b!=magic);
    printf("%d次才对\n");
    return 0;
}