

//2 进击的奶牛
//贪心+二分
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long> &place,long long k,int x){
    long long con=1;   //第一个位置放牛
    long long last=0;
    for(int i=0;i<place.size();i++){
        if(place[i]-place[last]>=x){          //隔着x远处放下一头牛
            con++;
            last=i;
            if(con>=k) return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> place(n);
    for(long long &x:place) cin>>x;
    sort(place.begin(),place.end());

    long long l=0,r=place[n-1]-place[0];
    long long re=0;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(place,m,mid)){
            re=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<re<<endl;
    return 0;
}




//C - 一元三次方程求解
/*
给出该方程中各项的系数（a,b,c,d均为实数），并约定该方程存在三个不同实根（根的范围在 −100至 100之间），且根与根之差的绝对值 ≥1。
*/


#include <iostream>
using namespace std;

bool check(double mid,double a,double b,double c,double d){
    return a*mid*mid*mid+b*mid*mid+c*mid+d-0;
    
}

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    double l=-100,r=100;
    double re1=r;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2.0;
        if(check(mid,a,b,c,d)==0){
            l=mid;
            re1=mid;
            cout<<re1<<endl;
        }else{
            r=mid;
        }
    }

    return 0;
}


/* 一元三次 */
/*这段代码主要的问题在于
 “端点根”的重复处理和浮点数误判，
会导致输出的根数量可能超过 3 个，或者把不是根的点当成根。
*/

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

double f(double mid,double a,double b,double c,double d){
    return a*mid*mid*mid+b*mid*mid+c*mid+d;
}

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    set<double> re;
    const double eps=1e-9;

    if (fabs(f(-100, a, b, c, d)) < eps) re.insert(-100);
    if (fabs(f(100, a, b, c, d)) < eps) re.insert(100);

    for(int i=-100;i<100;i++){           //根的范围[-100, 100]
        double fi=f(i,a,b,c,d);
        double fi1=f(i+1,a,b,c,d);

        // 若端点本身是根，直接插入（避免重复，set会自动去重）
        if (fabs(fi)<eps) {
            re.insert(i);
        }
        if (fabs(fi1)<eps) {
            re.insert(i+1);
        }
        if(fi*fi1<eps){
            if(f(i,a,b,c,d)*f(i+1,a,b,c,d)<0){
                double l=i,r=i+1;
                /*
                for(int j=0;j<100;j++){
                    double mid=(l+r)/2.0;
                    if(f(mid,a,b,c,d)*f(r,a,b,c,d)<0){        //不要用 f(mid) * f(l) < 0，而是用 f(mid) * f(r) < 0 或者更稳健地用 f(mid) 与 f(l) 异号判断，但允许等于 0 时直接返回 mid。
                        l=mid;
                    }else{
                        r=mid;
                    }
                }*/
                for (int j=0;j<200;j++) {
                    double mid=(l+r)/2.0;
                    double fm=f(mid,a,b,c,d);
    
                    // 如果 mid 恰好是根（或足够接近），直接锁定
                    if(fabs(fm)<1e-7) {
                        l=r=mid;
                        break;
                    }
    
                    // 正常异号判断：fm 与 f(l) 同号则移动左边界，否则移动右边界
                    if (fm*f(l,a,b,c,d)>0) 
                        l=mid;
                    else 
                        r=mid;
                }
                re.insert((l+r)/2.0);
            }
        }
    }
    int con=0;
    for (auto it=re.begin();it!=re.end() && con<3;++it) {
        printf("%.2f ", *it);
    }
    return 0;
}

////依旧是无法通过 嗯 那我们先学一学暴力枚举！
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
   double a,b,c,d;
   scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
   for(double i=-100;i<=100;i+=0.001)
   {
      double j=i+0.001;
      double y1=a*i*i*i+b*i*i+c*i+d;
      double y2=a*j*j*j+b*j*j+c*j+d;
      if(y1>=0&&y2<=0||y1<=0&&y2>=0)     //f[x0]*f[x1]<0
      {
         double x=(i+j)/2;
         printf("%.2lf ",x);
      }
   }
}

/*D 借教室*/
//处理接下来 n 天的借教室信息
//借教室的原则是先到先得，
//也就是说我们要按照订单的先后顺序依次为每份订单分配教室。

//现在我们需要知道，是否会有订单无法完全满足。
//如果有，需要通知哪一个申请人修改订单。

//好实现的算法：差分数组

/*
代码核心：

for(int i=1;i<=n;i++)
{cin>>a[i];sum[i]=sum[i-1]+a[i];}
for(int i=1;i<=q;i++)
{cin>>l>>r;cout<<sum[r]-sum[l-1]<<" ";}

而所谓的差分数组，即是前缀和数组的逆运算：
我们给定前i个数相邻两个数的差（1<=i<=n）,求每一项a[i]（1<=i<=n）。
此时无非就是用作差的方式求得每一项，此时我们可以有一个作差数组diff，
diff[i]用于记录a[i]-a[i-1],然后对于每一项a[i],我们可以递推出来：

for(int i=1;i<=n;i++)
{cin>>diff[i];a[i]=diff[i]+a[i-1];}
for(int i=1;i<=n;i++)
{cout<<a[i];}

到这儿，我们可以看出来，前缀和是用元数据求元与元之间的并集关系，
而差分则是根据元与元之间的逻辑关系求元数据，是互逆思想
（qwq但是有时元数据和关系数据不是很好辨别或者产生角色反演啊）

而对于能否二分，有一个界定标准：
状态的决策过程或者序列是否满足单调性或者可以局部舍弃性。
这一题前者有一个不满足后续直接可以不考虑

首先，要明白如为什么要用区间差分而不是区间前缀和：
因为这个题每次操作针对的对象都是原本题目中给的元数据，而不是让求某个关系，所以采用差分。

其次，要知道差分会起到怎样的作用：
因为diff数组决定着每个元数据的变化大小、趋势，所以，当我们想要针对区间操作时，钱可以转化成对diff数组操作：

diff[l[i]]+=d[i];
diff[r[i]+1]-=d[i];//d[i]是指每天要借的教室数
*/

//diff、need、d 等数组用了 int，累加时会溢出。

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
long long diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];

bool isok(int x){
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++){
        diff[l[i]]+=d[i];   //?
        diff[r[i]+1]-=d[i];
    }
    need[0]=0;
    for(int i=1;i<=n;i++){
        need[i]=need[i-1]+diff[i];
        if(need[i]>rest[i]) return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&rest[i]);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int begin=1,end=m; 
    if(isok(m)){cout<<"0";return 0;}
    while(begin<end)
    {
        int mid=(begin+end)/2;
        if(isok(mid))begin=mid+1;
        else end=mid;
    }
    cout<<"-1"<<endl<<begin;
}




