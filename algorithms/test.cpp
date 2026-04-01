/*#include <iostream>
using namespace std;

int main(){
    int q[10];
    for(int i=0;i<10;i++){
        cin >> q[i];
    }
    for(int i=0;i<10;i++){
        cout << q[i];
        if(i<9){
            cout << " ";
        }
    }
    printf("\n");
    for(int i=9;i>=0;i--){
        cout << q[i];
        if(i>0){
            cout << " ";
        }
    }
    return 0;
}*/
/*#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int q[n];
    for(int i=0;i<n;i++){
        cin >> q[i];
    }
    for(int i=0;i<n;i++){
        if(q[i]>=3){
            int x=q[i]/3;
            int m=q[i]%3;
            if(m==0){
                printf("%d %d %d",x,x,x);
            }else if(m==1){
                printf("%d %d %d",x,x,x+1);
            }else{
                printf("%d %d %d",x,x+1,x+1);
            }
        }else{
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}*/

/*#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int q[n];
    for(int i=0;i<n;i++){
        cin >> q[i];
    }
    for(int i=0;i<n;i++){
        if(q[i]<3){
            printf("-1\n");
        }else{
            printf("1 1 %d",q[i]-2);
        }
    }
    
    return 0;
}*/

//字符串输入
/*#include <iostream>
#include <cstring>
using namespace std;

int main(){

    return 0;
}*/

//斐波那契数列
/*#include <iostream>
using namespace std;

int fei(int n){    //求第 10 个rabbit数  //从0开始
    int q[n+1];   //在第 q[11]数组 的最后一个 q[10];
    q[0]=1,q[1]=1; //零与一都是 1  
    for(int i=2;i<n+1;i++){                     //注意数组指针 0~(数组容量-1);
        q[i]=q[i-1]+q[i-2];
    }
    return q[n];  //第 n 个 rabbit 数
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int re=fei(x);  //第 n 个rabbit 数
        printf("%d\n",re);
    }
    return 0;
}*/

//字符串打印
#include <iostream>
using namespace std;

int main(){
    char x;
    scanf("%c",&x);
    if(x=='H'){
        cout<<"*   *"<<endl;
        cout<<"*   *"<<endl;
        cout<<"*****"<<endl;
        cout<<"*   *"<<endl;
        cout<<"*   *"<<endl;
    }else if(x=='P'){
        cout<<"**** "<<endl;
        cout<<"*   *"<<endl;
        cout<<"**** "<<endl;
        cout<<"*    "<<endl;
        cout<<"*    "<<endl;
    }else{
        cout<<"*   *"<<endl;
        cout<<"*   *"<<endl;
        cout<<"*   *"<<endl;
        cout<<"*   *"<<endl;
        cout<<" *** "<<endl;
    }
    return 0;  
}
