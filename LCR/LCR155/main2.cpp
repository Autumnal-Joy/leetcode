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

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
#endif

class Solution {
    vector<Node *> res;
    void inorder(Node *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        res.push_back(root);
        inorder(root->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        inorder(root);
        if (res.empty()) {
            return nullptr;
        }
        res[0]->left = res.back();
        for (int i = 0; i < res.size() - 1; ++i) {
            res[i]->right = res[i + 1];
            res[i + 1]->left = res[i];
        }
        res.back()->right = res[0];
        return res[0];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
