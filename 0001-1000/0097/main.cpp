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
    static bool isInterleave(const string &s1, const string &s2, const string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        const auto m = static_cast<int>(s1.size());
        const auto n = static_cast<int>(s2.size());
        // dp[i][j] 表示 s1[0,i) 与 s2[0,j) 是否可以交错组成 s3[0,i+j)
        // s3[i+j+1]==s1[i], dp[i+1][j+1]=dp[i][j+1]
        // s3[i+j+1]==s2[j], dp[i+1][j+1]=dp[i+1][j]
        auto dp = vector(n + 1, false);
        dp[0] = true;
        for (int j = 0; j < n; ++j) {
            dp[j + 1] = s3[j] == s2[j] && dp[j];
        }
        for (int i = 0; i < m; ++i) {
            dp[0] = s3[i] == s1[i] && dp[0];
            for (int j = 0; j < n; ++j) {
                dp[j + 1] = s3[i + j + 1] == s1[i] && dp[j + 1] ||
                            s3[i + j + 1] == s2[j] && dp[j];
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
