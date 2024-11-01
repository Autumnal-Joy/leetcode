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
    bool isMatch(const string &s, const string &p) {
        // dp[i][j] 表示 s[0..i) 与 p[0..j) 匹配
        // s[i]==p[j], dp[i+1][j+1] |= dp[i][j]
        // p[j]=='.' , dp[i+1][j+1] |= dp[i][j]
        // p[j]=='*' ,
        //      dp[i+1][j+1] |= dp[i+1][j-1]
        //      dp[i+1][j+1] |= dp[i+1][j]
        //      s[i]==p[j-1], dp[i+1][j+1] |= dp[i][j+1]
        //                    dp[i+1][j+1] |= dp[i][j]
        auto dp = vector(s.size() + 1, vector(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < s.size() + 1; ++i) {
            for (int j = 0; j < p.size() + 1; ++j) {
                if (i >= 1 && j >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                } else if (j >= 2 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j] || dp[i][j - 2] || dp[i][j - 1];
                    if (i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

#ifdef LEETCODE
int main() {
    Solution().isMatch("aa", "a*");
    return 0;
}
#endif
