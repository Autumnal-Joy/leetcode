#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    unordered_map<TreeNode *, int> dpFalse;
    unordered_map<TreeNode *, int> dpTrue;

    int dfs(TreeNode *node, bool parentRobbed) {
        if (!node) return 0;

        if (!dpFalse[node->left]) {
            dpFalse[node->left] = dfs(node->left, false);
        }
        if (!dpFalse[node->right]) {
            dpFalse[node->right] = dfs(node->right, false);
        }
        auto res = dpFalse[node->left] + dpFalse[node->right];

        if (parentRobbed) {
            return res;
        }

        if (!dpTrue[node->left]) {
            dpTrue[node->left] = dfs(node->left, true);
        }
        if (!dpTrue[node->right]) {
            dpTrue[node->right] = dfs(node->right, true);
        }
        return max(res, node->val + dpTrue[node->left] + dpTrue[node->right]);
    }

public:
    int rob(TreeNode *root) {
        return dfs(root, false);
    }
};

int main() {
    Solution s;
    return 0;
}
