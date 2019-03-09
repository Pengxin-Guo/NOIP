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
// dp[n][i]代表第一块墙壁涂第0种颜色, 第n块墙壁涂第i种颜色的方法种数
// 最后答案是 k * (dp[n][1] + dp[n][2] + ... dp[n][k - 1])

void my_add(int *ans, int *num1, int *num2) {
    ans[0] = max(num1[0], num2[0]);
    for (int i = 1; i <= ans[0]; i++) {
        ans[i] = num1[i] + num2[i];
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
    return ;
}

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
                my_add(dp[num][i], dp[num][i], dp[num - 1][j]);
            }
        }
    }
    int ans[MAX_B + 1] = {0};
    for (int i = 1; i < k; i++) {
        my_add(ans, ans, dp[n][i]);
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
