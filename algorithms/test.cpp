#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    //使用字符串比较 双端指针
    string name;
    for(int i=0;i<N;i++){
        char x;
        cin>>x;
        name+=x;
    }
    string result;
    int l=0,r=N-1;
    while(l<=r){                   
        string s1,s2;
        for(int i=l;i<=r;i++){
            s1+=name[i];
        }
        for(int i=r;i>=l;i--){
            s2+=name[i];
        }
        if(s1<s2){
            result+=s1[0];
            l++;
        }else{
            result+=s2[0];
            r--;
        }
    }
    for (size_t i = 0; i <result.length(); i += 80) {
        std::cout << result.substr(i, 80) << '\n';
    }
    
    return 0;
}
