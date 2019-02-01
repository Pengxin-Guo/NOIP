/*************************************************************************
	> File Name: 12.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年02月01日 星期五 17时04分55秒
 ************************************************************************/
// 扔鸡蛋

#include <iostream>
using namespace std;
#define MAX_N 5
#define MAX_M 1000000
int dp[MAX_N + 5][MAX_M + 5] = {0}; // dp[i][j]代表有i个鸡蛋、测j层楼, 最多最少测几次
// dp[i][j] = min(max(dp[i - 1][k - 1], dp[i][j - k]) + 1)
// dp[i - 1][k - 1]代表这个鸡蛋扔在第k层碎了, dp[i][j - k]代表扔在第k层没碎

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = j;
            for (int k = 1; k <= j; k++) {
                int temp = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
                dp[i][j] = min(temp, dp[i][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
