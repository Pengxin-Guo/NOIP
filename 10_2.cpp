/*************************************************************************
	> File Name: 10_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月15日 星期二 18时33分07秒
 ************************************************************************/
// 最长上升子序列的优化

#include <iostream>
#include <limits.h>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5] = {0};                                  // dp[i]代表以i位为结尾的上升子序列的最长长度
int f[MAX_N + 5] = {0};                                   // f[i]是一个动态更新的数组, 记录长度为j序列的末尾最小值
int arr[MAX_N + 5] = {0};

int binary_search(int *num, int len, int x) {
// 在num数组中找到最后一个比x小的数
    int head = 0, tail = len - 1, mid;
    while (head + 3 < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] < x) head = mid;
        else tail = mid - 1;
    }
    for (; head < tail; head++) {
        if (num[head + 1] < x) continue;
        break;
    }
    return head;
}

int main() {
    int n, len = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    f[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = binary_search(f, len, arr[i]) + 1;
        f[dp[i]] = arr[i];
        if (len == dp[i]) len += 1;
    }
    cout << len - 1 << endl;
    return 0;
}
