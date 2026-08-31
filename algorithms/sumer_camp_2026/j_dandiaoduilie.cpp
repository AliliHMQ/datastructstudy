//单调队列 单调stack我很迷惑 

//单调队列模板
/*
定义/清空单调队列 //需要队头队尾均可压入和弹出，如双端队列
for(int i=1;i<=n;i++)
{
  while(队列非空 && 队尾劣于当前元素i) 弹出队尾;
  队尾压入i;
  while(队列非空 && 队头超出范围) 弹出队头;
  //此时队头为最优元素，按题目需要使用
}

*/



#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int n,m;
int a[N];
int q[N];
int head,tail;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    head=1;
    tail=0;
    cout<<0<<'\n';
    for(int i=1;i<n;i++){
        while((head<=tail)&&(i-q[head]>=m)){ 
            head++;
            //cout<<"区间宽度变大为"<<i-q[head]<<"头指针变为"<<head<<" ";
        }
        while((head<=tail)&&(a[q[tail]]>=a[i])){ 
            tail--;
            //cout<<"新来的 a[i] 比队尾元素还小 尾指针变为"<<tail<<" ";
        }

        tail++;
        q[tail]=i;
        //cout<<"新下标入队"<<q[tail]<<" ";
        cout<<a[q[head]]<<'\n';
    }
    return 0;
}


//B - 单调队列 / 滑动窗口
#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int n,m;
int a[N];
int q[N];
int head,tail;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    head=1;
    tail=0;
    cout<<0<<'\n';
    for(int i=1;i<n;i++){
        while((head<=tail)&&(i-q[head]>=m)){ 
            head++;
            //cout<<"区间宽度变大为"<<i-q[head]<<"头指针变为"<<head<<" ";
        }
        while((head<=tail)&&(a[q[tail]]>=a[i])){ 
            tail--;
            //cout<<"新来的 a[i] 比队尾元素还小 尾指针变为"<<tail<<" ";
        }

        tail++;
        q[tail]=i;
        //cout<<"新下标入队"<<q[tail]<<" ";
        cout<<a[q[head]]<<'\n';
    }
    return 0;
}

//
/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=5e4+10;
vector<PII> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    // 按左端点升序排序
    sort(a.begin(),a.end());
    //初始化合并区间是第一个区间
    int curl=a[0].first;
    int curr=a[0].second;

    for(int i=1;i<n;i++){
        //cout<<"第"<<i<<"组"<<'\n';
        if(curr>=a[i].first){
            curr=max(curr,a[i].second);
            //cout<<"出现头节点小于上一次尾节点，更新尾部节点为："<<curr<<'\n';
        }else{
            //cout<<"出现头节点大于上一次尾节点 出现断层"<<curr<<'\n';
            cout<<"no"<<'\n';
            return 0;
        }
    }
    cout<<curl<<" "<<curr<<'\n';
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=5e4+10;
vector<PII> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    // 按左端点升序排序
    sort(a.begin(),a.end());
    //初始化合并区间是第一个区间
    int curl=a[0].first;
    int curr=a[0].second;

    long long ans=1;
    for(int i=1;i<n;i++){
        //cout<<"第"<<i<<"组"<<'\n';
        if(curr>=a[i].first){
            curr=max(curr,a[i].second);
            //cout<<"出现头节点小于上一次尾节点，更新尾部节点为："<<curr<<'\n';
        }else{
            //cout<<"出现头节点大于上一次尾节点 出现断层"<<curr<<'\n';
            //cout<<"no"<<'\n';
            ans++;
            curr=a[i].second;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
*/



//B 统计两次

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
struct node{
    int t,q;
}p;

int a[N],b[N],n,k;
deque<node>minn,maxn; //最小值队列 最大值队列

int main(){
    cin>>n>>k;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        node p{x,i};
        //插入新元素
        while((!minn.empty())&&minn.back().t>=x){
             minn.pop_back();
        }
        minn.push_back(p);
        while((!maxn.empty())&&maxn.back().t<=x){
            maxn.pop_back();
        }
        maxn.push_back(p);
        //队首元素弹出
        while((!minn.empty())&&minn.front().q<=i-k){
            minn.pop_front();
        }
        while((!maxn.empty())&&maxn.front().q<=i-k){
            maxn.pop_front();
        }
        //将最小值与最大值存入答案数组中 
        if(i>=k){
            a[i-k]=maxn.front().t;
            b[i-k]=minn.front().t;
        }
    }
    for(int i=0;i<=n-k;i++) cout<<b[i]<<" ";
    cout<<'\n';
    for(int i=0;i<=n-k;i++) cout<<a[i]<<" ";
    return 0;
}


//C - 逛画展
#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[2005],k,ans,l,r,ll,rr; //b[i]表示当前区间画家i的图画数

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    l=1;r=1;k=1;b[a[1]]=1;ans=1000005;

    while(l<=r&&r<=n){
        if(k==m){
            //满足要求
            if(ans>r-l+1){
                ans=r-l+1; //钱数
                ll=l;rr=r; //最小化l,r
            }
            b[a[l]]--;
            if(b[a[l]]==0) k--;
            l++;
        }
        else{
            r++;
            b[a[r]]++;
            if(b[a[r]]==1) k++;
        }
    }
    cout<<ll<<" "<<rr<<'\n';
    return 0;
}


/*
用两个变量l和r来枚举区间

如果l到r的区间不满足要求,r++

如果l到r的区间满足要求,记录答案,l++
*/

//D - 切蛋糕
//前缀和递增才会保证最大
/*
其他题解之所以会被hack是因为他们光顾着维护队列单调递增
（前缀和递增才会保证最大），忘了万一数据是单调递减怎么办。
所以我们应该在维护递增之前就判断现在的答案是否为最优。
为了达到这个目的我们应该先给队列赋初值0，因为sum[i]-sum[q.front()]这一句，
不赋初值就出bug了，正好赋初值之后就可以避免第一个值是最大的，其余都是负的（如5 2 1 -10 -10 -10 -10 -10）这种丧心病狂的数据了。
*/
/*
#include <bits/stdc++.h>
#define debug cout<<"ok"<<endl
typedef long long ll;
const int maxn=1e7+10;
const int mod=1e9+7;
using namespace std;
int ans=-233333333,n,m,a,sum[maxn];
deque<int>q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;//前缀和
    }
    q.push_back(0);//赋初值
    for(int i=1;i<=n;i++)
    {
        //cout<<"第"<<i<<"轮";
        while(q.front()+m<i)
            q.pop_front();//越界就pop
        ans=max(ans,sum[i]-sum[q.front()]);
        while(!q.empty()&&sum[q.back()]>=sum[i])//递减就pop
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",ans);
    return 0;
}
*/