#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode *root) {
        if (!root) {
            return -1;
        }
        if (!root->left && !root->right) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }

    void handle(TreeNode *root, int r, int c, int height,
                vector<vector<string>> &res) {
        if (!root) {
            return;
        }
        res[r][c] = std::to_string(root->val);
        if (root->left) {
            handle(root->left, r + 1, c - (1 << (height - r - 1)), height, res);
        }
        if (root->right) {
            handle(root->right, r + 1, c + (1 << (height - r - 1)), height, res);
        }
    }

    vector<vector<string>> printTree(TreeNode *root) {
        int h = height(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        handle(root, 0, (n - 1) / 2, h, res);
        return res;
    }
};

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    auto s = Solution();
    auto res = s.printTree(root);
    return 0;
}
