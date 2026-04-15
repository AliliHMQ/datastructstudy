//structur.cpp --a simple structue
/*
#include <iostream>
using namespace std;

struct inflatable //sturcture declaration
{
    char name[20];
    float volume;
};   //Don't forget that!

int main(){
    inflatable guest=
    {
        "Alice Brice",  //Here is ' , '
        1.88   //Here is nothing!
    };
    cout << "This is your name "<< guest.name << endl;
    cout << guest.volume <<endl;
    return 0;
}
*/


//assgn_st.cpp  //结构体同类型的赋值
//arrstruc.cpp //数组存储在结构体里面

#include <iostream>
using namespace std;

struct influatable     //定义一个结构体
{
    char name[20];
    float volum;
    double price;
};

int main(){
    influatable guests[2]=  //initializing an arry of structs
    {
        {"Ana",0.5,21.99},
        {"Gima",0.4,565.99}
    };
    cout << "The guests " << guests[0].name << " and " << guests[1].name 
        <<"\nhave a combined volume of "
            <<guests[0].volum + guests[1].volum << endl;
    return 0;
}