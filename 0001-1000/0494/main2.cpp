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
    int findTargetSumWays(vector<int> &nums, const int target) {
        const auto sum = std::reduce(nums.begin(), nums.end(), 0);
        if (target < -sum || target > sum) return 0;
        const auto n = static_cast<int>(nums.size());
        auto dp = vector(n, vector(sum * 2 + 1, 0));
        ++dp[0][sum + nums[0]];
        ++dp[0][sum - nums[0]];
        for (int i = 1; i < n; ++i) {
            for (int j = -sum; j <= sum; ++j) {
                if (j + nums[i] >= -sum && j + nums[i] <= sum) {
                    dp[i][sum + j] += dp[i - 1][sum + j + nums[i]];
                }
                if (j - nums[i] >= -sum && j - nums[i] <= sum) {
                    dp[i][sum + j] += dp[i - 1][sum + j - nums[i]];
                }
            }
        }
        return dp[n - 1][sum + target];
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({0, 1});
    cout << Solution().findTargetSumWays(nums, 1) << endl;
    return 0;
}
#endif
