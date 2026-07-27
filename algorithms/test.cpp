#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

double f(double mid,double a,double b,double c,double d){
    return a*mid*mid*mid+b*mid*mid+c*mid+d;
}

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    set<double> re;
    if (fabs(f(100,a,b,c,d))<1e-7) re.insert(100);
    for(int i=-100;i<100;i++){           //根的范围[-100, 100]
        if(fabs(f(i,a,b,c,d))<1e-7){
            re.insert(i);
        }else{
            if(f(i,a,b,c,d)*f(i+1,a,b,c,d)<0){
                double l=i,r=i+1;
                for(int j=0;j<100;j++){
                    double mid=(l+r)/2.0;
                    if(f(mid,a,b,c,d)*f(l,a,b,c,d)<0){
                        r=mid;
                    }else{
                        l=mid;
                    }
                }
                re.insert((l+r)/2.0);
            }
        }
    }
    for (auto it=re.begin();it!=re.end();++it) {
        printf("%.2f ", *it);
    }
    return 0;
}