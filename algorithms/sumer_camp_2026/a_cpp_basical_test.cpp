
/******** A 大数之和 ********/

/*
意味着你不应该用32位整数来处理它们。你可以假设每个整数的长度不会超过1000。
2
1 2
112233445566778899 998877665544332211
*/

//解题代码 高精度加法 STL vector 存储
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> add(vector<int> &A,vector<int> &B){
	vector<int> C;
	if(A.size()<B.size()) return add(B,A);
	int t=0;
	for(int i=0;i<A.size();i++){
		t+=A[i];
		if(i<B.size()){
			t+=B[i];
		}
		C.push_back(t%10);
		t/=10;
	}
	if(t){
		C.push_back(1);
	}
	return C;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		string a,b;
		cin>>a>>b;
		vector<int> A,B,C;
		for(int i=(int)a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
		for(int i=(int)b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
		
		C=add(A,B);

		printf("Case %d:\n", j + 1);
        cout << a << " + " << b << " = ";
        for (int i=C.size()-1;i>=0;i--) printf("%d",C[i]); 
        printf("\n");

        // 两个测试用例之间输出一个空行（最后一个不输出）
        if (j!=n-1) printf("\n");
	}
	return 0;
}




/******** B - 进制转换 HDU - 2031 ********/

/*
输入一个十进制数N，将它转换成R进制数输出。
*/

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




/********* C - 回文_easy版本 HDU - 2029 ************/

/*
如果一个字符串是回文串，则输出"yes",否则输出"no
*/

#include <iostream>
#include <string>   // 必须包含
#include <cstdio>   // 若使用 printf 则必须包含
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int x=a.size();
        int j=x-1;
        int re=0;
        for(int i=0;i<x;i++){
            if(a[i]==a[j]){
                re=0;
            }else{
                re=1;
                break;
            }
            j--;
        }
        if(re){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    
    return 0;
}




/************ D - 魔法竹 健身房 - 101350D **************/

/*
最初，第i根竹子的高度等于hi。在一个动作中，
你可以把一根竹子推下去，让它的高度降低一根，但这个动作神奇地让其他所有竹子都增加了一根。
如果你能做任意多的动作，能让所有竹子高度都一样吗？
*/

/*
证明 你的思路正确：只需要判断所有 h_i 的奇偶性是否相同（也就是所有相邻差都是偶数）。

理由：
一次操作会使每根竹子的高度奇偶性都翻转，所以任意两根竹子高度之差的奇偶性永远不变。最终相等时高度差为 0（偶数），因此初始任意两根高度差必须为偶数，即所有 h_i 同奇偶。
反过来，如果所有 h_i 同奇偶，可以通过每次推当前最高的竹子等方法把差值调节为 0，所以条件充分。

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int first;
        cin >> first;
        int parity = first & 1;         //储存第一次的奇偶性
        bool ok = true;

        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            if ((x & 1) != parity) ok = false;    //存在与第一个不同的既不可能实现
        }

        cout << (ok ? "yes" : "no") << '\n';
    }
    return 0;
}




/************** E - 首字母变大写 HDU - 2026 ***************/

/*
输入一个英文句子，将每个单词的第一个字母改成大写字母。
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    while(getline(cin,a)){
        int x=a.size();
        a[0]=a[0]+'A'-'a';
        for(int i=1;i<x;i++){
            if(a[i-1]==' '){
                a[i]=a[i]+'A'-'a';
            }
        }
        cout<<a<<endl;
    }
    return 0;
}




//F - 食品采购 CodeForces - 1296B 
/*分析，要让人类的花出去的钱最大化
比如 10元花出10+10*0.1的效果 10~11
那20元呢，先花10元得到1元 第二轮在画10元得到1元 一共是22元
但是一起花呢，花20元得到2元 一共22元，一样的

区别在于，28元，分整数花，回报2元 之后10元变成11元 一共花成31元效果
那么 37——41
199 先花100 回10元再花100 回10元 再花10回1 再花10回1 一共221 花去的加上最后回的

从高到低，依次累加，对每次花出去的金额求和，加上最后一次回的
*/
//方法一 公式法
/*
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        long long ans=0;
        ans=s+(s-1)/9;
        cout<<ans<<endl;
    }
    return 0;
}*/
/*方法二，进行模拟
每次花掉最大的 10 的倍数
（即 s / 10 * 10），返现 s / 10，更新余额，
直到余额小于 10，最后把剩余的钱全部花掉。
*/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long s=0,ans=0;
        cin>>s;
        while(s>=10){
            long long spend=(s/10)*10;
            ans+=spend;
            s=s-spend+spend/10;
        }
        ans+=s;
        cout<<ans<<endl;
    }
    return 0;
}



/************* G - Yet Another Walking Robot CodeForces - 1296C ****************/

/*
这个优化预算很低，所以你需要移除最短的非空子串，
The value r−l+1 should be minimum possible.
最短字串，遇到UD/DU 或者 LR/RL直接出答案 //遇到 LURD LDRU RULD RDLU 同样 // LLUURRDD也行
*/
//但是怎么判断找出子串能够相互抵消的一串？
//pair+map解决

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;

        map<pair<int,int>,int> left; //子串l坐标
        left[{0,0}]=0; //原点初始化

        int x=0,y=0;
        int ansl=-1,ansr=-1;
        int best=n+1;

        for(int i=0;i<=n;i++){
            char c=s[i-1];  //从后往前开始记录走法
            if(c=='L') x--;
            else if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='R') x++;

            pair<int,int> cur={x,y};

            auto it=left.find(cur);

            if(it!=left.end()){ //在遍历完之前就已经找到了一个一样的坐标位置
                int l=it->second+1;
                int r=i;
                int len=r-l+1;

                if(len<=n-1){  //判断子串长度，随便选一个要小于原来字符串长度
                    best=len;
                    ansl=l;
                    ansr=r;
                }
            }
            left[cur]=i; //添加进去 这一点坐标对应的字符串序号
        }
        if(ansl==-1){
            cout<<-1<<endl;
        }else{
            cout<<ansl<<' '<<ansr<<endl;
        }
    }
    return 0;
}


/*************** H - 非零 CodeForces - 1300A ********************/

/*
他们需要做多少步
才能使数组中所有元素的和和乘积都与零不同？
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z=0,sum=0,re=0;
        cin>>n;

        vector<int> a(n);
        for(auto &x:a) cin>>x;

        for(int i=0;i<n;i++){
            if(a[i]==0){
                z++;
            }
            sum+=a[i];
        }
        if(sum==0){
            if(z==0){
                re=1;
            }else{
                re=z;
            }
        }else{
            if(z+sum==0){
                re=z+1;
            }else{
                re=z;
            }
        }
        cout<<re<<endl;
    }
    return 0;
}




/*************** I - 分配到班级 CodeForces - 1300B ********************/
/*
班级的技能水平为该班级学生技能水平的中位数。
你希望选择使两个班级技能水平之差的绝对值最小的一种分配。
你能达到的技能水平最小可能绝对差值是多少？

每组n个数，n为奇数选择a[n-1]和a[n]差值
n为偶数 选择 a[n-2]-a[n-1]和a[n-1]-a[n]最小值

不对 结论：统一取排序后中间两个数的差即可。
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(2*n);
        for(auto &x:a) cin>>x;
        sort(a.begin(),a.end());
        int re=a[n]-a[n-1];
        cout<<re<<endl;
    }
    return 0;
}

/************* J - 显示号码 CodeForces - 1295A *****************/
/*https://vjudge.net/contest/382262#problem/J*/

/*数字0-9 变成以灯为编码的数 最大数只含有数字1和7*/
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x%2==0){
            int j=x/2;
            for(int i=0;i<j;i++){
                cout<<'1';
            }
            cout<<endl;
        }else{
            
            cout<<'7';
            for(int i=0;i<(x-3)/2;i++){
                cout<<'1';
            }
            cout<<endl;
        }
    }
    return 0;
}




/*********** K - Yet Another Meme Problem CodeForces - 1288B ****************/

/*
给定两个整数 A 和 B，
计算满足以下条件的数对 (a, b) 的数量：
1≤a≤A  1≤b≤B
将 a 和 b 拼接起来得到的数==a*b+a+b

接下来每个测试用例一行，包含两个整数 
A 和 B 1≤A,B≤10^9   A B比较大了

a*(b+1)+b==ab
ab=a*10^b.size()+b
所以 b+1=10^b.size()

所以组合一共有 A*num(b)个 
找出num(b) 即 b 必须是形如 9,99,999,…9,99,999,… 的数
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long A;
        string B;
        cin>>A>>B;

        int numb=B.size()-1;     //思路没问题但是 如果B是99那应该和100一样 所以选择生成法，判断到B
        long long re=A*numb;

        cout<<re<<endl;

    }
    return 0;
}*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long A;
        long long B;
        cin>>A>>B;
        int numb=0;
        int cur=9;

        while(cur<=B){
            numb++;
            cur=cur*10+9;         //生成999类似数字 计数1~B里面类似数的个数
        }
        
        long long re=A*numb;

        cout<<re<<endl;

    }
    return 0;
}