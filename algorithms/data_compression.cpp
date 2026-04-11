//压缩技术 数据->图片
#include <iostream>
using namespace std;

const int A=220;

int main(){
    int n;
    scanf("%d",&n);
    int a[A*A]={};  //一长串数字
    int p=0;
    int cur=0;          // 当前要填充的数字，从0开始
    while(p < n*n){       // 填满为止，不固定循环次数
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            a[p++]=cur;
        }
        cur = 1 - cur;    // 交替0和1，这一步非常妙，我很喜欢
    }
     //赋值完成
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",a[i*n+j]);
        }
        printf("\n");
    }
    return 0;
}

//图片->数据

#include <iostream>
#include <string>
using namespace std;

int n,x,num=0,t=1;
string a,b;

int main(){
    cin >> b;
    n=b.size();
    cout<< n << " ";
    while(cin >> a){
        b+=a;
    }
    if(b[0]!='0') cout << "0 ";//开始时0的个数//格式问题
    for(int i=1;i<n*n;i++){
        if(b[i]==b[i-1]){
            t++;
        }else{
        cout << t <<" ";
        t=1;
        }
    }
    cout<<t;  //最后一次b[i]=b[i-1]部分计数
    return 0;
}