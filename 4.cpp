/*************************************************************************
	> File Name: 4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月12日 星期六 09时17分02秒
 ************************************************************************/
// 钱币问题

#include <iostream>
using namespace std;
#define MAX_N 10000
#define MAX_M 100
#define BASE 9973

int dp[MAX_M + 5][MAX_N + 5] = {0};
int w[MAX_M + 5] = {0};

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int j = 0; j <= n; j++) {
        if (j % w[1]) continue; 
        dp[1][j] = 1;
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - w[i] < 0) {
                dp[i][j] = dp[i - 1][j] % BASE;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - w[i]]) % BASE;
            }
        }
    }
    /*
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[m][n] << endl;
    return 0;
}
