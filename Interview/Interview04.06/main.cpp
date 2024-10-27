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
    vector<TreeNode *> path;
    size_t loc = 0;

    void inorder(TreeNode *root, TreeNode *p) {
        if (!root) { return; }
        inorder(root->left, p);

        path.push_back(root);
        if (root == p) {
            loc = path.size();
        }

        inorder(root->right, p);
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        inorder(root, p);
        return loc < path.size() ? path[loc] : nullptr;
    }
};


TreeNode *buildTree(const vector<int> &nodes) {
    auto q = queue<TreeNode *>();
    auto root = new TreeNode(nodes[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        auto node = q.front();
        q.pop();
        if (nodes[i++] != -1) {
            node->left = new TreeNode(nodes[i - 1]);
            q.push(node->left);
        }
        if (nodes[i++] != -1) {
            node->right = new TreeNode(nodes[i - 1]);
            q.push(node->right);
        }
    }
    return root;
}

int main() {
    auto root = buildTree({5, 3, 6, 2, 4, -1, -1, 1});
    auto res = Solution().inorderSuccessor(root, root->right);
    return 0;
}
