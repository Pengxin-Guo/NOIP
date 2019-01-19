/*************************************************************************
	> File Name: 3_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月19日 星期六 16时34分35秒
 ************************************************************************/
// 墙壁涂色问题的第一种优化

#include <iostream>
using namespace std;
#define MAX_N 1000
#define MAX_K 10
#define MAX_B 1000

int dp[MAX_N + 5][MAX_K + 5][MAX_B + 5] = {0};
// dp[n][i]代表第一块墙壁涂第0中颜色, 第n块墙壁涂第i种颜色的方法种数
// 最后答案是 k * (dp[n][1] + dp[n][2] + ... dp[n][k - 1])

int main() {
    int n, k;
    cin >> n >> k;
    dp[1][0][0] = dp[1][0][1] = 1;
    for (int i = 1; i < k; i++) {
        dp[2][i][0] = dp[2][i][1] = 1;
    }
    for (int num = 3; num <= n; num++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (j == i) continue;
                dp[num][i][0] = max(dp[num][i][0], dp[num - 1][j][0]);
                for (int x = 1; x <= dp[num][i][0]; x++) {
                    dp[num][i][x] += dp[num - 1][j][x];
                }
                for (int x = 1; x <= dp[num][i][0]; x++) {
                    if (dp[num][i][x] < 10) continue;
                    dp[num][i][x + 1] += dp[num][i][x] / 10;
                    dp[num][i][x] %= 10;
                    dp[num][i][0] += (x == dp[num][i][0]);
                }
            }
        }
    }
    int ans[MAX_B + 1] = {0};
    for (int i = 1; i < k; i++) {
        ans[0] = max(ans[0], dp[n][i][0]);
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] += dp[n][i][j];
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int j = 1; j <= ans[0]; j++) {
        ans[j] *= k;
    }
    for (int j = 1; j <= ans[0]; j++) {
        if (ans[j] < 10) continue;
        ans[j + 1] += ans[j] / 10;
        ans[j] %= 10;
        ans[0] += (j == ans[0]);
    }
    for (int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
