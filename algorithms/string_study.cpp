//字符串的学习
//两种风格， C-style string / string库

//string 定义
/*#include <iostream>
using namespace std;

int main(){
    char dog[8]={'b','e','a','u','x',' ','i','i'};    //not a string //without '\0'
    char cat[8]={'f','a','t','e','x','x','a','\0'};   //a string!
    printf("%c\n",dog[7]);
    printf("%c\n",cat[6]); //这段代码演示了C风格字符串的常见错误，导致未定义行为，最终输出“Hb”只是巧合。
    cout << dog <<endl;   //输出beaux iiH��  最后'H'之后的是内存里面随后的各个字节解释为要打印的字符
    cout << cat <<endl;
    return 0;
}*/

//这里有一种更方便的方法 将字符数组初始化为字符串
/*#include <iostream>
using namespace std;
// c++ 对字符串的长度没有限制    注意在 char max='A'; //is fine  
                                   // char max="A"; //is wrong
int main(){
    char brid[11]="Mr.Cheeps"; //the '\0' is understood
    char fish[]="Bubbles";  //let the compiler count 让编译器自动计算数组或字符串的大小
    cout << brid <<endl;
    cout << fish <<endl;
    return 0;
}*/

//strlen() 语法    strings.cpp -- strong strings in an array
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    const int Size=15;
    char name1[Size];               //empty array
    char name2[Size]="c++isgood";   //initialized array 已初始化的数组 
    //Note: some imle
    return 0;
}
