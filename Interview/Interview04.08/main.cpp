#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode *res = nullptr;
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return 0;
        }
        auto cnt = (root == p) + (root == q) +
                   dfs(root->left, p, q) +
                   dfs(root->right, p, q);
        if (!res && cnt == 2) {
            res = root;
        }
        return cnt;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }
};

int main() {

    return 0;
}
