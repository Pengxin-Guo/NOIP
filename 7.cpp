/*************************************************************************
	> File Name: 7.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 10时24分17秒
 ************************************************************************/
// 最长公共子序列

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    char stra[MAX_N + 5], strb[MAX_N + 5];
    cin >> stra >> strb;
    int lena = strlen(stra), lenb = strlen(strb);
    for (int i = 0; i < lena; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < lenb; i++) {
        dp[0][i] = 0;
    }
    int ans = dp[0][0];
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (stra[i - 1] == strb[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (ans < dp[i][j]) ans = dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
