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
    int res = 0;
    void dfs(vector<int> &nums, int i, int target, vector<int> &prefix) {
        if (i == nums.size()) {
            res += target == 0;
        } else {
            if (-prefix[i + 1] <= target + nums[i] && target + nums[i] <= prefix[i + 1]) {
                dfs(nums, i + 1, target + nums[i], prefix);
            }
            if (-prefix[i + 1] <= target - nums[i] && target - nums[i] <= prefix[i + 1]) {
                dfs(nums, i + 1, target - nums[i], prefix);
            }
        }
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        const auto n = static_cast<int>(nums.size());
        auto prefix = vector(n + 1, 0);
        prefix[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            prefix[i] = nums[i] + prefix[i + 1];
        }
        dfs(nums, 0, target, prefix);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
