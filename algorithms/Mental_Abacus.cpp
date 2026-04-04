//这里是1-100的数据，那我们使用数组存储
//每次遍历 找是否有匹配的
#include <iostream>
using namespace std;

int main() {
    int n, a[105];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {      //外面确定每次比较的数
        bool ok = false;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[j] + a[k] == a[i]) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}