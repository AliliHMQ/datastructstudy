//结构体类型
//队列基本操作
#include <iostream>
using namespace std;
//定义一个结构体
struct queue
{
    int data[100];
    int head;
    int tail;
};

int main(){
    struct queue q;
    int i;
    //初始化队列
    q.head=1;
    q.tail=1;
    for(int i=1;i<=9;i++){
        //依次向队列加入9个数
        scanf("%d,&q.data[q.tail]");
        q.tail++;
    }
    while(q.head<q.tail){
        printf("%d",q.data[q.head]);//打印队首并将队首出队
        q.head++;
        //先将新队首的数添加到队尾
        q.data[q.tail];
        //再将队首出队
        q.head++;
    }
    
    return 0;
}