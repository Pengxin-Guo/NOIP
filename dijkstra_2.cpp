/*************************************************************************
	> File Name: dijkstra_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月29日 星期五 18时43分52秒
 ************************************************************************/
// 链式前向星实现dijstra算法
// 改进算法

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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

struct Data {
    Data(int a, int b) : first(a), second(b) {}
    bool operator<(const Data &obj) const {
        return this->second > obj.second;
    }
    int first, second;
};

void dij(int s, int n) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<Data> q;
    q.push(Data(s, 0));
    for (int i = 1; i < n && !q.empty(); i++) {
        int ind = q.top().first;
        q.pop();
        cout << q.size() << endl;
        while (vis[ind] && !q.empty()) {
            ind = q.top().first;
            q.pop();
        }
        for (int j = head[ind]; j; j = g[j].next) {
            if (dist[g[j].to] > dist[ind] + g[j].c) {
                dist[g[j].to] = dist[ind] + g[j].c;
                vis[g[j].to] = 0;    // 可以处理带负权边的图
                q.push(Data(g[j].to, dist[g[j].to]));
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

