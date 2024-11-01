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
    bool dfs(const vector<int> &postorder, const int begin, const int end) {
        if (end - begin <= 2) {
            return true;
        }
        auto mid = begin;
        while (mid < end - 1 && postorder[mid] < postorder[end - 1]) {
            ++mid;
        }
        for (int i = mid + 1; i < end - 1; ++i) {
            if (postorder[i] < postorder[end - 1]) {
                return false;
            }
        }
        return dfs(postorder, begin, mid) &&
               dfs(postorder, mid, end - 1);
    }

public:
    bool verifyTreeOrder(const vector<int> &postorder) {
        const auto n = static_cast<int>(postorder.size());
        return dfs(postorder, 0, n);
    }
};

#ifdef LEETCODE
int main() {
    auto postorder = vector({1, 2, 5, 10, 6, 9, 4, 3});
    Solution().verifyTreeOrder(postorder);
    return 0;
}
#endif
