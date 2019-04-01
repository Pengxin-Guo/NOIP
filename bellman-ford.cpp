/*************************************************************************
	> File Name: bellman-ford.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月01日 星期一 09时47分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_M 500000
#define MAX_N 10000
#define INF 0x3f3f3f3f

struct Edge {
    int to, next, c;
} g[MAX_M + 5];
int head[MAX_N + 5], cnt = 0;

inline void add(int a, int b, int c) {
    g[++cnt].to = b;
    g[cnt].next = head[a];
    g[cnt].c = c;
    head[a] = cnt;
}

int dp[MAX_N + 5];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dp[s] = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = head[i]; j; j = g[j].next) {
                int to = g[j].to, c = g[j].c;
                dp[to] = min(dp[to], dp[i] + c);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dp[i] == INF) {
            cout << "2147483647";
        } else {
            cout << dp[i];
        }
    }
    cout << endl;
    return 0;
}
