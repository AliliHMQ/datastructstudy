//A
/*
单调stack模板
*/

/*
首先我们要明白，我们存放的是下标。
然后，我们直接把元素放在栈顶，会破坏它的单调性。
所以我们需要吐出栈顶的元素，使得我们当前的元素再加进去不会破坏它的单调性。
*/

#include <bits/stdc++.h>
using namespace std;
int a[30000005],ans[30000005];
stack<int> s;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+1);
    }
    for(int i=n;i;i--){
        while(s.size() && a[s.top()]<=a[i]){
            s.pop();
        }
        ans[i]=s.size()?s.top():0,s.push(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans);
    }
    return 0;
}

//anthor ai 解释
#include <cstdio>

const int MAXN = 3000005;
//栈（stk 数组）中存储的就是数组 a 的下标（索引），而不是具体的数值。
int a[MAXN], stk[MAXN], ans[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int top = 0; // 栈顶指针（指向栈中下一个空位）
    
    // 从右向左扫描
    for (int i = n; i >= 1; i--) {
        // 维护单调递减栈：栈顶元素如果 <= 当前值，就不可能成为更左边元素的答案，直接弹出
        while (top > 0 && a[stk[top - 1]] <= a[i]) {
            top--;
        }
        
        // 栈若为空，说明右边没有更大的；否则栈顶下标就是答案
        ans[i] = (top == 0) ? 0 : stk[top - 1];
        
        // 当前下标入栈
        stk[top++] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    
    return 0;
}


//左侧第一个比它大的，从左往右遍历
//右侧第一个比它大的，从右往左遍历



//从右往左构造（取决于你想要单调递增数列）
/*
#include <bits/stdc++.h>
using namespace std;

const int N=3e6+5;
int a[N],ans[N];
stack<int> s;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }

    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i]){  //弹出所有比要加入的元素小的
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top();   //符合不为stack底就有满足要求的下标
        s.push(i);
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
*/
//Time Limit Exceeded
//输入数据太多

#include <bits/stdc++.h>
using namespace std;

const int N=3e6+5;
int a[N],ans[N];
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }

    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i]){  //弹出所有比要加入的元素小的
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top();   //符合不为stack底就有满足要求的下标
        s.push(i);
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}



//B - 求数列所有后缀最大值的位置

//输出一位所有后缀最大值的下标的按位异或和。
//右边有一位比它小的

/*
就是这个数字右边没有比它还大的数了，收集它的下标
*/
//什么东西，逻辑不通
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long a[N],ans[N];
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()]<=a[i]){
            ans[i]^=s.top();
            s.pop();
        }
        s.push(i);
        if(!s.empty()) ans[i]^=s.top();
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//题解


/*
#include<bits/stdc++.h>
#define int unsigned long long
#define mod 90007
#define inf 0x7fffffff

using namespace std;
int n;
struct node{
	int x,y;
}a[3000000];//创建数组，x为数字，y为下标
stack<node>s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=i; //下标为输入时的顺序
	}
	int v=1;
	int ans=0;
	while(v<=n){ //v==n时最后一个元素还没有入栈，所以v=n+1时才能退出
		while(!s.empty()&&s.top().x<=a[v].x){
			ans^=s.top().y; //出栈时异或
			s.pop(); //维护栈的单调性，小于她的都出栈
		}
		s.push(a[v]); //入栈
		ans^=a[v].y; //异或新入栈的
		cout<<ans<<'\n'; //输出答案
		v++; //准备下一个下标
	}
}

*/


/*F - Patrik 音乐会的等待*/
//写一个程序计算出有多少对人可以互相看见。几对人
//维护一个严格递减（从栈底到栈顶）的栈，
//栈里存储的是人的下标，
//同时保证这些人的身高严格递减（相等时会被合并）。
//维护一个严格递减（从栈底到栈顶）的栈，栈里存储的是人的下标，同时保证这些人的身高严格递减（相等时会被合并）。
/*
#include <bits/stdc++.h>
using namespace std;
long long n,s[500010],a[500010],top,sum,same[500010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<"第"<<i<<"次寻找："<<'\n';
        while(top>0&&a[i]>=a[s[top-1]]){
            cout<<"出现大于等于顶部的元素"<<" ";
            if(a[i]==a[s[top-1]]){
                cout<<"出现加入元素等于stack顶部元素"<<" ";
                same[i]=same[s[top-1]]+1;
                cout<<"出现相同的数"<<same[i]<<" ";
            }
            sum++;
            sum+=same[s[top-1]];
            top--;
            cout<<"本轮答案1是"<<sum<<" ";
        }
        if(top>0) sum++;
        s[top++]=i;
        cout<<"本轮答案2是"<<sum<<'\n';
    }
    cout<<sum;

    return 0;
}
*/