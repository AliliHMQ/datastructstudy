//structur.cpp --a simple structue
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

