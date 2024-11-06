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
    int minCut(const string &s) {
        const auto n = static_cast<int>(s.size());
        // isPalindrome[i][j] 表示 s[i:j] 是否是回文串
        auto isPalindrome = vector(n, vector(n, false));
        isPalindrome[0][0] = true;
        for (int i = 1; i < n; ++i) {
            isPalindrome[i][i] = true;
            isPalindrome[i - 1][i] = s[i - 1] == s[i];
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s[i] == s[j];
            }
        }
        // dp[i] 表示 s[0:i] 的最小分割次数
        auto dp = vector(n, n);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j <= i; ++j) {
                    if (isPalindrome[j][i]) {
                        dp[i] = std::min({dp[i], dp[j - 1] + 1});
                    }
                }
            }
        }
        return dp[n - 1];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
