//13


//02
//最大可行，用两层
//第二层都变为0

#include <iostream>
#include <math.h>
using namespace std;

const int N=1e6+10;

int main(){
    long long a[N],re[N],x[N];
    int n;
    int w=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n-1;i++){   //第一层
        re[i]=a[i+1]-a[i];
    }
    long long min=a[1]-a[0];
    for(int i=0;i<n-2;i++){   //第二层
        x[i]=re[i+1]-re[i];
        if(x[i]){
            w=1;
        }
        if(x[i]<min){
            min=x[i];
        }
    }
    if(!w){
        printf("-1\n");     //全为0
    }else{
        long long re0=abs(min);        //最大公因数
        int an=0;                //是否全部整除
        for(long long i=min;i>=1;i--){
            for(int j=0;j<n-2;j++){
             if(x[j]%i!=0){
                  an=1;
                  break;
             }
            }
            if(!an){
                re0=i;
                break;
            }
        }
     printf("%lld",re0);
    }
    return 0;
}

//走迷宫
#include <iostream>
#include <math.h>
using namespace std;

const int N=1010;

int main(){
    int a,b;
    int x1,y1,x2,y2;
    char n[N][N];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%c",&n[i][j]);
            if(n[i][j]=='S'){
                x1=i;y1=j;
            }
            if(n[i][j]=='T'){
                x2=i;y2=j;
            }
        }
    }
    int re=0;
    int re0=abs(x1-x2)+abs(y1-y2);
    
    
    return 0;
}


//C
#include <iostream>
using namespace std;

const int N=1e6;

int panduan(int l,int r,int a[N]){
    int min=a[l];
    for(int i=l;i<=r;i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    int x=0;
    for(int i=l;i<=r;i++){
        if(a[i]%min==0){
            x=0;
        }else{
            x=1;
        }
    }
    if(!x){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int t;
    while(t--){
        int n;
        scanf("%d",&n);
        int a[N];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=panduan(i,j,a);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


//最大公因数 超时
#include <iostream>
using namespace std;

const int N=1e6;

int panduan(int l,int r,int a[N]){
    int min=a[l];
    for(int i=l;i<=r;i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    int x=0;
    for(int i=l;i<=r;i++){
        if(a[i]%min!=0){
            x=1;
            break;
        }
    }
    if(!x){
        return 1;
    }else{
        return 0;
    }
    x=0;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[N];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum+=panduan(i,j,a);
                //printf("%d",panduan(i,j,a));
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


//种树
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    int ans=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            ans+=a[i]-a[i-1];
        }
    }
    printf("%d",ans);
    return 0;
}

//丹药1
#include <iostream>
using namespace std;

int N=1e6;

int main(){
    int t;
    cin>>t;
    while(t--){
        int re=0;
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        int a[N],b[N];
        int w1=1,w2=1;
        for(int i=1;i<=x2;i++){
            for(int j=1;j<=x1;j++){
                a[w1]=j*2+i;
                w1++;
            }
        }
        for(int i=1;i<=y2;i++){
            for(int j=1;j<=y1;j++){
                b[w2]=j*2+i;
                w2++;
            }
        }

        for(int i=w1;i>=1;i--){
            for(int j=w2;j>=1;j--){
                if(a[i]==b[j]){
                    re=a[i];
                    break;
                }
            }
        }
        cout<<re*2<<endl;
    }
    return 0;
}