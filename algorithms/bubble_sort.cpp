#include <iostream>
using namespace std;

//冒泡排序优化算法
void bubble_sort(int a[],int n){
    bool flag = true;
    while(flag){
        flag=false;
        //排n-1次
        for(int i=0;i<n-1;i++){  //每一轮比较次数固定
            if(a[i]>a[i+1]){
                flag=true;
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
}

int main()
{
    /*********Begin*********/
    //冒泡排序
    int q[10];
    for(int i=0;i<10;i++){
        scanf("%d",&q[i]);
    }
    bubble_sort(q,10);
    for(int i=9;i>=0;i--){
        printf("%d ",q[i]);
    }
    /*********End**********/
    return 0;
}