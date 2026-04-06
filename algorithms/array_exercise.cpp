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

//数字显示屏   //一起判断然后输出很奇怪//真的很奇怪
/*#include <iostream>
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
}*/

//由于每个数字对应的点阵是固定的，因此本题可以使用贪心 + 暴力解决。只需将 0∼9 中的所有整数的点阵存入数组，需要时再调用即可。
/*#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string ans[10][5]={"XXX","X.X","X.X","X.X","XXX",
				  	 "..X","..X","..X","..X","..X",
				 	 "XXX","..X","XXX","X..","XXX",
				   	 "XXX","..X","XXX","..X","XXX",
				   	 "X.X","X.X","XXX","..X","..X",
				   	 "XXX","X..","XXX","..X","XXX",
				  	 "XXX","X..","XXX","X.X","XXX",
				   	 "XXX","..X","..X","..X","..X",
				  	 "XXX","X.X","XXX","X.X","XXX",
				  	 "XXX","X.X","XXX","..X","XXX"};
//ans数组存0~9中整数相对应的点阵。
int main(){
	cin>>n>>s;
	for(int i=0;i<5;i++){//5行。
		for(int j=0;j<n;j++){//n列。
			cout<<ans[s[j]-'0'][i];//输出对应点阵。
			if(j!=n-1)cout<<".";//输出间隔符。
		}
		cout<<"\n";//换行。
	}
	return 0;//好习惯。
}*/


//求n个数的数组里面连续m个子数组最小值(数据不大(n<=3*1e3))
//竟然一遍过?!
//太神奇了，可歌可泣
//还是洛谷刷题顺啊

/*#include <iostream>
using namespace std;

int main(){
    int n=0,m=0;  //第一行输入
    scanf("%d %d",&n,&m);
    //我准备定义一份数组，一个动态计算值，一个最小容器 //1. 滑动窗口思想，O(n) 时间，O(1) 额外空间
    const int N=1e4;
    int a[N]={0};
    int sum=0,min=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        min+=a[i];
    }
    sum=min;
    for(int i=0;i<n;i++){
        //这里我怕越界，m 的倍数超过 n 就会指到不知道哪里去了，写个判断控制一下
        if(i+m<n){
            sum-=a[i];
            sum+=a[i+m];
        }

        /*sum-=a[i];
        sum+=a[i+m];*/
        /*if(sum<min){
            min=sum;
        }
    }
    printf("%d",min);
    return 0;
}*/

//数组在信息学竞赛中用处极大，希望你能掌握它的用法，在这条路上勇往直前。
//这里有一题可以使用概率论的

//基础做法
//a,b,c三个骰子，有A,B,C个面，求三个最大概率是哪个和

//1\暴力枚举
/*
#include <iostream>
using namespace std;

int main(){
    //这里使用了桶排序
    const int N=100;
    int sum[N]={};
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);  
    //等会回来再写，先打比赛
    //int sum1=0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                //sum1=i+j+k;
                sum[i+j+k]++;
            }
        }
    }
    int re1=0,re2=0;
    for(int i=3;i<=n1+n2+n3;i++){
        if(sum[i]>re1){
            re1=sum[i]; //最大次数
            re2=i;      //最终答案
        }
    }
    printf("%d",re2);
    return 0;
}

//频率估测概率
//三个独立均匀分布随机变量之和的众数出现在分布的中心区域，具体位置取决于三个面数的相对大小。
#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    //排序使 a>=b>=c。
    if(a<b)swap(a,b);
    if(b<c)swap(b,c);
    if(a<b)swap(a,b);
    if(b<=a-c+1){
        cout<<1+b+c;
    }else{
        cout<<2+a+(b-a+c-1)/2;
    }
    return 0;
}

*/

//开灯问题
//1、有一点点想法，一维bool数组，但是有一个问题在于多大呢？数据很大 long long 大的灯条！
//找了一下，这么大：
//int b[3000005]={};//0表示关，1表示开
/*
#include <iostream>
using namespace std;

int b[3000005]={};//0表示关，1表示开

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        double a;
        int t;
        cin >> a >> t;
        for(int j=1;j<=t;j++){
            if(b[int(a*(j*1.0))]==0){
                b[int(a*(j*1.0))]=1;
            }else{
                b[int(a*(j*1.0))]=0;
            }
        }
    }
    for(int i=1;;i++){
        if(b[i]==1){         //唯一亮灯就输出
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
//这里可以利用异或运算的特性：

//任何数与 0 异或结果是它本身。
//任何数与自身异或结果是 0。

//第二种做法
#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,x;
double a;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>t;
        for(int i=1;i<=t;i++){
			x=(int)floor(a*i);//a*i为当前灯的编号
			ans^=x;
		}
	}
	cout<<ans;
	return 0;
}

*/

