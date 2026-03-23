// 1、数组重排
/*#include <iostream>
using namespace std;

long long main(){
    long long a[3];
    for(long long i=0;i<3;i++){
        cin >> a[i];
    }
    prlong longf("%d %d %d",a[2],a[0],a[1]);
    return 0;
}*/

//构造回文数，26个小写字母，最多26*2=52个数

/*#include <iostream>
using namespace std;

long long main(){
    char str1[27]="abcdefghijklmnopqrstuvwxyz";
    //char str2[27]="abcdefghijklmnopqrstuvwxyz";
    long long n;
    scanf("%d",&n);
    for(long long i=0;i<n;i++){
        long long x;
        scanf("%d",&x);
        if(x<=52){
           /*for(long long j=0;j<x;j++){
               prlong longf("%c",str1[i]);
           }
           for(long long j=0;j<x;j++){
               prlong longf("%c",str2[i]);
           }
           prlong longf("\n");
           //先判断奇数与偶数
           if(x%2==0){
            for(long long j=0;j<x/2;j++){
               prlong longf("%c",str1[j]);
           }
           for(long long j=x/2-1;j>=0;j--){
               prlong longf("%c",str1[j]);
           }
           prlong longf("\n");
           }else{
            for(long long j=0;j<x/2+1;j++){
               prlong longf("%c",str1[j]);
           }
           for(long long j=x/2-1;j>=0;j--){
               prlong longf("%c",str1[j]);
           }
           prlong longf("\n");
           }
        }else{
            prlong longf("No\n");
        }
    }

    return 0;
}*/

//且所有字符都互不相同的仅由小写字母组成的回文串 只有 "a";
/*#include <iostream>
using namespace std;

long long main(){
    long long T;
    cin >> T ;
    while(T--){
        long long x;
        cin >> x;
        if(x==1){
            prlong longf("a\n");
        }else{
            prlong longf("No\n");
        }
    }
    return 0;
}*/

//设计 奇数偶数判断
/*#include <iostream>
using namespace std;

const int Mod=998244353;

long long jiecheng(int n,int x){
    long long re=1;
    for(int i=n;i>=n-x;i--){
        re*=i;
    }
    return re;
}

int  main(){
    long long j=0;
    long long o=0;
    long long q=0; //'?'个数    long long n;
    long long n;
    cin >> n;
    long long odd=(n+1)/2;
    long long even=n/2;
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        if(x=='j'){
            j++;
        }else if(x=='o'){
            o++;
        }else{
            q++;
        }
    }
    long long re=0;
    if(j<=odd && o<=even){
        re=jiecheng(odd,j)*jiecheng(even,o)*jiecheng(n-j-o,0) % Mod;
        printf("%lld",re);
    }else{
        printf("0\n");
    }

    return 0;
}*/

/*#include <iostream>
using namespace std;

const int Mod=998244353;

long long jiecheng(int n,int x){
    long long re=1;
    for(int i=0;i<x;i++){          // 循环 x 次，计算 n*(n-1)*...*(n-x+1)
        re = re * (n - i) % Mod;
    }
    return re;
}

int main(){
    long long j=0;
    long long o=0;
    long long q=0; //'?'个数
    long long n;
    cin >> n;
    long long odd=(n+1)/2;
    long long even=n/2;
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        if(x=='j'){
            j++;
        }else if(x=='o'){
            o++;
        }else{
            q++;
        }
    }
    long long re=0;
    if(j<=odd && o<=even){
        re = jiecheng(odd,j) * jiecheng(even,o) % Mod; //取两次模（其实每次乘法后都取模）是为了在计算过程中始终将数值控制在模数范围内，避免溢出
        re = re * jiecheng(n-j-o, n-j-o) % Mod;   // 剩余数字全排列
        printf("%lld\n",re);
    }else{
        printf("0\n");
    }

    return 0;
}*/

//取中位数
#include <iostream>
using namespace std;

const int N=1e5+10;
int q[N];

void merge_sort(int q[],int l,int r){
    int tmp[N];
     if(l>=r) return;
     int mid=(l+r)>>1;
     merge_sort(q,l,mid);
     merge_sort(q,mid+1,r);
     int k=0,i=l,j=mid+1;
     while(i<=mid && j<=r){
        if(q[i]<=q[j]){
            tmp[k++]=q[i++];
        }else{
            tmp[k++]=q[j++];
        }
     }
    while (i<=mid) tmp[k++] = q[i++];
    while (j<=r) tmp[k++] = q[j++];
    for(int i=l,j=0;i<=r;i++,j++){
        q[i]=tmp[j];
     }
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    merge_sort(q,0,n-1);
    int pos=(n-1)/2;   //中位数的指针
    int median=q[pos];

    int L=0,R=0;
    for (int i=0;i<n;i++) {
        if (q[i]<median) L++;
        else if (q[i]>median) R++;
    }

    if (L==0 && R==0) {
        printf("-1\n");
        return 0;
    }

    int ans = n;
    if (L>0) ans=min(ans,n-2*L);
    if (R > 0) ans=min(ans,n-2*R+1);

    printf("%d\n",ans);

    return 0;
}

//每日一题，稳定子数组，寻找到最大连续一组的子数组
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int * a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n==1){
        cout << 1 <<endl;
        return 1;
    }
    int left=0,right=1,ans=0;
    while(left<n){
        while(left<n && abs(a[right]-a[right-1])<=1){
            right++;
        }
        ans=max(ans,right-left);
        left=right;
        right++;
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")