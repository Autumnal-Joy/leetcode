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
    long long maxEnergyBoost(const vector<int> &energyDrinkA, const vector<int> &energyDrinkB) {
        const auto n = static_cast<int>(energyDrinkA.size());
        // dp[i][j] 表示[0, i]小时位于 j 的最大能量
        auto dp = vector(2, 0ll);
        for (int i = 1; i <= n; ++i) {
            auto temp = dp;
            dp[0] = std::max({temp[0] + energyDrinkA[i - 1], temp[1]});
            dp[1] = std::max({temp[1] + energyDrinkB[i - 1], temp[0]});
        }
        return ranges::max(dp);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
