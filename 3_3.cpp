/*************************************************************************
	> File Name: 3_3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月19日 星期六 19时13分44秒
 ************************************************************************/
// 墙壁涂色问题的第二种优化

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX_N 1000
#define MAX_B 1000

int dp[MAX_N + 5][MAX_B + 5] = {0};
// dp[n]代表n块墙壁的方法种数, dp[n] = (k - 2) * dp[n - 1] + (k - 1) * dp[n - 2];

void my_add(int *ans, int *num1, int *num2, int x, int y) {
    ans[0] = max(num1[0], num2[0]);
    for (int i = 1; i <= ans[0]; i++) {
        ans[i] = x * num1[i] + y * num2[i];
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
    dp[2][1] = k * (k - 1);
    dp[2][0] = floor(log10(k * (k - 1))) + 1;
    for (int i = 3; i <= n; i++) {
        my_add(dp[i], dp[i - 1], dp[i - 2], k - 2, k - 1);
    }
    for (int i = dp[n][0]; i >= 1; i--) {
        cout << dp[n][i];
    }
    cout << endl;
    return 0;
}
