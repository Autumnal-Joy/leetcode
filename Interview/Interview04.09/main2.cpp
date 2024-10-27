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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

class Solution {
    void buildMap(TreeNode *root, unordered_map<int, TreeNode *> &mp) {
        mp[root->val] = root;
        if (root->left) buildMap(root->left, mp);
        if (root->right) buildMap(root->right, mp);
    }

public:
    vector<vector<int>> BSTSequences(TreeNode *root) {
        if (!root) {
            return {{}};
        }
        auto res = deque<vector<int>>({{root->val}});
        auto nodes = unordered_map<int, TreeNode *>();
        buildMap(root, nodes);
        auto n = static_cast<int>(nodes.size());

        for (int i = 1; i < n; ++i) {
            const auto m = static_cast<int>(res.size());
            for (int j = 0; j < m; ++j) {
                auto arr = res[j];
                auto visited = unordered_map<int, bool>();
                for (const auto node: arr) {
                    visited[node] = true;
                }
                for (int id: arr) {
                    const auto &leftChild = nodes[id]->left,
                               &rightChild = nodes[id]->right;
                    if (leftChild && !visited[leftChild->val]) {
                        auto temp = res[j];
                        temp.push_back(leftChild->val);
                        res.push_back(std::move(temp));
                    }
                    if (rightChild && !visited[rightChild->val]) {
                        auto temp = res[j];
                        temp.push_back(rightChild->val);
                        res.push_back(std::move(temp));
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                res.pop_front();
            }
        }
        return {std::make_move_iterator(res.begin()),
                std::make_move_iterator(res.end())};
    }
};

int main() {
    auto root = buildTree({33, 14, 40, -1, 27, -1, 73, -1, -1, 47, 74, -1, 48, -1, 88, -1, -1, -1, 89});
    auto res = Solution().BSTSequences(root);
    return 0;
}
