//高精度练习

//P1042 [NOIP 2003 普及组] 乒乓球
/*#include <iostream>
using namespace std;

int main(){


    return 0;
}*/

//格式化输出
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> add(vector<int> &A,vector<int> &B){
	vector<int> C;
	if(A.size()<B.size()) return add(B,A);
	int t=0;
	for(int i=0;i<A.size();i++){
		t+=A[i];
		if(i<B.size()){
			t+=B[i];
		}
		C.push_back(t%10);
		t/=10;
	}
	if(t){
		C.push_back(1);
	}
	return C;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		string a,b;
		cin>>a>>b;
		vector<int> A,B,C;
		for(int i=(int)a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
		for(int i=(int)b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
		
		C=add(A,B);

		printf("Case %d:\n", j + 1);
        cout << a << " + " << b << " = ";
        for (int i=C.size()-1;i>=0;i--) printf("%d",C[i]); 
        printf("\n");

        // 两个测试用例之间输出一个空行（最后一个不输出）
        if (j!=n-1) printf("\n");
	}
	return 0;
}
 