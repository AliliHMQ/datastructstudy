//STL库学习

//1.容器

//种类

/*
    1.vector 类  矢量
    1.1对vector进行操作
        size(),begin(),end(),push_back(),erase(),insert()

    2.什么是堆（Heap）？
    堆是一种特殊的完全二叉树数据结构，它满足以下性质：
    priority_queue 就是C++对堆的实现：
    完全二叉树：除了最后一层，其他层都是满的，最后一层节点靠左排列
    堆序性：父节点和子节点之间有特定的大小关系

*/

//2.迭代器

/*
    1.输入迭代器，输出迭代器，正向迭代器，双向迭代器，随机访问迭代器

    迭代器类型	    支持的操作	                                                示例容器
    输入迭代器	    只读、单向移动	                                           istream_iterator
    输出迭代器	    只写、单向移动	                                           ostream_iterator
    前向迭代器	    ++p, p++, *p, ==, !=, 复制赋值	                           forward_list
    双向迭代器	    前向迭代器全部功能 + --p, p--	                            list, set, map
    随机访问迭代器	双向迭代器全部功能 + p+=i, p-=i,  p+i, p[i], <, >, p2-p1	vector, deque

    
    stack 和 queue 没有迭代器，只能通过成员函数访问元素
    不同容器返回的迭代器类型不同，影响可用的算法
    


*/

//3.函数对象

//4.算法


//练习


/*P1996 约瑟夫问题*/
/*
1.从第一个人开始报数,数到 m 的人出列
2.再由下一个人重新从 1 开始报数，数到 m 的人再出圈
3.直到所有的人都出圈，请输出依次出圈人的编号

quene 队列模拟

队列是先进先出（FIFO）结构。
约瑟夫问题中，每次报数到k的元素出列，
其余元素重新加入队尾，模拟"围成一圈报数"的场景

“未被选中的元素会在下一圈判断能否被选中，相当于未被选中的放在了队列最后，选中直接弹出，直到没有元素为止
*/

/*
1.从第一个人开始报数,数到 m 的人出列
2.再由下一个人重新从 1 开始报数，数到 m 的人再出圈
3.直到所有的人都出圈，请输出依次出圈人的编号

队列是先进先出（FIFO）结构。约瑟夫问题中，
每次报数到k的元素出列，其余元素重新加入队尾，模拟"围成一圈报数"的场景
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;

    queue<int> people;
    for(int i=1;i<=n;i++){
        people.push(i);
    }

    while(!people.empty()){
        for(int i=1;i<m;i++){     //报数到k-1
            people.push(people.front()); //只是读取队首的值，并将其追加到队列末尾
            people.pop(); //删除队首
        }
        cout<<people.front()<<" ";       //.front()弹出队首 .back()弹出队尾 但是没有删除，只是复制了
        people.pop();                    //这里才是删除.pop()
    }

    return 0;
}
/*std::queue 天生不支持索引（没有 [] 或 at()），因为它是容器适配器，设计初衷就是先进先出（FIFO），只允许操作队头和队尾。*/




/*3. stack 栈应用
推荐题目：洛谷P1449「后缀表达式」
该题练习栈的表达式求值，核心操作是 push()、top()、pop()。*/

/*
式中不再引用括号，运算符号放在两个运算对象之后，
所有计算按运算符号出现的顺序

严格地由左而右新进行（不用考虑运算符的优先级）。
3*(5-2)+7 对应的后缀表达式为：3.5.2.-*7.+@

@ 为表达式的结束符号。. 为操作数的结束符号。

后缀表达式（逆波兰表达式）中，
操作数在前，运算符在后。
遇到数字入栈，遇到运算符则弹出栈顶两个数运算，
结果再入栈。最终栈顶即为结果
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> number;
    char c;
    int a=0;

    while(cin>>c){
        if(c=='@') break;
        if(c>='0'&& c<='9'){
            a=a*10+(c-'0');
        }else if(c=='.'){
            number.push(a);
            a=0;
        }else{
            int n1=number.top();number.pop();   //除数...算式里面第二个数
            int n2=number.top();number.pop();
            if(c=='+') number.push(n2+n1);
            else if(c=='-') number.push(n2-n1);
            else if(c=='*') number.push(n2*n1);
            else if(c=='/') number.push(n2/n1);
        }
    }
    cout<<number.top()<<endl;
    return 0;
}
/*采取了计算机知识，选取用stack存储数据(在不考虑没有括号，没有运算符优先级的情况下)*/





/*4. sort + set 去重排序
推荐题目：洛谷P1059「明明的随机数」

该题练习 set 的自动去重排序，以及 sort 的应用*/

/*
请你协助明明完成“去重”与“排序”的工作。
表示所生成的随机数的个数 N，得到从小到大排好序的不相同的随机数
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    set<int> num;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        num.insert(x);                 //加入的时候就已经完成了去重与排序
        /*
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        */
    }
    cout<<num.size()<<endl;
    for(int x:num) cout<<x<<" ";
    return 0;
}


//P5266 【深基17.例6】学籍管理
/*map是一种描述“对应关系”的存储结构，就像函数一样*/

/*
这个题通过审题可以发现，
每一个string的学号对应一个int的分数，
这样的话，这题简直就是为map量身定制的啊
*/

/*根据map一一对应的性质进行操作，添加删除什么的*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> a;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x==1){
            string n;
            cin>>n;
            int s;
            cin>>s;
            a.insert({n,s});             //insert添加的是一对pair
            //a[n]=s; 同理
            cout<<"OK"<<endl;
        }else if(x==2){
            string n;
            cin>>n;
            if(a.count(n)){
                cout<<a[n]<<endl;          //极为快速的根据首元的寻找
            }else{
                cout<<"Not found"<<endl;
            }
        }else if(x==3){
            string n;
            cin>>n;
            if(a.count(n)){
                a.erase(n);                  //删除以n为名的一整个节点
                cout<<"Deleted successfully"<<endl;
            }else{
                cout<<"Not found"<<endl;
            }
        }else{
            cout<<a.size()<<endl;            //依旧是大小
        }
        
    }
    return 0;
}

/*  摘苹果问题
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<int, int> mp;  // 高度 -> 苹果数量
    
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        mp[h]++;  // 统计每个高度的苹果数
    }
    
    while (q--) {
        int a;
        cin >> a;
        cout << mp[a] << endl;  // 输出该高度苹果数
        mp[a] = 0;  // 摘完后清零
    }
    return 0;
}
*/





/*6. priority_queue 优先队列
推荐题目：洛谷P1090「合并果子」

该题练习贪心算法与 priority_queue 小根堆的应用。*/

/*想到前缀和 但是不妙超时了*/
//前缀和? 不对，最优策略是每次选择当前所有堆中重量最小的两堆合并
//哈夫曼树

/*错误
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sumre=0;

    vector<int> a(n);
    vector<int> sum(n);
    for(int &x:a) cin>>x;
    sort(a.begin(),a.end());

    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }

    for(int i=1;i<n;i++){
        sumre+=sum[i];
    }
    cout<<sumre<<endl;
    return 0;
}*/

//使用优先队列（小根堆）模拟哈夫曼合并过程：

/*
priority_queue<int, vector<int>, greater<int>> pq;  // 注意这里的 >> 在 C++11 后是合法的，不会被认为是右移

greater<int> 是一个函数对象（仿函数），表示“大于”的比较。
它等价于一个函数 bool operator()(int a, int b) { return a > b; }。
所以当把它作为参数传递给容器或算法时，
会**按降序（从大到小）**排列元素（默认的 less<int> 是升序，从小到大）。
*/

/*只要时刻记住队列里装的永远是“待合并的堆”，就不会再犯这类错误了。👍*/

//嗯对，确实是逻辑错误了，
//每次求和都是累成一堆，不能是ans不然会越来越多

/*
而且按果子的不同种类分成了不同的堆
每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。

使多多耗费的体力最少，并输出这个最小的体力耗费值。
*/

//使用优先队列（小根堆）模拟哈夫曼合并过程：
//每次合并最小的两堆果子，消耗体力最小

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    priority_queue<int, vector<int>, greater<int>> pq;  //从小到大哦

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    int ans=0;
    while(pq.size()>1){
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        int sum=a+b;
        ans+=sum;
        pq.push(sum);         //合并过后的一堆放进总和
    }
    cout<<ans<<endl;
    return 0;
}








//********************* test **************************//

/*A - 小鱼的数字游戏 洛谷 - P1427 */

/*
1.一行内输入一串整数，以 0 结束，以空格间隔。
2.一行内倒着输出这一串整数 长度不一定
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    int x;  
    while(cin>>x){
        if(x==0) break;
        a.push_back(x);
    }
    for(int i=(int)a.size()-1;i>=0;i--){   //当 a 为空时，a.size()-1 是无符号数
        cout<<a[i]<<" ";
    }
    return 0;
}


/* B - Increasing CodeForces - 1742B */

/*
给定一个由 n 个正整数组成的数组 a。通过重新排列元素，确定是否可以使数组严格递增
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;
        sort(a.begin(),a.end());
        
        int re=0;
        for(int i=1;i<n;i++){
            if(a[i-1]==a[i]){
                re=1;
                break;
            }
        }
        if(!re){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}




/*C - Number Replacement CodeForces - 1744A */

/* 
小提示：要建立数字和字符的一一映射关系，可以使用map<int, char>
*/

//那就边输入边加入pair吧

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        map<int,char> m;
        for(int &x:a) cin>>x;
        string s;
        cin>>s;
        
        int re=0;
        for(int i=0;i<n;i++){
            int num=a[i];
            char c=s[i];
            if(m.count(num)){
                if(m[num]!=c){
                    re=1;
                    break;
                }
            }else{
                m[num]=c;
            }
        }

        if(re){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}




/*D - Ten Words of Wisdom CodeForces - 1850B */

/*
只能拿重量小于等于10的神剑
想要尽可能拿走神力高的

结构体排序，

然后是n行，其中的i行包含两个整数ai和bi（1 ≤ ai, bi ≤ 50）--分别是第i把剑的重量和神力
*/

//方法一 直接遍历
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=-1,shen=-1;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(x<=10){
                if(y>shen){
                    shen=y;
                    ans=i;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

//训练方法 map


/*E - Array Coloring CodeForces - 1857A */

/*
给定一个由n个整数组成的数组
您的任务是确定是否有可能以两种颜色为其所有元素上色，
从而使两种颜色的元素的和具有相同的奇偶性，
并且每种颜色至少有一个元素上色。

奇+奇=偶
偶+偶=偶 奇+偶=奇  偶数不影响奇偶性

数组分为两组 每组之和奇偶性相同 
小提示：判断奇数偶数个数就行

奇数个奇数 绝对不可能分好
偶数个奇数 可以分好

奇数个偶数的话 加到两边不影响奇偶性
偶数个偶数的话 加到两边更加不影响奇偶性
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int x=0;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            if(num%2!=0){
                x++;
            }
        }
        if(x%2!=0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}



/*F - Is It a Cat? CodeForces - 1800A */

/*
字符串 "meow", "mmmEeOWww", "MeOooOw" 描述的是一只猫在喵喵叫
判断你听到的声音是一只猫在喵喵叫还是其他什么声音。

小提示：把一个字符转换为小写可以使用tolower()函数。在本题中，连续相同的字符会干扰我们的判断。
想想办法把mmmmmeeeeoowww化成简单的meow。
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> a(n);
        
        for(char &x:a) cin>>x;
        for(int i=0;i<n;i++){
            a[i]=tolower(a[i]);         //转换成大写
        }
        a.erase(unique(a.begin(),a.end()),a.end());
        string res;
        for(int i=0;i<a.size();i++){
            res+=a[i];
        }
        string s1="meow";
        if(res==s1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}




/*G - Parity Sort CodeForces - 1851B */

/*
特殊排序
将两个元素 ai 和 aj 对调，使得 i ≠ j、ai 和 aj 要么都是偶数，要么都是奇数

确定是否有可能通过执行任意次数（可能为零）的操作对数组进行
非递减排序。 递增排序

我知道，分三组 原数组排序得到第一组 
偶数组排序得到第二组 奇数组排序得到第三组 
但是要放回去看看是否一致
*/

/*
更进一步 你可以这样思考

复制原数组，排序得到 b。
依次比较每个位置：
如果 a[i] 是奇数，但 b[i] 是偶数，就失败。
如果 a[i] 是偶数，但 b[i] 是奇数，也失败。

全部通过就输出 YES，否则 NO。         好聪明，性质一致也是一种很好的判断方式1，相较于细节化地考虑操作步骤，只看变化前后两个状态就能完成判断最厉害了
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;

        vector<int> b(n);
        for(int i=0;i<n;i++){
            b[i]=a[i];
        }
        sort(a.begin(),a.end());
        int re=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=b[i]%2){
                re=1;
                break;
            }
        }
        if(!re){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}




/*H - Balanced Round CodeForces - 1850D */

/*
1.按顺序排列才能使最后的差值均为最小 
之后再和k进行比较遇到第一个大于k的差值对左右两边的数数目计算 
去掉最短的一列 如果一直没有，就输出0

但关键问题是：最终能保留的数，只能来自某一个连续段，而不是在每个裂缝处二选一。
找最长连续段，而不是每次遇到裂缝就累加删除数
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<int> a(n);
        //vector<int> b(n);

        for(int &x:a) cin>>x;
        sort(a.begin(),a.end());

        /*
        for(int i=1;i<n;i++){
            b[i]=a[i]-a[i-1];
        }*/

        int re=0;
        int len=1;
        int maxlen=1;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=k){
                len++;
            }else{
                if(len>maxlen){
                    maxlen=len;
                }
                len=1;              //重置为1
            }
        }
        //循环结束后处理最后一段len
        maxlen=max(maxlen,len);

        if(maxlen==n){
            re=0;
        }else{
            re=n-maxlen;
        }
        cout<<re<<endl;
    }

    return 0;
}