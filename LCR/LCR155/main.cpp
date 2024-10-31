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
    Node *prev = nullptr;
    void inorder(Node *node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        if (prev) {
            prev->right = node;
        }
        node->left = prev;
        prev = node;
        inorder(node->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        if (!root) {
            return nullptr;
        }
        inorder(root);
        auto head = root;
        auto tail = root;
        while (head->left) {
            head = head->left;
        }
        while (tail->right) {
            tail = tail->right;
        }
        head->left = tail;
        tail->right = head;
        return head;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
