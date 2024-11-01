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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> path;
    vector<vector<int>> res;
    void dfs(const TreeNode *root, const int targetSum) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                res.push_back(path);
            }
        } else {
            if (root->left) dfs(root->left, targetSum - root->val);
            if (root->right) dfs(root->right, targetSum - root->val);
        }
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root) {
            dfs(root, targetSum);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
