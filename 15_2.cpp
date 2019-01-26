/*************************************************************************
	> File Name: 15_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月26日 星期六 21时02分31秒
 ************************************************************************/
// 多重背包的二进制优化

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

int dp[MAX_V + 5] = {0};
int v[MAX_N + 5] = {0}, w[MAX_N + 5] = {0}, s[MAX_N + 5] = {0};
int n, V;

int main() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= s[i]; k <<= 1) {
            int K = (s[i] - k + 1 < k ? s[i] - k + 1 : k);
            int ww = w[i] * K, vv = v[i] * K;
            for (int j = V; j >= ww; j--) {
                dp[j] = max(dp[j], dp[j - ww] + vv);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
