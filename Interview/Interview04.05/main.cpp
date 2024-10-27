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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    bool res = true;
    long long prev = numeric_limits<long long>::min();

    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        if (root->val <= prev) res = false;
        prev = root->val;
        dfs(root->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        dfs(root);
        return res;
    }
};

int main() {

    return 0;
}
