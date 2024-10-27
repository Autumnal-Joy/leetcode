#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    static TreeNode *from(vector<int> tree) {
        if (tree.empty()) {
            return nullptr;
        }
        auto root = new TreeNode(tree[0]);
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        for (int i = 1; i < tree.size(); i++) {
            if (tree[i] == -1) {
                nodes.push_back(nullptr);
            } else {
                auto node = new TreeNode(tree[i]);
                nodes.push_back(node);
                if (i % 2 == 1) {
                    nodes[(i - 1) / 2]->left = node;
                } else {
                    nodes[(i - 1) / 2]->right = node;
                }
            }
        }
        return root;
    }
};

struct DTreeNode {
    int val;
    DTreeNode *left;
    DTreeNode *right;
    DTreeNode *parent;

    explicit DTreeNode(int x, DTreeNode *parent)
        : val(x), left(nullptr), right(nullptr), parent(parent) {}
};

class Solution {
public:
    vector<int> results;

    DTreeNode *buildDTree(TreeNode *root, DTreeNode *parent, TreeNode *target,
                          DTreeNode *&targetD) {
        if (root == nullptr) {
            return nullptr;
        }
        auto node = new DTreeNode(root->val, parent);
        if (root == target) {
            targetD = node;
        }
        node->left = buildDTree(root->left, node, target, targetD);
        node->right = buildDTree(root->right, node, target, targetD);
        return node;
    }

    void search(DTreeNode *node, int k, DTreeNode *from) {
        if (node == nullptr) {
            return;
        }
        if (k == 0) {
            results.push_back(node->val);
            return;
        }
        if (node->left != from) {
            search(node->left, k - 1, node);
        }
        if (node->right != from) {
            search(node->right, k - 1, node);
        }
        if (node->parent != from) {
            search(node->parent, k - 1, node);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        DTreeNode *targetD = nullptr;
        buildDTree(root, nullptr, target, targetD);
        search(targetD, k, nullptr);
        return results;
    }
};

int main() {
    auto s = Solution();
    TreeNode *tree = TreeNode::from({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    if (!tree) {
        exit(1);
    }
    auto results = s.distanceK(tree, tree->left, 2);
    std::copy(results.begin(), results.end(),
              std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
