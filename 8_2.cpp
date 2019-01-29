/*************************************************************************
	> File Name: 8_2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年01月15日 星期二 10时26分30秒
 ************************************************************************/
// 切割回文的优化

#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 500000
int dp[MAX_N + 5] = {0};                            // dp[i]代表从1到i最少切多少刀
// dp[i] = min{dp[k] + 1}                           |  k c [0, i) 且 str[k+1...i]是回文串
vector<int> f[MAX_N + 5];                           // f[i]存储以i位置为结尾的所有回文串的起始位置

void expand(string &str, int i, int j) {
    while (i >= 0 && j < str.size() && str[i] == str[j]) {
        f[j].push_back(i);
        i--;
        j++;
    }
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        expand(str, i, i);                          // 处理回文串长度为奇数的情况
        expand(str, i, i + 1);                      // 处理回文串长度为偶数的情况
    }
    for (int i = 0; i < str.size(); i++) {
        dp[i] = str.size();
        for (int k = 0; k < f[i].size(); k++) {
            int ind = f[i][k];
            int val = (ind - 1 < 0 ? -1 : dp[ind - 1]);
            dp[i] = min(dp[i], val + 1);
        }
    }
    cout << dp[str.size() - 1] << endl;
    return 0;
}
