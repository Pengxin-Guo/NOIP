/*************************************************************************
	> File Name: 2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月09日 星期三 10时25分20秒
 ************************************************************************/
// 爬楼梯

/*

逆向递推求解
滚动数组
大数加法

*/

#include <iostream>
using namespace std;
#define MAX_N 100

int f[4][MAX_N + 5] = {0};

int main() {
    int n;
    f[1][0] = 1, f[1][1] = 0;
    f[2][0] = f[2][1] = 1;
    f[3][0] = f[3][1] = 1;
    cin >> n;
    for (int i = 4; i <= n; i++) {
        f[i % 4][0] = f[(i - 1) % 4][0];
        for (int j = 1; j <= f[i % 4][0]; j++) {
            f[i % 4][j] = f[(i - 2) % 4][j] + f[(i - 3) % 4][j];
        }
        for (int j = 1; j <= f[i % 4][0]; j++) {
            if (f[i % 4][j] < 10) continue;
            f[i % 4][j + 1] += f[i % 4][j] / 10;
            f[i % 4][j] %= 10;
            f[i % 4][0] += (j == f[i % 4][0]);
        }
    }
    for (int i = f[n % 4][0]; i > 0; i--) {
        cout << f[n % 4][i];
    }
    cout << endl;
    return 0;
}
