/*  预习程序
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

//定义顺序表，课本24页 
typedef struct 
{
	int *elem;
    int length;
}SqList;

//初始化顺序表， 课本26页 
Status InitList(SqList &L)	
{
	L.elem=new int[MAXSIZE];
	if(!L.elem) return OVERFLOW;
    L.length=0;
    return OK;                       //必须存在一个返回值 OK
}


//顺序表输入 
void ListInput(SqList &L, int n)			
{//顺序表数据的输入
    for (int i = 0; i <= n-1; i++) {
        cin >> L.elem[i];
    }
    L.length = n;
}

//取值操作，课本26页  
Status GetElem(SqList L, int i, int &e)			
{
    if(i<1 || i>L.length) return ERROR;

    e=L.elem[i-1];

    return OK;
	
}

//查找操作，课本26页  
int LocateElem(SqList L, int e)				
{
	for(int i=0;i<L.length;i++){
        if(e==L.elem[i]){
            return i+1;
        }
    }
    return 0;
}

//插入操作，课本28页  
Status ListInsert(SqList &L, int i, int e)				
{
    //判错
    if((i<1) || (i>L.length+1)) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    //第i个位置插入e(索引是i-1)
    for(int j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

//顺序表输出 
void ListOutput(SqList L)						
{
	int i;
	for (i = 0; i <= L.length-1; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

//线性表的合并（顺序表），课本41页  
void MergeList(SqList &LA, SqList LB)					
{
    //去重
    int m=LA.length;
    int n=LB.length;
    for(int i=1;i<=n;i++){
        int e;
        GetElem(LB,i,e);
        if(!LocateElem(LA,e)){
            ListInsert(LA,++m,e);
        }
    }
}												

int main()
{
    SqList LA, LB;
    int n, m;
    InitList(LA);
    InitList(LB);
    cin >> n;
    ListInput(LA, n);
    cin >> m;
    ListInput(LB, m);
    MergeList(LA, LB);
    ListOutput(LA);
    return 0;
}

*/

//自主编写
#include <bits/stdc++.h>
#define MAXSIZE 100005
using namespace std;

//建顺序表
struct sqlist{
    int *elem;
    int length;
};

//初始化
void initlist(sqlist &L){
    L.elem=new int[MAXSIZE];
    L.length=0;
}

//初始化顺序表
void listinsert(sqlist &L,int n){
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        L.elem[i]=x;
        L.length++;
    }
}

//查找元素函数
int findelem(sqlist &L,int &e){
    for(int i=0;i<L.length;i++){
        if(e==L.elem[i]){
            return 1;
        }
    }
    return 0;
}

//加入元素函数
void insertelem(sqlist &L,int x){
    L.elem[L.length]=x;
    L.length++;
}

//合并函数
void unionlist(sqlist &LA,sqlist &LB){
    int m=LA.length;
    int n=LB.length;
    for(int i=0;i<n;i++){
        if(!findelem(LA,LB.elem[i])){
            insertelem(LA,LB.elem[i]);
        }
    }
}

int main(){
    sqlist LA,LB;
    int n,m;
    
    cin>>n;
    initlist(LA);
    listinsert(LA,n);
    
    cin>>m;
    initlist(LB);
    listinsert(LB,m);
    
    unionlist(LA,LB);
    
    for(int i=0;i<LA.length;i++){
        cout<<LA.elem[i]<<" ";
    }
    cout<<'\n';
    
    delete[] LA.elem;
    delete[] LB.elem;

    return 0;
}