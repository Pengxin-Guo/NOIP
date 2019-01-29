/*************************************************************************
	> File Name: 10_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月19日 星期六 16时12分38秒
 ************************************************************************/
// 完全背包的优化

#include <iostream>
using namespace std;
#define MAX_N 10000

int dp[MAX_N + 5] = {0};

int main() {
    int n, total, v, w;
    cin >> n >> total;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        for (int j = w; j <= total; j++) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[total] << endl;
    return 0;
 }
