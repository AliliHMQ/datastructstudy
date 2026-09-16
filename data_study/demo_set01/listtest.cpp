//顺序表程序训练

/*
#include <iostream>
using namespace std;
#define MAXSIZE 1000010

typedef struct{
    ElemType *elem;                  //❌未定义ElemType
    int length;
}sqlist;

void initlist(sqlist &l){
    l.elem=new ElemType[MAXSIZE];
    l.length=0;
}

void insert(sqlist &list,int x,int l){
    list.elem[l-1]=x;                 //❌每次更新并没有增加长度逻辑不完整
}

int find(sqlist &list,int p){
    return list.elem[p-1];
}

int main(){
    int N,n;
    cin>>N>>n;
    initlist(sqlist);              //❌严重错误，将定义的数据类型当作变量
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        insert(sqlist,x,i+1);
    }
    while(n--){
        int y;
        cin>>y;
        cout<<find(sqlist,y)<<'\n';
    }
    return 0;                      //❌ new了新的内存但是没有delete
}
*/


#include <iostream>
using namespace std;
#define MAXSIZE 2000005

typedef struct{
    int *elem;                       //实际元素的位置，类似数组，可以用下标索引，模拟数组。
    int length;
}sqlist;

void initlist(sqlist &l){
    l.elem=new int[MAXSIZE];        //这时，系统在堆区分配了一块连续的、能装下 MAXSIZE 个整数的内存，并把这大块内存的第一个字节的地址（首地址）交给了 elem。
    l.length=0;
}

void insert(sqlist &list,int x,int l){
    list.elem[l-1]=x;
    list.length++;                    //加长度
}

int find(sqlist &list,int p){
    return list.elem[p-1];
}

int main(){
    int N,n;
    cin>>N>>n;
    sqlist list;
    initlist(list);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        insert(list,x,i+1);
    }
    while(n--){
        int y;
        cin>>y;
        cout<<find(list,y)<<'\n';
    }
    //删除
    delete[] list.elem;          //对应new的语法
    return 0;
}

/*
手动内存管理：你使用了 new int[] 和 delete[] list.elem;，这完全符合 C 风格顺序表（动态数组）的标准实现，真正做到了自己管理内存。

封装思想：你把 initlist、insert、find 分离开，这就是数据结构中抽象数据类型（ADT）的思想——将数据的存储和操作分离。

随机访问：find 函数里直接用 list.elem[p-1] 返回，体现了顺序表最核心的优势：时间复杂度 O(1) 的随机访问。
*/

/*
图例

【栈区 或 全局区】                    【堆区 (Heap)】
sqlist 结构体变量                     连续的内存块（底层数组）
+----------------+                  +------+------+------+------+------+
|  int *elem     | ---------------> | elem |      |      |      |      | ...
|                |    (首地址)      | [0]  | [1]  | [2]  | [3]  | [4]  |
+----------------+                  +------+------+------+------+------+
|  int length    |                  ^
| (当前长度)      |                  |
+----------------+                  |
                                   首地址指向这里
*/

//顺序表
#include <bits/stdc++.h>
using namespace std;

using ElemType = int;        // 按题目改，比如 char、long long
const int MaxSize = 100010;  // 按题目改

struct SqList {
    ElemType data[MaxSize];
    int length;
};

// 初始化
void InitList(SqList &L) {
    L.length = 0;
}

// 求长度
int Length(const SqList &L) {
    return L.length;
}

// 按位查找：第 i 个，1-based，用 e 返回
bool GetElem(const SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    return true;
}

// 按值查找：返回第一次出现的位置，1-based；找不到返回 0
int LocateElem(const SqList &L, ElemType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

// 插入：在第 i 个位置插入 e，1-based
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= MaxSize) return false;

    // 从后往前搬，腾出位置
    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;
    ++L.length;
    return true;
}

// 删除：删除第 i 个元素，用 e 返回被删值，1-based
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;

    e = L.data[i - 1];

    // 从前往后搬，覆盖被删位置
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }

    --L.length;
    return true;
}

// 遍历输出
void PrintList(const SqList &L) {
    for (int i = 0; i < L.length; ++i) {
        cout << L.data[i] << ' ';
    }
    cout << '\n';
}

//单链表
#include <bits/stdc++.h>
using namespace std;

using ElemType = int;  // 按题目改

struct LNode {
    ElemType data;
    LNode *next;
};

using LinkList = LNode*;  // 单链表类型

// 初始化：带头结点
bool InitList(LinkList &L) {
    L = new LNode;
    if (L == nullptr) return false;
    L->next = nullptr;
    return true;
}

// 头插法建表：a[0..n-1]，结果会逆序
void CreateListHead(LinkList &L, ElemType a[], int n) {
    InitList(L);
    for (int i = 0; i < n; ++i) {
        LNode *s = new LNode;
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

// 尾插法建表：a[0..n-1]，结果保持原顺序
void CreateListTail(LinkList &L, ElemType a[], int n) {
    InitList(L);
    LNode *r = L;  // r 指向尾结点

    for (int i = 0; i < n; ++i) {
        LNode *s = new LNode;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

// 按位查找：返回第 i 个结点，1-based
// i = 0 返回头结点；失败返回 nullptr
LNode *GetElem(LinkList L, int i) {
    if (i < 0) return nullptr;

    LNode *p = L;
    int j = 0;

    while (p != nullptr && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}

// 按值查找：返回第一个值为 e 的结点
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}

// 插入：在第 i 个位置插入 e，1-based
bool ListInsert(LinkList &L, int i, ElemType e) {
    LNode *p = GetElem(L, i - 1);  // 找第 i-1 个结点
    if (p == nullptr) return false;

    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除：删除第 i 个结点，用 e 返回，1-based
bool ListDelete(LinkList &L, int i, ElemType &e) {
    LNode *p = GetElem(L, i - 1);  // 第 i-1 个结点
    if (p == nullptr || p->next == nullptr) return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

// 遍历输出
void PrintList(LinkList L) {
    for (LNode *p = L->next; p != nullptr; p = p->next) {
        cout << p->data << ' ';
    }
    cout << '\n';
}

// 销毁
void DestroyList(LinkList &L) {
    while (L != nullptr) {
        LNode *p = L;
        L = L->next;
        delete p;
    }
}

//双链表
#include <bits/stdc++.h>
using namespace std;

using ElemType = int;  // 按题目改

struct DNode {
    ElemType data;
    DNode *prior;
    DNode *next;
};

using DLinkList = DNode*;  // 双链表类型

// 初始化：带头结点
bool InitDLinkList(DLinkList &L) {
    L = new DNode;
    if (L == nullptr) return false;
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

// 按位查找：返回第 i 个结点，1-based
// i = 0 返回头结点；失败返回 nullptr
DNode *GetElem(DLinkList L, int i) {
    if (i < 0) return nullptr;

    DNode *p = L;
    int j = 0;

    while (p != nullptr && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}

// 在 p 结点之后插入 s
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == nullptr || s == nullptr) return false;

    s->next = p->next;
    if (p->next != nullptr) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 在 p 结点之前插入 s
bool InsertPriorDNode(DNode *p, DNode *s) {
    if (p == nullptr || s == nullptr) return false;

    s->prior = p->prior;
    if (p->prior != nullptr) {
        p->prior->next = s;
    }
    s->next = p;
    p->prior = s;
    return true;
}

// 插入：在第 i 个位置插入 e，1-based
bool ListInsert(DLinkList &L, int i, ElemType e) {
    DNode *p = GetElem(L, i - 1);  // 第 i-1 个结点
    if (p == nullptr) return false;

    DNode *s = new DNode;
    s->data = e;
    return InsertNextDNode(p, s);
}

// 删除 p 的后继结点
bool DeleteNextDNode(DNode *p) {
    if (p == nullptr || p->next == nullptr) return false;

    DNode *q = p->next;
    p->next = q->next;
    if (q->next != nullptr) {
        q->next->prior = p;
    }
    delete q;
    return true;
}

// 删除：删除第 i 个结点，用 e 返回，1-based
bool ListDelete(DLinkList &L, int i, ElemType &e) {
    DNode *p = GetElem(L, i);
    if (p == nullptr || p == L) return false;  // 不删头结点

    e = p->data;

    p->prior->next = p->next;
    if (p->next != nullptr) {
        p->next->prior = p->prior;
    }

    delete p;
    return true;
}

// 尾插法建表
void CreateDListTail(DLinkList &L, ElemType a[], int n) {
    InitDLinkList(L);

    DNode *r = L;  // r 指向尾结点
    for (int i = 0; i < n; ++i) {
        DNode *s = new DNode;
        s->data = a[i];
        s->prior = r;
        s->next = nullptr;
        r->next = s;
        r = s;
    }
}

// 正向遍历
void PrintDList(DLinkList L) {
    for (DNode *p = L->next; p != nullptr; p = p->next) {
        cout << p->data << ' ';
    }
    cout << '\n';
}

// 反向遍历
void PrintDListReverse(DLinkList L) {
    if (L == nullptr) return;

    DNode *p = L;
    while (p->next != nullptr) {
        p = p->next;
    }

    for (; p != L; p = p->prior) {
        cout << p->data << ' ';
    }
    cout << '\n';
}

// 销毁
void DestroyDList(DLinkList &L) {
    while (L != nullptr) {
        DNode *p = L;
        L = L->next;
        delete p;
    }
}
//P1996 约瑟夫问题        

//P1160 队列安排

