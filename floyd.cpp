/*************************************************************************
	> File Name: floyd.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月31日 星期日 20时37分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 100
#define INF 0x3f3f3f3f
int dp[MAX_N + 5][MAX_N + 5][MAX_N + 5] = {0};
// dp[k][i][j] 代表从i点到j点, 经过前k个点的最短路径长度

int main() {
    memset(dp, 0x3f, sizeof(dp));
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[0][a][b] = min(c, dp[0][a][b]);
    }
    for (int i = 1; i <= n; i++) dp[0][i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[k][i][j] = min(dp[k - 1][i][j], dp[k - 1][i][k] + dp[k - 1][k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dp[n][s][i] == INF) {
            cout << "2147483647";
        } else {
            cout << dp[n][s][i];
        }
    }
    cout << endl;
    return 0;
}
