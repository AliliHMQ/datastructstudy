#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long totalMod = 0;
    for (long long x : a) {
        totalMod = (totalMod + x % m + m) % m;
    }

    vector<int> pos(m, -1);
    pos[0] = 0;

    long long pref = 0;
    int bestDelete = n + 1;

    for (int i = 1; i <= n; ++i) {
        pref = (pref + a[i - 1] % m + m) % m;
        int need = (pref - totalMod + m) % m;
        if (pos[need] != -1) {
            bestDelete = min(bestDelete, i - pos[need]);
        }
        pos[pref] = i;
    }

    if (bestDelete == n + 1 || bestDelete == n) {
        cout << -1 << '\n';
    } else {
        cout << n - bestDelete << '\n';
    }

    return 0;
}


