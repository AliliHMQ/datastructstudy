//p7533 自动修正
/*
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[101];
    cin >> a;
    int x=strlen(a);
    for(int i=0;i<x;i++){
        if( a[i]>=97 && a[i]<=122){
            a[i]=a[i]-32;
        }
    }
    cout << a;
    return 0;
}

//p1914 小书童——凯撒密码
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[51];
    int n;
    cin >> n;
    cin >> a;
    int x=strlen(a);
    for(int i=0;i<x;i++){
        if(a[i]+n>122){
            a[i]=a[i]+n-26;  //减去一个 a~z 循环
        }else{
            a[i]=a[i]+n;
        }
    }
    cout << a;
    return 0;
}
*/
//P1125 [NOIP 2008 提高组] 笨小猴
#include <iostream>
#include <cstring>
using namespace std;

//质数判断函数
int panduan(int n){
    if(n==1) {
        return 0;
    }else if(n==2){
        return n;
    }else{
        int w=1;
        for(int i=2;i<n;i++){
            if(n%i==0){
                w=0;//只要不是质数就是0
                break;
            }
        }
        if(w==1){
            return n;
        }else{
            return 0;
        }
    }
    
}

int main(){
    int a[27]={0};  //桶
    
    //int x=97;
    /*for(int i=0;i<26;i++){
        a[i]=x;
        x++;
    }
    cout << a; //53个桶已经准备好*/

    char q[101];
    cin >> q;
    
    int n=strlen(q);
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(i+97==q[j]){
                a[i]++;
            }
        }
    }
    int max=0,min=0;
    int first=1;
    for(int i=0;i<26;i++){
        if(a[i]>0){
            if(first){
                max=min=a[i]; //第一个非零的桶赋值（必须进去排）
                first=0;
            }else{
                if(a[i]>max) max=a[i];
                if(a[i]<min) min=a[i];
            }
        }
        /*if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }*/
    }
    int re=panduan(max-min);
    if(re==0){
        cout << "No Answer "<<endl;
        cout << 0 << endl;
    }else{
        cout << "Lucky Word "<<endl;
        cout << re << endl;
    }
    return 0;
}