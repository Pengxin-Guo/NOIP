/*************************************************************************
	> File Name: 11_3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月29日 星期二 20时42分48秒
 ************************************************************************/
// 多重背包的单调队列优化

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 100000

int dp[MAX_N + 5][MAX_V + 5] = {0};
int v[MAX_N + 5], w[MAX_N + 5], s[MAX_N + 5];
struct Data {
    int val, j; // val代表价值, j代表当前单调队列这个元素的重量值
} q[MAX_V + 5]; // 单调队列用来维护这个区间的最大值
int head, tail;
int n, V;

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
    for (int i = 1; i <= n; i++) { // 处理每种物品
        for (int r = 0; r < w[i]; r++) { // 按照余数系来处理
            head = 0, tail = 0;
            q[tail++] = {dp[i - 1][r], r};
            dp[i][r] = dp[i - 1][r];
            for (int j = r + w[i]; j <= V; j += w[i]) {
                int val = dp[i - 1][j] - j / w[i] * v[i];
                while (head < tail && val >= q[tail - 1].val) --tail;
                q[tail++] = {val, j};
                if ((j - q[head].j) / w[i] > s[i]) ++head;
                dp[i][j] = q[head].val + j / w[i] * v[i];
            }
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}
