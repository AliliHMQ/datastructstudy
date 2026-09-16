#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using ElemType=int;

//单链表定义，课本30页 
typedef struct LNode{
    ElemType data;
    LNode *next;

}LNode,*LinkList;


//利用后插法创建单链表，课本37页 

/*
p：表示本次新创建的节点
r：表示当前链表的尾节点
*/
void CreateList_R(LinkList &L,int n){
    //加入n个数
    L=new LNode;
    L->next=NULL;              ////假设原本是 L -> 1(r) -> NULL
    LNode *r=L; //尾指针初始化
    for(int i=0;i<n;i++){
        LNode *p=new LNode;    //创建 2(p) -> NULL 一个新的节点
        cin>>p->data;           
        p->next=NULL;          // 新节点自己的 next 置空，准备当尾节点
        r->next=p;             //添加上新节点 L -> 1(r) -> 2(p) -> NULL
        r=p;                   //更新尾节点 L -> 1 -> 2(p,r) -> NULL
    }
}

//链式有序表合并，课本44页 
void MergeList(LinkList &LA,LinkList &LB,LinkList &LC){
    LinkList pa=LA->next;
    LinkList pb=LB->next;
    LC=LA;
    LinkList pc=LC;

    while(pa&&pb){
        if(pa->data <= pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    delete LB;            //释放LB头节点
}

void ListOutput(LinkList L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    LinkList La,Lb,Lc;
    int m,n,i;
    cin>>m;
    CreateList_R(La,m);
    cin>>n;
    CreateList_R(Lb,n);
    MergeList(La,Lb,Lc);
    ListOutput(Lc);
    return 0;
}