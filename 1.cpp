/*************************************************************************
	> File Name: 1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月09日 星期三 09时20分14秒
 ************************************************************************/
// 兔子繁殖问题

/*

如何求解递推问题

1.确定递推状态（最重要的一步）
2.推导递推公式
3.程序实现

*/

#include <iostream>
using namespace std;

#define MAX_N 1000

namespace smallData {
    int f_keep[MAX_N + 5] = {0, 1, 2};
    int f(int n) {
        if (f_keep[n]) return f_keep[n];
        f_keep[n] = f(n - 1) + f(n - 2);
        return f_keep[n];
    }
}

namespace bigData {
    int f[MAX_N + 5][100] = {0};
    void solve(int n) {
        f[1][0] = f[1][1] = 1;
        f[2][0] = 1, f[2][1] = 2;
        for (int i = 3; i <= n; i++) {
            f[i][0] = f[i - 1][0];
            for (int j = 1; j <= f[i][0]; j++) {
                f[i][j] = f[i - 1][j] + f[i - 2][j];
            }
            for (int j = 1; j <= f[i][0]; j++) {
                if (f[i][j] < 10) continue;
                f[i][j + 1] += f[i][j] / 10;
                f[i][j] %= 10;
                f[i][0] += (j == f[i][0]);
            }
        }
        for (int i = f[n][0]; i > 0; i--) {
            cout << f[n][i];
        }
        cout << endl;
    }
}
int main() {
    int n;
    while (cin >> n) {
        if (n <= 20) {
            cout << smallData::f(n) << endl;
        } else {
            bigData::solve(n);
        }
    }
    return 0;
}
