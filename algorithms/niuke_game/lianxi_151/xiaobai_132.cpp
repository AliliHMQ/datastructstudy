//牛客小白月赛 132 

//A、出题需要 rating

/*
题目分析
1、1000分初始，参加n场
2、统计（排除初始状态）多少次名字
3、输入比赛次数n n次比赛之后分的变化
4、输出7个非负整数，
在灰名、紫名、蓝名、青名、黄名、橙名、红名的记录次数。
*/

/*
做题思路
1、数组存储变化 每次赛后分数 re
2、循环记录re
3、输出
*/

/*
#include <iostream>
using namespace std;

const int N=1e5+10;
int a[N]={},re[7]={};

int main(){
    a[0]=10;
    int n;
    cin>>n;    //n场比赛
    int m=1000;
    for(int i=1;i<n+1;i++){  //n次结果
        int x;
        cin>>x;
        m+=x;
        a[i]=m/100;
    }
    //n+1个数据记录
    for(int i=1;i<n+1;i++){
        if(0<=a[i] && a[i]<=6){
            re[0]++;
        }else if(7<=a[i] && a[i]<=10){
            re[1]++;
        }else if(11<=a[i] && a[i]<=14){
            re[2]++;
        }else if(15<=a[i] && a[i]<=19){
            re[3]++;
        }else if(20<=a[i] && a[i]<=23){
            re[4]++;
        }else if(24<=a[i] && a[i]<=27){
            re[5]++;
        }else{
            re[6]++;
        }
    }

    for(int i=0;i<7;i++){
        printf("%d",re[i]);
        if(i<6){
            printf(" ");
        }
    }
    return 0;
}
*/

//B、出题需要语文

/*
题目分析
1、他已经出了 n 道题目，难度和质量
2、难度：A-F，质量：0-100
3、选6道，组成比赛，(质量>=60,平均质量>=70,A-F刚好一道)
4、选方案，无则-1

1、输入n个题
2、有合法方案输出题号，从A-F
*/

/*
做题思路
1、A-F分组
2、循环去除低于60分的 
如果同一组完全没有大于或等于60分的直接输出-1
3、循环组成每套题顺便判断，有则直接输出，没有直接-1
*/

#include <iostream>
using namespace std;

const int N=1e5+10;

int main(){
    int a[N],x1=0;
    int b[N],x2=0;
    int c[N],x3=0;
    int d[N],x4=0;
    int e[N],x5=0;
    int f[N],x6=0;
    //int x[7]={};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char x;
        int m;
        cin>>x>>m;
        if(m<60){
            continue;
        }
        if(x=='A'){
            a[x1++]=m;
        }else if(x=='B'){
            b[x2++]=m;
        }else if(x=='C'){
            c[x3++]=m;
        }else if(x=='D'){
            d[x4++]=m;
        }else if(x=='E'){
            e[x5++]=m;
        }else{
            f[x6++]=m;
        }
    }
    if(x1==0 || x2==0 || x3==0 || x4==0 || x5==0 || x6==0){
        return -1;
    }
    bool re=0;
    for(int i=0;i<x1;i++){
        for(int j=0;j<x2 && !re;j++){
            for(int k=0;k<x3 && !re;k++){
                for(int l=0;l<x4 && !re;l++){
                    for(int m=0;m<x5 && !re;m++){
                        for(int n=0;n<x6 && !re;n++){
                            int sum=a[i]+b[j]+c[k]+d[l]+e[m]+f[n];
                            if(sum>=420){
                                re=1;
                                printf("%d %d %d %d %d %d",i,j,k,l,m,n);
                            }
                        }
                    }
                }
            }
        }
    }
    if(re==0){
        printf("-1");
    }
    
    return 0;
}

//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 每个难度存储最高分及其下标（1-based）
    int max_score[6] = {0};   // 0:A,1:B,2:C,3:D,4:E,5:F
    int max_idx[6] = {0};

    for (int i = 1; i <= n; i++) {
        char d;
        int q;
        cin >> d >> q;
        if (q < 60) continue;   // 质量不够的直接跳过

        int pos;
        if (d == 'A') pos = 0;
        else if (d == 'B') pos = 1;
        else if (d == 'C') pos = 2;
        else if (d == 'D') pos = 3;
        else if (d == 'E') pos = 4;
        else pos = 5;   // 'F'

        if (q > max_score[pos]) {
            max_score[pos] = q;
            max_idx[pos] = i;
        }
    }

    // 检查每个难度是否都有题目
    bool ok = true;
    int total = 0;
    for (int i = 0; i < 6; i++) {
        if (max_score[i] == 0) {
            ok = false;
            break;
        }
        total += max_score[i];
    }

    if (!ok || total < 420) {
        cout << -1 << endl;
    } else {
        // 输出最优组合的下标
        cout << max_idx[0] << " " << max_idx[1] << " " << max_idx[2] << " "
             << max_idx[3] << " " << max_idx[4] << " " << max_idx[5] << endl;
    }

    return 0;
}


//C、出题需要加法

/*
题目分析
1、w非负整数，x和y，区间范围内有多少个合数
2、组数，区间
*/

#include <iostream>
using namespace std;

const int N=1e5+10;

int main(){
    int n;
    cin>>n;
    return 0;
}