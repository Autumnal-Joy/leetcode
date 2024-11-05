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
    int minimumTotal(const vector<vector<int>> &triangle) {
        const auto level = static_cast<int>(triangle.size());
        auto dp = vector(level, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < level; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else if (j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    dp[j] = std::min({dp[j], dp[j - 1]}) + triangle[i][j];
                }
            }
        }
        return ranges::min(dp);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
