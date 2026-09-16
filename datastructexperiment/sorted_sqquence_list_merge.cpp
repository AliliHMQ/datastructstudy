#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct{
    int *elem;
    int length;
}SqList;

Status InitList(SqList &L){
    L.elem=new int[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

Status InsertList(SqList &L,int i,int e){
    if(i<1||i>L.length+1) return ERROR;
    int j;
    for(j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}

//顺序有序表合并，课本43页 
//类似于快速排序算法 双指针比较选择小的值
void MergeList(SqList LA,SqList LB,SqList &LC){
    LC.length=LA.length+LB.length;
    LC.elem=new int[LC.length];     //开新表
    int *pc=LC.elem;
    int *pa=LA.elem;
    int *pb=LB.elem;
    int *pa_last=LA.elem+LA.length-1;
    int *pb_last=LB.elem+LB.length-1;

    while((pa<=pa_last) && (pb<=pb_last)){
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }
    while(pa<=pa_last) *pc++=*pa++;     //不要遗漏最后一个
    while(pb<=pb_last) *pc++=*pb++;
    
}

void ListInput(SqList &L, int n)			
{//顺序表数据的输入
    for (int i = 0; i <= n-1; i++) {
        cin >> L.elem[i];
    }
    L.length = n;
}

void ListOutput(SqList L)						
{
	int i;
	for (i = 0; i <= L.length-1; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

int main(){
    SqList La,Lb,Lc;
    int m,n,i,e;
    InitList(La);
    InitList(Lb);
    InitList(Lc);
    cin>>m;
    ListInput(La,m);
    cin>>n;
    ListInput(Lb,n);
    MergeList(La,Lb,Lc);
    ListOutput(Lc);
    return 0;
}
