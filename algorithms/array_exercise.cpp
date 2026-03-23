//工艺品制作
//简单的题可以用三维布尔数组模拟切割过程
/*#include <iostream>
#include <cmath>
using namespace std;
//长方体 w,x,h
//建立一个三维长方体数组
int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);  //确定有"1"的区域
    int a[30][30][30]={0};  //整一大块是有实际数字
    //初始化
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int w=0;w<z;w++){
                a[i][j][w]=1;
            }
        }
    }
    //切几刀
    int q=0;
    int an=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x1,x2,y1,y2,z1,z2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
        // 转换为 0‑based 索引
        x1--; y1--; z1--;
        x2--; y2--; z2--;
        for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            for(int w=z1;w<=z2;w++){
                a[i][j][w]=0;
                an++;
            }
        }
    }
    }
    int sum=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int w=0;w<z;w++){
                if(a[i][j][w]==1){
                    sum++;
                }
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}*/

//彩票摇奖
//数组存储中奖的七位数
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[7];
    for(int i=0;i<7;i++){
        scanf("%d",&a[i]);
    }
    int re[7]={0};
    while(n--){
        int q[7];   //一张彩票的数字
        int sum=0;
        for(int i=0;i<7;i++){
            scanf("%d",&q[i]);
            for(int j=0;j<7;j++){
                if(a[j]==q[i]){
                    sum++;
                    break;
                }
            }
        }
        if(sum!=0){
            re[sum-1]++;    //注意这里需要累加计数，可以两张彩票同时中一种奖
        }
    }
    for(int i=6;i>=0;i--){
        printf("%d",re[i]);
        if(i>0){
            printf(" ");
        }
    }
    return 0;
}