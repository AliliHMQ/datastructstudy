//在一个数组的第 x 个位置插入一个新的数 y
/*#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        int m;
        cin >> m;
        v.push_back(m);
    }
    int x,m;
    cin >> x >> m;
    v.insert(v.begin()+x-1,m);
    for(int i=0;i<v.size();i++){
        if(i>0){
            cout << " ";
        }
        cout << v[i];
    }
    return 0;
}*/
