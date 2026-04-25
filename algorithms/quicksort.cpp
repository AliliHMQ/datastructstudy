// Quick Sort
// 快速排序
#include <iostream>
using namespace std; 

const int N=1e6+10;
	//1e6这个表示法默认是 double 类型;
int n;
int q[N];	

void quick_sort(int q[], int l, int r)   //当数组是空的时候，可以说是一个指针； 
{
    if (l >= r) return;  //函数返回值； 

    int i = l - 1, j = r + 1, x = q[l + r >> 1]; //x = q[l + r >> 1]; 数学上等于（l+r）/2；这种写法在处理大数组时是安全的，因为 >> 1 不会像 /2 那样可能产生浮点数的问题。 
    while (i < j)
    {
        do i++; while(q[i]<x);            	 							
		//if(q[i]<x) i++;  //一次换下一个吗  不可以do-while 会连续移动指针，直到遇到不满足条件的元素（q[i] >= x 或 q[j] <= x）。
        //而 if 只移动一步（甚至不移动），无法跳过所有小于 x 的元素，导致分区后左侧仍可能有小于 x 的数，右侧仍可能有大于 x 的数。
       	do j -- ; while (q[j] > x);
        //if(q[j]>x) j--;

        if (i < j) swap(q[i], q[j]);  //前面已经判断完全部情况了
    }
    quick_sort(q, l, j);//递归//每一次的首元都会变化，解决了数组中间最小值问题； 
	quick_sort(q, j + 1, r);//左右对称； 
}

int main(){
	//int n;
    //int q[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&q[i]);
	} 
	quick_sort(q,0,n-1);
	
	for(int i=0;i<n;i++){
		printf("%d ",q[i]);
	}                                                                                                                                                                                                                                                                                                                                            
	return 0;
}

//快速排序求第 k 个数
#include <iostream>
using namespace std;

const int N=1e5+10;
int a[N];

void quick_sort(int q[],int l,int r,int k){
    if(l>=r) return;
    int i=l-1;
    int j=r+1;
    int x=q[(l+r)/2];
    while(i<j){
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    if(k>j){
        quick_sort(q,j+1,r,k);
    }else{
        quick_sort(q,l,j,k);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    quick_sort(a,0,n-1,k-1);
    cout << a[k-1] << " ";
    
}