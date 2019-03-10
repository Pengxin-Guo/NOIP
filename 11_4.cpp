/*************************************************************************
	> File Name: 11_4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月10日 星期日 11时04分54秒
 ************************************************************************/
// 多重背包的另一种优化（好记）
// 类似于0/1背包的优化
// 不过过海贼的题会TLE

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000
int vv, n;
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];
int dp[MAX_V + 5] = {0};

int main() {
    cin >> vv >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = vv; j >= 0; j--) {
            for (int k = 0; k <= s[i]; k++) {
                if (j >= v[i] * k) {
                    dp[j] = max(dp[j - v[i] * k] + w[i] * k, dp[j]);
                }
            }
        }
    }
    cout << dp[vv] << endl;
    return 0;
}
