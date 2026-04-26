//2026.4.26
//高精度算法
//c++要求高  （√）
//两个大数相加减
 

//A+B   1e6
//A-B   1e6
//A*a  len(A)<=1e6 a<=1000
//A/a

//1、如何存储大的数
//利用数组存 大整数 个位存在 a[0];

//2、如何运算
//模拟人为竖式加减法
/*
    a[3]a[2]a[1]a[0]
  + b[3]b[2]b[1]b[0]
                c[0]
*/
//进位为 t
//c[i]=a[i]+b[i]+t;



//***加法高精度模板***
#include <iostream>
#include <vector>  //自带一个 size 函数表示一个数组的长度
using namespace std;

const int N=1e6+10;  //题目的数据范围 （习惯）
//写工程需要能省空间就省，算法的话快一点就行

//add函数 返回值是数组
//高精度函数，模拟加法
vector<int> add(vector<int> &A,vector<int> &B) //直接传入A,B不需要再开空间去复制了
{
    //输出答案C
    vector<int> C;

    //
    int t=0; //累加器
    for(int i=0;i<A.size() || i<B.size();i++){
        //t是三个数累加和 其中某位两数之和
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10); //与A、B存储方式相同
        t/=10;  //进位
    }
    //如果最高位还有进位 补上一个1 注意这里需要检验!
    if(t) C.push_back(1); //最后补上 1
    return C;
}

int main(){
    //字符串进来
    string a,b;
    vector<int> A,B;

    cin >> a >> b; // a="123456"
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');  //整数存进去 //A=[6,5,4,3,2,1]
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');  //整数存进去 
    
    //auto 编译器自己换判断出来是 vector<int>
    auto C=add(A,B);

    //输出倒着输出
    for(int i=C.size()-1;i>=0;i--){
        cout << C[i];
    }

    return 0;
}

/*
相加部分加到最高位的那个数
换成：
    if(A.size()<B.size()) return add(B,A);
    int t=0;
    //这样循环
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
*/


//***减法***
/*
    A>=B的 模拟人类算法
    当 A-B >=0 函数算（A-B）
    当 A-B <0  函数算（B-A）之后求负值 最高位不借位，省去边界判断

    a[2]a[1]a[0]
-   b[2]b[1]b[0]
            c[0]

    c[i]=a[i]-b[i]-t; t代表着是否借位
    //是否借位
    c[i]>=0 下一个t=0;
    c[i]<0 则c[i]=a[i]-b[i]-t+10; t=1;
*/

#include <iostream>
#include <vector>
using namespace std;

const int N=1e6+10;

//判断是否有 A>=B
bool cmp(vector<int> &A,vector<int> &B){
    //位数不相同
    if(A.size()!=B.size()) return A.size()>B.size();

    else{
        bool t=1;  //设定A>=B输出 真
        //高位开始比
        for(int i=A.size()-1;i>=0;i--){
            if(B[i]>A[i]){
                t=0;
                break;
            }
            /*
            if(A[i]!=B[i]){
                return A[i]>B[i];
            }
            return true;
            */
        }
        return t;
    }
}


vector<int>sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()) t-=B[i];
        //添加两种情况
        if(t<0){
            C.push_back(t+10);
            t=1;
        }else{
            C.push_back(t);
            t=0;
        }
        //或者这样合二为一判断
        /*
        C.push_back((t+10)%10);
        if(t>=0) t=0;
        else t=1;
        */
    }
    //返回时去掉前导0 例如123-120=003(C的位数和A设置的一样)变成3 这样用 while
    while(C.size()>1 && C.back()==0) C.pop_back(); //删掉后面的0
    return C;
}


//主函数不变
int main(){
    //字符串进来
    string a,b;
    vector<int> A,B;

    cin >> a >> b; // a="123456"
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');  //整数存进去 //A=[6,5,4,3,2,1]
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');  //整数存进去 
    
    //答案
    vector<int> C;

    //auto 编译器自己换判断出来是 vector<int>
    //这里需要实现判断问题
    if(cmp(A,B)) {
        C=sub(A,B); 
        //自己是实现判断
    }
    else C=sub(B,A);

    //输出倒着输出
    for(int i=C.size()-1;i>=0;i--){
        cout << C[i];
    }

    return 0;
}


//上面的似乎拥有问题
/*
#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector <int> &A,vector <int> &B){ // 判断是否A ≥ B
    if(A.size() != B.size()) return A.size() > B.size(); // 如果A、B长度不相同，长度长的那个数大
    for(int i = A.size() - 1;i >= 0;i --){ // 否则就要从最高位开始看（因为执行这个函数前，A和B数组都已经倒序，所以这里要从后往前看）
        if(A[i] != B[i]) return A[i] > B[i]; // 如果A的当前位和B的当前位不相等，当前位大的更大
    }
    return true; // 如果A、B数组都相等，这里可以直接返回true，当然也可以直接输出0
}
vector <int> sub(vector <int> &A,vector <int> &B){ // A - B
    int t = 0; // 每一位上相减得到的数
    vector <int> C; // 最后的答案
    for(int i = 0;i < A.size();i ++){ // 遍历一遍，和高精度加法不一样的是，只要遍历完A就行了，因为这里A肯定比B长
        t = A[i] - t; // t要等于A的当前位减掉自己，因为上一位有可能出现借位的情况
        if(i < B.size()) t -= B[i]; // 如果没有遍历完B，那么t减掉B的当前位
        C.push_back((t + 10) % 10); // 更新C数组
        // 这里如果没有借位，(t + 10) % 10就刚好等于t
        // 如果这里有借位，(t + 10) % 10就会借一个10下来
        if(t < 0) t = 1; // 如果t < 0，说明不够减，需要借位，把t赋值为1，就是在下一次执行中，A的当前位会减掉t
        else t = 0; // 否则够减，赋值为0，不用借位
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back(); // 删除前导0
    return C; // 返回答案
}
int main(){
    string a,b; // 两个数，因为很大，所以用string来存
    cin>>a>>b; // 读入
    vector <int> A,B; // 两个数，因为减法是从最低位开始减，我们可以把两个数倒过来
    for(int i = a.size() - 1;i >= 0;i --) A.push_back(a[i] - '0'); // 把a数组到过来存入A，记得a是string类型的数组，要减去'0'让它变成数字
    for(int i = b.size() - 1;i >= 0;i --) B.push_back(b[i] - '0'); // 把b数组倒过来存入B
    if(cmp(A,B)){ // 如果A > B
        auto C = sub(A,B); // 那么可以直接相减
        for(int i = C.size() - 1;i >= 0;i --) printf("%d",C[i]); // 最后因为C是倒着的，需要反向输出
    }
    else{ // 否则A < B，需要计算-(B - A)
        auto C = sub(B,A); // 计算B - A
        printf("-"); // 给前面加上一个负号
        for(int i = C.size() - 1;i >= 0;i --) printf("%d",C[i]); // 反向输出C数组
    }
    return 0;
}

作者：洛喑
链接：https://www.acwing.com/solution/content/126786/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

//乘法都话也是一样的
