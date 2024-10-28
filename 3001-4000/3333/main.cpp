#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    long long M = 1e9 + 7;

public:
    int possibleStringCount(string word, int k) {
        const auto n = static_cast<int>(word.size());
        if (n < k) {
            return 0;
        }
        auto table = vector<long long>();
        auto total = 1ll;
        char prev = word[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == prev) {
                ++cnt;
            } else {
                prev = word[i];
                table.push_back(cnt);
                total = (total * cnt) % M;
                cnt = 1;
            }
        }
        table.push_back(cnt);
        total = (total * cnt) % M;
        const auto m = static_cast<int>(table.size());

        if (m >= k) {
            return static_cast<int>(total);
        }

        // dp[i][j] 表示前 [0,i] 项取 j 的个数
        // table[i] = y
        // dp[i][j] = dp[i-1][j-y] + dp[i-1][j-y+1] + ... + dp[i-1][j-1]
        auto dp = vector(k, 0ll);
        for (int j = 1; j <= table[0] && j < k; ++j) {
            dp[j] = 1;
        }
        auto sum = vector(k + 1, 0ll);
        for (int i = 1; i < m; ++i) {
            for (long long j = 1; j <= k; ++j) {
                sum[j] = sum[j - 1] + dp[j - 1] % M;
            }
            for (long long j = 1; j < k; ++j) {
                dp[j] = (sum[j] - sum[std::max({0ll, j - table[i]})] + M) % M;
            }
        }

        long long exclude = 0;
        for (int j = 0; j < k; ++j) {
            exclude = (exclude + dp[j]) % M;
        }

        const auto res = (total + (M - exclude)) % M;
        return static_cast<int>(res);
    }
};

int main() {
    auto s = string("aabbccdd");
    Solution().possibleStringCount(s, 7);
    return 0;
}
