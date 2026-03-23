// Fei's Two
//二维斐波那契数列
//dp[i][j] = dp[i-1][j] + dp[i][j-1],边界条件 dp[1][j] = 1, dp[i][1] = 1,其中 1 <= i <= n, 1 <= j <= m
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int dp[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1) continue;
            
            if (i == 1){
                dp[i][j] = dp[i][j-1];
            }else if (j == 1){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}