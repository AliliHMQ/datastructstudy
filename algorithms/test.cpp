/*
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
const long long NEG = -1e18;

struct Edge {
    int a, b;
    long long w;
} e[M];

long long dist[N], backup[N];
int D, P, C, F,s;

bool bellman_ford() {
    // 初始化：只有起点能赚到 D
    for (int i = 1; i <= C; i++) dist[i] = NEG;
    dist[s] = D;

    // 最多松弛 C - 1 轮
    for (int i = 1; i < C; i++) {
        memcpy(backup, dist, sizeof(dist));
        bool updated = false;

        for (int j = 0; j < P + F; j++) {
            int a = e[j].a, b = e[j].b;
            long long w = e[j].w;

            if (backup[a] == NEG) continue; // 不可达

            if (dist[b] < backup[a] + w) {
                dist[b] = backup[a] + w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    // 第 C 轮还能更新，说明存在正环
    for (int j = 0; j < P + F; j++) {
        int a = e[j].a, b = e[j].b;
        long long w = e[j].w;

        if (dist[a] == NEG) continue;

        if (dist[b] < dist[a] + w) {
            return false; // 无限赚钱
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> D >> P >> C >> F >> s;

    // 普通路径，边权为 D
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        e[i] = {a, b, D};
    }

    // 航线，边权为 D - T
    for (int i = P; i < P + F; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        e[i] = {a, b, (long long)D - t};
    }

    if (!bellman_ford()) {
        cout << "orz" << '\n';
    } else {
        long long ans = NEG;
        for (int i = 1; i <= C; i++) {
            ans = max(ans, dist[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
const long long NEG = -1e18;

struct Edge {
    int a, b;
    long long w;
} e[M];

long long dist[N], backup[N];
int D, P, C, F;

bool bellman_ford() {
    // 多源初始化：可以从任意城市出发赚 D 元
    for (int i = 1; i <= C; i++) dist[i] = D;

    // 最多松弛 C - 1 轮
    for (int i = 1; i < C; i++) {
        memcpy(backup, dist, sizeof(dist));
        bool updated = false;

        for (int j = 0; j < P + F; j++) {
            int a = e[j].a, b = e[j].b;
            long long w = e[j].w;

            if (backup[a] == NEG) continue; // 实际不会为 NEG，但保留安全检查

            if (dist[b] < backup[a] + w) {
                dist[b] = backup[a] + w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    // 第 C 轮检测正环
    for (int j = 0; j < P + F; j++) {
        int a = e[j].a, b = e[j].b;
        long long w = e[j].w;

        if (dist[a] == NEG) continue;

        if (dist[b] < dist[a] + w) {
            return false; // 存在正环，无限赚钱
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> D >> P >> C >> F;

    // 普通路径，边权为 D
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        e[i] = {a, b, D};
    }

    // 航线，边权为 D - T
    for (int i = P; i < P + F; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        e[i] = {a, b, (long long)D - t};
    }

    if (!bellman_ford()) {
        cout << "orz" << '\n';
    } else {
        long long ans = NEG;
        for (int i = 1; i <= C; i++) {
            ans = max(ans, dist[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}