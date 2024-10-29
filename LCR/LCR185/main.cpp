#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {

public:
    vector<double> statisticsProbability(int num) {
        // dp[i][j] 表示 i 个骰子掷出 j 的情况数
        auto dp = vector(num + 1, vector(6 * num + 1, 0ll));
        dp[0][0] = 1;
        for (int i = 1; i < num + 1; ++i) {
            for (int j = i; j < 6 * num + 1; ++j) {
                for (int k = 1; k <= 6 && k <= j; ++k) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        auto res = vector<double>(5 * num + 1, 0);
        auto all = pow(6, num);
        for (int i = 0; i < res.size(); ++i) {
            res[i] = dp[num][i + num] * 1.0 / all;
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
