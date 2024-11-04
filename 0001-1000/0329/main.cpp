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
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo) {
        if (memo[i][j] == 0) {
            memo[i][j] = 1;
            if (i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j]) {
                memo[i][j] = std::max({memo[i][j], dfs(matrix, i - 1, j, memo) + 1});
            }
            if (i + 1 < matrix.size() && matrix[i][j] > matrix[i + 1][j]) {
                memo[i][j] = std::max({memo[i][j], dfs(matrix, i + 1, j, memo) + 1});
            }
            if (j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1]) {
                memo[i][j] = std::max({memo[i][j], dfs(matrix, i, j - 1, memo) + 1});
            }
            if (j + 1 < matrix[0].size() && matrix[i][j] > matrix[i][j + 1]) {
                memo[i][j] = std::max({memo[i][j], dfs(matrix, i, j + 1, memo) + 1});
            }
        }
        return memo[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        const auto m = static_cast<int>(matrix.size());
        const auto n = static_cast<int>(matrix[0].size());
        auto memo = vector(m, vector(n, 0));
        auto res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = std::max({res, dfs(matrix, i, j, memo)});
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
