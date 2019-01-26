/*************************************************************************
	> File Name: 15.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 16时02分16秒
 ************************************************************************/
// 多重背包
// 第一种简单的做法, 就是将其退化为简单的0/1背包来做
// 第二种做法就是下面程序实现的做法

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_T 10000

int v[MAX_N + 5] = {0};
int w[MAX_N + 5] = {0};
int s[MAX_N + 5] = {0};
int dp[MAX_N + 5][MAX_T + 5] = {0};

int main() {
    int n, total;
    cin >> total >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= s[i]; k++) {
                if (j - k * w[i] < 0) break;
                int temp = dp[i - 1][j - k * w[i]] + k * v[i];
                if (temp > dp[i][j]) dp[i][j] = temp;
            }
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
