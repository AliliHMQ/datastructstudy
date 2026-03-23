//冒泡排序
#include <iostream>
using namespace std;

int main(){
    int q[100],i,j,n;
    scanf("%d",&n);
    //输入
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    //冒泡排序核心
    for(int i=0;i<n-1;i++){     //n个数排序进行 n-1 趟
        for(int j=0;j<n-i;j++){ //n个数进行 n-1 次选择判断
            if(q[j]>q[j+1]){
                int t=q[j];       //进行两个数交换而不改变数组里面的值
                q[j]=q[j+1];
                q[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",q[i]);
        if(i<n-1){
            printf(" ");
        }
    }

    return 0;
}