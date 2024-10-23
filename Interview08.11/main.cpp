#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    int M = 1000000007;

public:
    int waysToChange(int n) {
        // dp[i] 表示组成 i 的方法数
        auto dp = vector<int>(n + 1);
        auto coins = vector({1, 5, 10, 25});
        dp[0] = 1;
        for (auto &coin: coins) {
            for (int i = coin; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i - coin]) % M;
            }
        }
        return dp[n];
    }
};

int main() {

    return 0;
}
