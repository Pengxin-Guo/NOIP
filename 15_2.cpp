/*************************************************************************
	> File Name: 15_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月26日 星期六 21时02分31秒
 ************************************************************************/
// 把多重背包当做0/1背包
// 我们把多重背包当成0/1背包做, 就是因为每一堆都是1的话可以组合出所有的可能性
// 多重背包的二进制优化

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

int dp[MAX_V + 5] = {0};
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];
int n, V;

int main() {
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i] >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= s[i]; k <<= 1) {
            int kk = (s[i] - k + 1 < k ? s[i] - k + 1 : k);
            int ww = w[i] * kk, vv = v[i] * kk;
            for (int j = V; j >= ww; j--) {
                dp[j] = max(dp[j], dp[j - ww] + vv);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
