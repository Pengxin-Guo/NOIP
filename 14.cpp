/*************************************************************************
	> File Name: 14.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: Sun Feb  3 20:34:22 2019
 ************************************************************************/
// 古老的打印机(斜率优化)
/*
 dp[i]代表打印到第i个字符的最小消耗
 
 dp[i] = min(dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + M)  | j c [0, i - 1]
 这里的sum数组代表前缀和

 f[i] = dp[i] + sum[i] * sum[i]

 用单调队列去维护所有有可能是答案的点
*/

#include <iostream>
using namespace std;
#define MAX_N 1000000
long long int sum[MAX_N + 5] = {0};
long long int dp[MAX_N + 5] = {0};
long long int f[MAX_N + 5] = {0};
int q[MAX_N + 5], head = 0, tail = 0;
int n, M;

void set(int i, int j) {
    dp[i] = dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + M;
    f[i] = dp[i] + sum[i] * sum[i];
    return ;
}

double slope(int i, int j) {
    return 1.0 * (f[j] - f[i]) / (sum[j] - sum[i]);
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) cin >> sum[i], sum[i] += sum[i - 1];
    q[tail++] = 0;
    q[tail++] = 1;
    set(1, 0);
    for (int i = 2; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head], q[head + 1]) <= 2 * sum[i]) ++head;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 2], q[tail - 1]) >= slope(q[tail - 1], i)) --tail;
        q[tail++] = i;
    }
    cout << dp[n] << endl;
    return 0;
}
