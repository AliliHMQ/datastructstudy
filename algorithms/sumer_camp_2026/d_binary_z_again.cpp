

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