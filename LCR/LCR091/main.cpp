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
    int minCost(const vector<vector<int>> &costs) {
        if (costs.empty()) return 0;
        const auto n = static_cast<int>(costs.size());
        // dp[i][j] 表示 [0,i] 的房子的最小花费，且第 i 个房子的颜色为 j
        auto dp = vector(3, 0);
        dp = costs[0];
        for (int i = 1; i < n; ++i) {
            auto temp = dp;
            dp[0] = std::min({temp[1], temp[2]}) + costs[i][0];
            dp[1] = std::min({temp[0], temp[2]}) + costs[i][1];
            dp[2] = std::min({temp[0], temp[1]}) + costs[i][2];
        }
        return ranges::min(dp);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
