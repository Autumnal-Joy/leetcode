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
    int uniquePaths(int m, int n) {
        long long res = 1;
        for (int i = m, j = 1; j < n; ++i, ++j) {
            res = res * i / j;
        }
        return static_cast<int>(res);
    }
};

#ifdef LEETCODE
int main() {
    Solution().uniquePaths(3, 7);
    return 0;
}
#endif
