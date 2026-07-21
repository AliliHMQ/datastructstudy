//首字母大写
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    while(getline(cin,a)){
        int x=a.size();
        a[0]=a[0]+'A'-'a';
        for(int i=1;i<x;i++){
            if(a[i-1]==' '){
                a[i]=a[i]+'A'-'a';
            }
        }
        cout<<a<<endl;
    }
    return 0;
}