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

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
    long long M = 1e9 + 7;

public:
    int numDistinct(string s, string t) {
        const auto m = static_cast<int>(s.size());
        const auto n = static_cast<int>(t.size());
        // dp[i][j] 表示 s[0, i] 中 t[0, j] 的子序列个数
        // dp[i+1][j+1]
        //      s[i]==t[j], dp[i][j+1]+dp[i][j]
        //      s[i]!=t[j], dp[i][j+1]
        auto dp = vector(m, vector(n, 0ll));
        dp[0][0] = s[0] == t[0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + (s[i] == t[0]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % M;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return static_cast<int>(dp[m - 1][n - 1]);
    }
};

#ifdef LEETCODE
int main() {
    cout << Solution().numDistinct("babgbag", "bag") << endl;
    return 0;
}
#endif
