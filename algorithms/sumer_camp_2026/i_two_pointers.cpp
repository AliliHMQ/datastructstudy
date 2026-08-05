//双指针


/*A - 连续正整数和*/
/*
枚举左端点 l，
找出使总和大于或等于 n 的 r，
如果此时总和等于 n，输出。
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int j=n;
    for(int l=1,r=2,sum=3;r<n;sum-=l,l++){  //一个循环里面两个指针，双指针
        while(sum<n){
            r+=1;
            sum+=r;
        }
        if(sum==n){
            cout<<l<<" "<<r<<'\n';
        }
    }
    return 0;
}

/*B - 区间最大和*/
//找到满足要求的一段区间和
//n<=4*10^6
//双指针加前缀和优化
#include <bits/stdc++.h>
using namespace std;
int n,m,s;
long long sum[4000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        sum[i]=sum[i-1]+s;    //子区间和用前缀和优化
    }
    long long ans=-1;
    int l=1,r=1,ansl,ansr;
    while(r<=n){
        while(sum[r]-sum[l-1]>m && l<r)l++;
        if(sum[r]-sum[l-1]>ans){
            ans=sum[r]-sum[l-1];
            ansl=l,ansr=r;
        }
        r++;
    }
    cout<<ansl<<" "<<ansr<<" "<<ans<<"\n";
    return 0;
}

/*C - T3 句子反转*/

/*
要求将这些单词倒序输出
而且对于每个单词，如果是小写词，应当转为大写；
如果是大写词，应当转为小写；
如果是自然数，应该倒转输出。
*/
//getline 处理？
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string re;
    for(int i=0;i<=s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            re+=s[i]-'A'+'a';
        }
        if(s[i]>='a'&&s[i]<='z'){
            re+=s[i]-'a'+'A';
        }
        if(s[i]>='0'&&s[i]<='9'){
            
        }
        //遇到困难，不知道怎么处理这个123反转成321
    }


    return 0;
}
*/
//依旧题解
/*
可以使用 getline 读入一整行后慢慢处理，
也可以用 cin 分单词读入
*/
/*
#include <bits/stdc++.h>
using namespace std;

int n;
string s[1007];

int main(){
    while(cin>>s[++n]);--n;
    for(int i=n;i>=1;i--){
        for(int j=n;j<(int)s[i].size();j++){
            if(s[i][j]>='A'&&s[i][j]<='Z'){
                s[i][j]-='A'+'a';
            }
            else if(s[i][j]>='a'&&s[i][j]<='z'){
                s[i][j]-='a'+'A';
            }
        }
        if(s[i][0]>='0' && s[i][0]<='9'){
            for(int j=(int)s[i].size()-1;j>=0;j--){
                cout<<s[i][j];
            }else{
                cout<<s[i];
            }
            if(i!=1) cout<<" ";
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n;
string s[1007];

int main() {
	while(cin >> s[++n]); --n;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < (int)s[i].size(); j++) {
			if(s[i][j] >= 'a' && s[i][j] <= 'z') s[i][j] -= 'a' - 'A';
			else if(s[i][j] >= 'A' && s[i][j] <= 'Z') s[i][j] -= 'A' - 'a'; 
		}
		if(s[i][0] >= '0' && s[i][0] <= '9')
			for(int j = (int)s[i].size() - 1; j >= 0; j--) cout << s[i][j];
		else cout << s[i];
		if(i != 1) cout << " ";
	}
}
*/

/*H - 【模板】双指针*/

//找出最长的区间，满足区间中元素两两不同。
//如果有多个这样的区间，依次输出它们。 找最长无重复子数组：滑动窗口。
