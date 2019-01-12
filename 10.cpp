/*************************************************************************
	> File Name: 10.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月11日 星期五 09时56分42秒
 ************************************************************************/
// 最长上升子序列

#include <iostream>
using namespace std;
#define MAX_N 500000

int value[MAX_N + 5] = {0};
int dp[MAX_N + 5] = {0};

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    dp[0] = 1;
    ans = dp[0];
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (value[j] >= value[i]) continue;
            if (temp < dp[j]) temp = dp[j];
        }
        dp[i] = temp + 1;
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans << endl; 
    return 0;
}
