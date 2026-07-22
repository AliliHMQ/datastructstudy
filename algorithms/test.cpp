#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;

        map<pair<int,int>,int> left; //子串l坐标
        left[{0,0}]=0; //原点初始化

        int x=0,y=0;
        int ansl=-1,ansr=-1;
        int best=n+1;

        for(int i=1;i<=n;i++){
            char c=s[i-1];  //从后往前开始记录走法
            if(c=='L') x--;
            else if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='R') x++;

            pair<int,int> cur={x,y};

            auto it=left.find(cur);

            if(it!=left.end()){ //在遍历完之前就已经找到了一个一样的坐标位置
                int l=it->second+1;
                int r=i;
                int len=r-l+1;

                if(len<best){  //判断子串长度，随便选一个要小于原来字符串长度
                    best=len;
                    ansl=l;
                    ansr=r;
                }
            }
            left[cur]=i; //添加进去 这一点坐标对应的字符串序号
        }
        if(ansl==-1){
            cout<<-1<<endl;
        }else{
            cout<<ansl<<' '<<ansr<<endl;
        }
    }
    return 0;
}