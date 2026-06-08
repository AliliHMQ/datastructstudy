///P1255 数楼梯

/*
楼梯有 N 阶，上楼可以一步上一阶，也可以一步上二阶。
编一个程序，计算共有多少种不同的走法。

输入格式
一个数字，楼梯数。

输出格式
输出走的方式总数。
*/

//上楼梯
//求的是方式种类
//需要我们制作的是到达条件的步骤加一

#include <iostream>
using namespace std;


//这个递归函数完全学不懂一点好吧
long long int shushu(int n,int re,int sum){
    if(re==n) return 1; //最后一步不对                             换成if(re+1==n || re+2==n) return 1; 有灵感了
    if(n-re>=2){
        sum++;
        return sum=shushu(n-1,n-1,sum)+shushu(n-2,n-2,sum);
    }else if(n-re==1){
        sum++;
        return sum=shushu(n-1,n-1,sum);
    }else{
        return 0;
    }
}

int main(){
    int n;
    cin>> n;
    int re=shushu(n,0,0);
    cout<<re;
    return 0;
}


//思考着改了一下函数，结果超时了
//上楼梯
//求的是方式种类
//需要我们制作的是到达条件的步骤加一

#include <iostream>
using namespace std;

long long int shushu(int n,int re){
    if(re+1==n){
        re++;
        return 1;
    }else if(re+2==n){
        re+=2;
        return 1;
    }else{
        return shushu(n,re-1)+shushu(n,re-2);
    }
}

int main(){
    int n;
    cin>> n;
    int re=shushu(n,0);
    cout<<re;
    return 0;
}


//这一题当然不会是简简单单的但写一个递归函数就成了
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct numx{ // 结构体封装
	int k,num[10001]; // k表示位数，num存储每位数字，num[1]是最低位
	numx operator + (const numx x)const{ // 高精加
	    numx tmp;
	    memset(tmp.num,0,sizeof(tmp.num)); // 将答案先赋成0
	    for(int i=1;i<=max(k,x.k);i++){ // 按位相加
		    tmp.num[i]=num[i]+x.num[i];
	    }
	    for(int i=1;i<=max(k,x.k)+1;i++){ // 进位处理
		    tmp.num[i+1]+=tmp.num[i]/10;
		    tmp.num[i]%=10;
            if(tmp.num[i])tmp.k=i; // 更新最高位
	    }
	    return tmp; // 返回答案
	}
}s[150]; // 滚动处理
int main(){
	scanf("%d",&n);
    // 边界条件初始化
	s[0].num[1]=1;
    s[0].k=1; // f[0]=1
    s[1].num[1]=1;
    s[1].k=1; // f[1]=1
	for(int i=2;i<=n;i++)s[i%150]=s[(i+149)%150]+s[(i+148)%150]; // 递推，滚动处理
	for(int i=s[n%150].k;i>=1;i--)printf("%d",s[n%150].num[i]); // 从高到低按位输出
	return 0;
}
