#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(const vector<vector<int>> &matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        int res = 0;

        // dp[i][j] 表示以 matrix[i][j] 为右下角的正方形的最大边长
        // dp[i-1][j] != dp[i][j-1] 时，dp[i][j] = min({dp[i-1][j], dp[i][j-1]})
        // dp[i-1][j] == dp[i][j-1] = k 时，dp[i][j] = min({k, dp[i-1][j-1]}) + 1
        //     k > dp[i-1][j-1], dp[i][j] = dp[i-1][j-1] + 1
        //     k <= dp[i-1][j-1], dp[i][j] = k + 1
        // dp[i-1][j] != dp[i][j-1] = k 时，dp[i][j] = min({dp[i-1][j], dp[i][j-1]})
        // + 1

        auto dp = vector<vector<int>>(m, vector<int>(n));
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        if (dp[i - 1][j] == dp[i][j - 1]) {
                            dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                        } else {
                            dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1]}) + 1;
                        }
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    cout << s.countSquares({{0, 1, 1, 1},
                            {1, 1, 1, 1},
                            {0, 1, 1, 1}})
         << endl;
    return 0;
}
