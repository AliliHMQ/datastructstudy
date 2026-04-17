//数轴跳跃
//问题要求机器人从1出发，
//每次只能向右跳k或向左跳k
//（但向左跳需要当前位置 > k）。
//实际上，机器人只能向右移动
//（因为从1出发无法向左），
//所以能到达的位置是所有形如 
//1 + t*k (t ≥ 0) 的正整数，即与1模k同余的数

/*
#include <iostream>
using namespace std;
const int N=1e5+10;

int main(){
    int n,x;
    cin >> n >> x;
    int a[N];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int w=n%x;
    //cout << w << endl;
    int b[N];
    for(int i=0;i<n;i++){
        b[i]=w+i*x;
        //cout << b[i] << " ";
    }
    //printf("\n");
    int re=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i]==a[j]){
                re++;
            }
        }
    }
    cout << re;
    return 0;
}
*/

#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    long long a;
    int re=0;
    for(int i=0;i<n;i++){
        cin >> a;
        if((a-1)%k==0) re++;
    }
    cout << re << endl;
    return 0;
}