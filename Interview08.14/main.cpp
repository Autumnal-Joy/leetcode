#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    using P = std::pair<int, int>;

    static int operate(const int a, const char op, const int b) {
        switch (op) {
            case '&':
                return a & b;
            case '|':
                return a | b;
            case '^':
                return a ^ b;
            default:
                throw invalid_argument("Invalid operator");
        }
    }

public:
    int countEval(const string &s, int result) {
        const auto sz = static_cast<int>(s.size());
        const auto n = (sz + 1) / 2;

        // dp[i][j][k] 表示 s[2i:2j] 为 k 的个数
        auto dp = vector(n, vector(n, vector(2, 0)));
        for (int i = 0; i < n; ++i) {
            const auto c = s[2 * i] - '0';
            dp[i][i][c] = 1;
        }

        for (int cnt = 2; cnt <= n; ++cnt) {
            for (int i = 0; i + cnt - 1 < n; ++i) {
                // 计算 dp[i][i + cnt - 1][k]
                for (int j = 0; j < cnt - 1; ++j) {
                    const auto op = s[2 * (i + j) + 1];
                    for (auto [a, b]: {P{0, 0}, P{0, 1}, P{1, 0}, P{1, 1}}) {
                        dp[i][i + cnt - 1][operate(a, op, b)] += dp[i][i + j][a] * dp[i + j + 1][i + cnt - 1][b];
                    }
                }
            }
        }

        return dp[0][n - 1][result];
    }
};

int main() {
    auto s = string("1^0|0|1");
    cout << Solution().countEval(s, 0) << endl;
    return 0;
}
