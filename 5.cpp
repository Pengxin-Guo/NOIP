/*************************************************************************
	> File Name: 5.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月10日 星期四 11时41分33秒
 ************************************************************************/
// 数字三角形

/*
动态规划类问题

1.确定动归状态  
    f(i, j)代表从底边走到(i, j)点所能获得的最大值
2.确定状态转移方程 
    f(i, j) = max { f(i + 1, j)     } + val(i, j)
                  { f(i + 1, j + 1) }
3.正确性证明
    借助于数学归纳法
4.程序实现

*/

#include <iostream>
using namespace std;
#define MAX_N 1000
int val[MAX_N + 5][MAX_N + 5] = {0};
int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = 0; i < n; i++) dp[n - 1][i] = val[n - 1][i];
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + val[i][j];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
