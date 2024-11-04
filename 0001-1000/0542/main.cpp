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
    vector<vector<int>> updateMatrix(const vector<vector<int>> &mat) {
        const auto m = static_cast<int>(mat.size());
        const auto n = static_cast<int>(mat[0].size());
        auto res = vector(mat.size(), vector(mat[0].size(), m + n));
        auto dq = deque<pair<int, int>>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dq.emplace_back(i, j);
                    res[i][j] = 0;
                }
            }
        }
        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();
            if (i - 1 >= 0 && res[i - 1][j] > res[i][j] + 1) {
                res[i - 1][j] = res[i][j] + 1;
                dq.emplace_back(i - 1, j);
            }
            if (i + 1 < m && res[i + 1][j] > res[i][j] + 1) {
                res[i + 1][j] = res[i][j] + 1;
                dq.emplace_back(i + 1, j);
            }
            if (j - 1 >= 0 && res[i][j - 1] > res[i][j] + 1) {
                res[i][j - 1] = res[i][j] + 1;
                dq.emplace_back(i, j - 1);
            }
            if (j + 1 < n && res[i][j + 1] > res[i][j] + 1) {
                res[i][j + 1] = res[i][j] + 1;
                dq.emplace_back(i, j + 1);
            }
        }

        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto mat = vector<vector<int>>({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}});
    auto res = Solution().updateMatrix(mat);
    return 0;
}
#endif
