#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    int x,m;
    cin >> x >> m;
    a.insert(a.begin()+x-1,m);
    for(int i=0;i<n+1;i++){
        if(i>0){
            cout << " ";
        }
        cout << a[i];
    }
    return 0;
}

//这里
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(5 * sizeof(int));
    // 忘记检查 arr 是否为 NULL
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    free(arr);
    // 没有 free 后置 NULL，但这不是重点
    return 0;
}