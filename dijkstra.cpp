/*************************************************************************
	> File Name: dijkstra.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月29日 星期五 16时39分46秒
 ************************************************************************/
// 链式前向星实现dijstra算法

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_M 500000
#define MAX_N 10000
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, next, c;
} g[MAX_M + 5];
int head[MAX_N + 5];
int cnt = 0;
int dist[MAX_N + 5], vis[MAX_N + 5];

// 头插法
void add(int a, int b, int c) {
    g[++cnt].to = b;
    g[cnt].c = c;
    g[cnt].next = head[a];
    head[a] = cnt;
    return ;
}

void dij(int s, int n) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    for (int i = 1; i < n; i++) {
        int ind = -1;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (ind == -1 || dist[ind] > dist[j]) ind = j;
        }
        for (int j = head[ind]; j; j = g[j].next) {
            if (dist[g[j].to] > dist[ind] + g[j].c) {
                dist[g[j].to] = dist[ind] + g[j].c;
            }
        }
        vis[ind] = 1;
    }
    return ;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dij(s, n);
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dist[i] == INF) {
            cout << "2147483647";
        } else {
            cout << dist[i];
        }
    }
    cout << endl;
    return 0;
}
