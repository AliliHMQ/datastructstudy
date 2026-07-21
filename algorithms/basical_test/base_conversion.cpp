//除基取余

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int a;
    int R;
    while(cin>>a>>R){
        if(a<0){              //判断负数
            a=-a;
            cout<<"-";
        }

        vector<char> re;      //结果

        if(a==0){
            printf("0\n");
            continue;
        }

        while(a>0){
            int t=a%R;
            if(t<10) re.push_back('0'+t);
            else re.push_back('A'+(t-10));
            a/=R;
        }
        for(int i=re.size()-1;i>=0;i--){
            printf("%c",re[i]);
        }
        printf("\n");
    
    }
    return 0;
}