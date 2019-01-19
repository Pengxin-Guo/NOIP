/*************************************************************************
	> File Name: 13_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月19日 星期六 10时57分29秒
 ************************************************************************/
// 0/1背包的优化

#include <iostream>
using namespace std;
#define MAX_N 1000000

int dp[MAX_N + 5] = {0};

int main() {
    int n, total, w, v;
    cin >> total >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> w >> v;
        for (int j = total; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[total] << endl;
    return 0;
}
