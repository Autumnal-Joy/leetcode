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
    int combinationSum4(vector<int> &nums, int target) {
        auto dp = vector(target + 1, 0u);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (const auto num: nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
