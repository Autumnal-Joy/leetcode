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
TreeNode *vec2tree(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    queue<TreeNode *> q;
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        TreeNode *node = q.front();
        q.pop();
        if (vec[i] != -1) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != -1) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vec2list(const vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}
#endif

#ifdef LEETCODE
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
#endif

class Solution {
public:
    Node *flatten(Node *head) {
        auto p = head;
        Node *tail = nullptr;
        auto st = stack<Node *>();
        while (p || !st.empty()) {
            if (!p) {
                p = st.top();
                st.pop();
                if (p->next) {
                    p->next->prev = tail;
                }
                tail->next = p->next;
                p->child->prev = p;
                p->next = p->child;
                p->child = nullptr;
                tail = p;
                p = p->next;
            } else if (p->child) {
                st.push(p);
                p = p->child;
            } else {
                tail = p;
                p = p->next;
            }
        }
        return head;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif