#include <iostream>
#include <cstring>
using namespace std;

int juge(char n){
    if(n=='e'){
        return 3;
    }else if(n=='t'){
        return 2;
    }else if(n=='c'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    //我想用全部列出来来着，感觉不太行

    //而这里的这个解释就是用到了 游戏规则比大小转化为了用差值去判断
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int a,b,c;
    a=juge(str1[0]);  //牛牛
    b=juge(str2[0]);  //牛妹
    c=a-b; //如果是1或者-3，牛牛赢，-1或者3，牛妹赢，其余情况平局
    if(c==1 || c==-3){
        printf("win\n");
    }else if(c==-1 || c==3){
        printf("lose\n");
    }else{
        printf("tie\n");
    }
    return 0;
}
// 64 位输出请用 printf("%lld")