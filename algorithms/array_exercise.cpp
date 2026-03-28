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
/*#include <iostream>
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
}*/

//幻方
/*这个是一个看不懂版本
#include<bits/stdc++.h>
using namespace std;
int a[40][40];
int main(){
    int n;
	cin>>n;
	int x=1,y=n/2+1;
	for(int i=1;i<=n*n;i++){
		a[x][y]=i;
		if(x==1&&y==n)x++;
		else if(a[x-1][y+1])x++;
		else if(x==1)x=n,y++;
		else if(y==n)x--,y=1;
		else x--,y++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

*/

//幻方但简单版本     but I stil don't know!
/*#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const int M=50;
int n,rb,downb;  //rb代表右边界
int map[M][M];      //初始化数组
int stuffi,stuffj;  //填充k的位置

void calculate(int ii,int jj){
    stuffi = stuffj =0; //初始化
    if(ii == 1 && jj !=n){ //若k-1在第一行但不在最后一列
        stuffi = n;
        stuffj = jj + 1;
        return;
    }else if(jj==n && ii!=1){
        stuffi = n;

    }
}

int main(){
    
    return 0;
}*/

//数字显示屏
#include <iostream>
using namespace std;

const int n1=350,n2=6;
char q[n1][n2];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        if(x=='0'){
            q[0][0]='X';
            q[0][1]='X';
            q[0][2]='X';
            q[0][3]='.';
            q[1][0]='X';
            q[1][1]='.';
            q[1][2]='X';
            q[2][0]='X';
            q[2][1]='.';
            q[2][2]='X';
            q[3][0]='X';
            q[3][1]='.';
            q[3][2]='X';
            q[4][0]='X';
            q[4][1]='X';
            q[4][2]='X';
        }else if(x=='1'){
            q[0][0]='.';
            q[0][1]='.';
            q[0][2]='X';
            q[1][0]='.';
            q[1][1]='.';
            q[1][2]='X';
            q[2][0]='.';
            q[2][1]='.';
            q[2][2]='X';
            q[3][0]='.';
            q[3][1]='.';
            q[3][2]='X';
            q[4][0]='.';
            q[4][1]='.';
            q[4][2]='X';
        }else if(x=='2'){
            q[0][0]='X';
            q[0][1]='X';
            q[0][2]='X';
            q[1][0]='.';
            q[1][1]='.';
            q[1][2]='X';
            q[2][0]='X';
            q[2][1]='x';
            q[2][2]='X';
            q[3][0]='x';
            q[3][1]='.';
            q[3][2]='.';
            q[4][0]='X';
            q[4][1]='X';
            q[4][2]='X';
        }else if(x=='3'){
            q[0][0]='X';
            q[0][1]='X';
            q[0][2]='X';
            q[1][0]='.';
            q[1][1]='.';
            q[1][2]='X';
            q[2][0]='X';
            q[2][1]='x';
            q[2][2]='X';
            q[3][0]='.';
            q[3][1]='.';
            q[3][2]='X';
            q[4][0]='X';
            q[4][1]='X';
            q[4][2]='X';
        }else if(x=='4'){
            q[0][0]='X';
            q[0][1]='X';
            q[0][2]='X';
            q[1][0]='X';
            q[1][1]='.';
            q[1][2]='X';
            q[2][0]='X';
            q[2][1]='.';
            q[2][2]='X';
            q[3][0]='X';
            q[3][1]='.';
            q[3][2]='X';
            q[4][0]='X';
            q[4][1]='X';
            q[4][2]='X';
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3*n;j++){
            printf("%c",q[i][j]);
        }
        printf("\n");
    }
    return 0;
}