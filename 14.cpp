/*************************************************************************
	> File Name: 14.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 16时02分16秒
 ************************************************************************/
// 完全背包

#include <iostream>
using namespace std;
#define MAX_N 10000
#define MAX_T 10000

int v[MAX_N + 5] = {0};
int w[MAX_N + 5] = {0};
int dp[MAX_N + 5][MAX_T + 5] = {0};

int main() {
    int n, total;
    cin >> n >> total;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            if (j - w[i] < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][total] << endl;
    return 0;
}
