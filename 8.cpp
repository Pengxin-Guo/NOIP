/*************************************************************************
	> File Name: 8.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 10时49分44秒
 ************************************************************************/
// 切割回文

/*
区间dp问题

1.确定动归状态
dp(i, j) 代表从第i位到第j位最少切多少刀

2.确定状态转移方程
dp(i, j) = min { dp(i, k) + dp(k + 1, j) + 1    |   k c [i, j)
               { 0                              |   str[i] = str[j] 且 dp(i + 1, j - 1) = 0
3.分析转移方式

*/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 5000

int dp[MAX_N + 5][MAX_N + 5] = {0};                  // dp[i][j]代表从第i位到第j位最少切多少刀

int main() {
    char str[MAX_N + 5] = {0};
    cin >> str;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j] && dp[i + 1][j - 1] == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][i] + dp[i + 1][j] + 1;
            for (int k = i + 1; k < j; k++) {
                int temp = dp[i][k] + dp[k + 1][j] + 1;
                if (dp[i][j] > temp) dp[i][j] = temp;
            }
        }
    }
    /*
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[0][len - 1] << endl;
    return 0;
}
