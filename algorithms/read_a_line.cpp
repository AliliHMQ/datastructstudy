//每次读取一行字符输入，避免成为就是有在字符串里面的两种风格只能读取一个英文单词
//第一种 cin.getline()

/*#include <iostream>
using namespace std;

int main(){
    const int N=30;
    char name[N];
    char dessert[N];

    cout <<"What's your name?\n";
    cin.getline(name,N);
    cout <<"Happy Birthday "<< name<<"! What's your favorit dessert?\n";
    cin.getline(dessert,N);
    cout <<"Here you are! "<< name<<",Get your favorit "<<dessert<<"!\n";

    return 0;
}*/

//第二种 cin.get()

#include <iostream>
using namespace std;

int main(){
    const int N=30;
    char name[N];
    char dessert[N];

    cout <<"What's your name?\n";
    cin.get(name,N);
    //吃掉换行符
    cin.get();
    cout <<"Happy Birthday "<< name<<"! What's your favorit dessert?\n";
    cin.get(dessert,N).get();  //另一种跟在后面吃掉
    cout <<"Here you are! "<< name<<",Get your favorit "<<dessert<<"!\n";

    return 0;
}