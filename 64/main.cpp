#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        auto dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = std::min({dp[i][j - 1], dp[i - 1][j]}) + grid[i][j];
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

int main() {

    return 0;
}
