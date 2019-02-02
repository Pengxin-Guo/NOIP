/*************************************************************************
	> File Name: 13.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年02月02日 星期六 10时48分30秒
 ************************************************************************/
// 矩形（单调栈优化）

#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD_NUM 100007
int f[MAX_N + 5][MAX_N + 5] = {0};
// f[i][j]代表(i, j)点向下有多少个连续的白色格子
int dp[MAX_N + 5][MAX_N + 5] = {0}; 
// dp[i][j]代表以(i, j)点作为左上角坐标的合法全白矩形的数量
int s[MAX_N + 5], top = -1;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
        f[i][m] = -1;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m ; j++) {
            if (f[i][j] == 0) continue;
            f[i][j] += f[i + 1][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        top = -1;
        s[++top] = m;
        for (int j = m - 1; j >= 0; j--) {
            while (f[i][s[top]] > f[i][j]) --top;
            dp[i][j] = (s[top] - j) * f[i][j] + dp[i][s[top]];
            dp[i][j] %= MOD_NUM;
            ans += dp[i][j];
            ans %= MOD_NUM;
            s[++top] = j;
        }
    }
    cout << ans << endl;
    return 0;
}
