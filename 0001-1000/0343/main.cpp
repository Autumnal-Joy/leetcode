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
    int integerBreak(int n) {
        auto dp = vector<int>(n + 1);
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = std::max({dp[i], std::max({j, dp[j]}) * std::max({i - j, dp[i - j]})});
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
