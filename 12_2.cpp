/*************************************************************************
	> File Name: 12_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年02月01日 星期五 21时29分19秒
 ************************************************************************/
// 扔鸡蛋的优化

#include <iostream>
using namespace std;
#define MAX_N 32
#define MAX_K 65536

long long int dp[MAX_N + 5][MAX_K + 5] = {0};
// dp[i][k]代表i个鸡蛋测k次, 最多能测几层楼

int main() {
    long long int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    for (int i = 1; i <= MAX_K; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= MAX_K; k++) {
            dp[i][k] = dp[i][k - 1] + dp[i - 1][k - 1] + 1;
        }
    }
    int ans = 1;
    while (dp[n][ans] < m) ans++;
    cout << ans << endl;
    return 0;
}
