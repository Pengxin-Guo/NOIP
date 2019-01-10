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

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    int f[4] = {1, 0, 1, 1};
    cin >> n;
    for (int i = 4; i <= n; i++) {
        f[i % 4] = f[(i - 2) % 4] + f[(i - 3) % 3];
    }
    cout << f[n % 4] << endl;
    return 0;
}
