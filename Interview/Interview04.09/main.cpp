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
    vector<vector<int>> res;
    vector<int> path;

    void dfs(deque<TreeNode *> &dq) {
        if (dq.empty()) {
            res.push_back(path);
        }
        auto n = static_cast<int>(dq.size());
        for (int i = 0; i < n; ++i) {
            auto front = dq.front();
            dq.pop_front();

            path.push_back(front->val);
            if (front->left) dq.push_back(front->left);
            if (front->right) dq.push_back(front->right);

            dfs(dq);

            if (front->right) dq.pop_back();
            if (front->left) dq.pop_back();
            path.pop_back();

            dq.push_back(front);
        }
    }

public:
    vector<vector<int>> BSTSequences(TreeNode *root) {
        if (!root) {
            return {{}};
        }
        auto dq = deque({root});
        dfs(dq);
        return res;
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
    auto root = buildTree({33, 14, 40, -1, 27, -1, 73, -1, -1, 47, 74, -1, 48, -1, 88, -1, -1, -1, 89});
    auto res = Solution().BSTSequences(root);
    return 0;
}
