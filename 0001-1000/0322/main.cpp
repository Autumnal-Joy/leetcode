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
    int coinChange(const vector<int> &coins, const int amount) {
        auto dp = vector(amount + 1, amount + 1);
        dp[0] = 0;
        for (const auto &coin: coins) {
            for (int i = coin; i <= amount; ++i) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
