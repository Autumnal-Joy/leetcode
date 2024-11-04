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
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        auto res = 1;
        if (i - 1 >= 0) res += dfs(grid, i - 1, j);
        if (i + 1 < grid.size()) res += dfs(grid, i + 1, j);
        if (j - 1 >= 0) res += dfs(grid, i, j - 1);
        if (j + 1 < grid[0].size()) res += dfs(grid, i, j + 1);
        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        auto res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                res = std::max({res, dfs(grid, i, j)});
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
