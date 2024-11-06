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
public:
    int longestCommonSubsequence(const string &text1, const string &text2) {
        const auto m = static_cast<int>(text1.size());
        const auto n = static_cast<int>(text2.size());
        // dp[i][j] 表示 text1[0..i) 和 text2[0..j) 的最长公共子序列
        // text1[i]==text2[j], dp[i+1][j+1]=dp[i][j]+1
        auto dp = vector(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            int prev = dp[0];
            for (int j = 0; j < n; ++j) {
                const int next = dp[j + 1];
                dp[j + 1] = std::max({dp[j + 1], dp[j]});
                if (text1[i] == text2[j]) {
                    dp[j + 1] = std::max(dp[j + 1], prev + 1);
                }
                prev = next;
            }
        }
        return dp[n];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
