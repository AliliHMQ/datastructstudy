//二分查找
#include <iostream>
using namespace std;

//二分查找，在已知 一维数组 里面寻找 目标数的位置
int binary_search(int q[],int l,int r,int target){
    while(l<=r){
        int mid=(l+r) >> 1;
        if(q[mid]==target){
            return mid;
        }else if(q[mid]>target){        // 这里因为 mid 不 可 能 是 答 案 了 ， 所 以 搜 索 范 围 都 需 要 将 mid 排除
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    int a[101];
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    int re=binary_search(a,0,n-1,x);
    printf("%d",re);
    return 0;   
}

