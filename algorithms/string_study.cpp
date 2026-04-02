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
/*#include <iostream>
#include <cstring>
using namespace std;

int main(){
    const int Size=15;
    char name1[Size];              //empty array  
    char name2[Size]="c++isgood";   //initialized array 已初始化的数组 
    char name3[Size]={};
    cin >> name1;                   
    cout << sizeof(name1) << endl;  //整个字符数组在内存里面占用的字节多少
    cout << strlen(name2) << endl;   
    name2[3]='\0';
    cout << name2 << endl;       
    cout << name3 << endl;      //这里定义的空输入的初始化，字符数组里面全是 '\0'
    return 0;
}*/

//推测甜点喜欢的交互语言沟通
#include <iostream>
using namespace std;

int main(){
    const int Arsize=20;
    char name[Arsize]; //定义用户名字
    char dessert[Arsize]; //甜点名

    //主要交互部分
    cout << "Hi!What's your name?\n";
    cin >> name; //字符数组能够通过 cin 读取整个字符串！
    cout << "Oh,I know!So,"<< name << "! what's your favorit dessert?\n";
    cin >> dessert;
    cout << "Here you are!Now I know your favorit dessert is " << dessert;  //哈哈注意这里的dessert应该是单个单词，不然只能出第一个连续的词
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[101]={};
    while(cin >> a){        //*读取整个字符串
        cout << a << endl;  
    }
    return 0;
}
