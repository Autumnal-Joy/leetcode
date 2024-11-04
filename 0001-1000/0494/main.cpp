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
    int findTargetSumWays(vector<int> &nums, int target) {
        auto sum = std::reduce(nums.begin(), nums.end(), 0);
        target = std::abs(target);
        if (target > sum) return 0;
        sum -= target;
        if (sum % 2 != 0) return 0;
        sum /= 2;
        // dp[i][j] 表示 [0,i) 拿到 j 的个数
        auto dp = vector(sum + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = sum; j >= nums[i - 1]; --j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[sum];
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({1, 2, 1});
    cout << Solution().findTargetSumWays(nums, 0) << endl;
    return 0;
}
#endif
