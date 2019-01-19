/*************************************************************************
	> File Name: 3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 17时49分38秒
 ************************************************************************/
// 墙壁涂色

#include <iostream>
using namespace std;
#define MAX_N 1000
#define MAX_K 10
#define MAX_B 1000

int f[MAX_N + 5][MAX_K + 5][MAX_K + 5][MAX_B + 5] = {0};
// f[n][i][j]代表前n块墙壁, 第一块涂第i中颜色, 第n块涂第j种颜色的方法种数

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        f[1][i][i][0] = f[1][i][i][1] = 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            f[2][i][j][0] = f[2][i][j][1] = 1;
        }
    }
    for (int num = 3; num <= n; num++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                //if (i == j) continue;
                for (int t = 0; t < k; t++) {
                    if (t == j) continue;
                    f[num][i][j][0] = max(f[num][i][j][0], f[num - 1][i][t][0]);
                    for (int x = 1; x <= f[num][i][j][0]; x++) {
                        f[num][i][j][x] += f[num - 1][i][t][x];
                    }
                    for (int x = 1; x <= f[num][i][j][0]; x++) {
                        if (f[num][i][j][x] < 10) continue;
                        f[num][i][j][x + 1] += f[num][i][j][x] / 10;
                        f[num][i][j][x] %= 10;
                        f[num][i][j][0] += (x == f[num][i][j][0]);
                    }
                }
            }
        }
    }
    int ans[MAX_B + 5] = {0};
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            ans[0] = max(ans[0], f[n][i][j][0]);
            for (int x = 1; x <= ans[0]; x++) {
                ans[x] += f[n][i][j][x];
            }
            for (int x = 1; x <= ans[0]; x++) {
                if (ans[x] < 10) continue;
                ans[x + 1] += ans[x] / 10;
                ans[x] %= 10;
                ans[0] += (x == ans[0]);
            }
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
