//二分查找
#include <iostream>
using namespace std;

//二分查找，在已知 一维数组 里面寻找 目标数的位置
int binary_search(int q[],int l,int r,int target){
    while(l<=r){
        int mid=(l+r) >> 1;
        if(q[mid]==target){
            return mid;
        }else if(q[mid]>target){
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