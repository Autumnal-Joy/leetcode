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
    bool searchMatrix(const vector<vector<int>> &matrix, const int target) {
        if (matrix.empty()) return false;
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            while (i < m && matrix[i][j] < target) ++i;
            while (i < m && j >= 0 && matrix[i][j] > target) --j;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
