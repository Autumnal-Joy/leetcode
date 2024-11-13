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

class Node {
public:
    int val{};
    Node *next{};
    Node() = default;
    explicit Node(int _val) {
        val = _val;
        next = nullptr;
    }
    Node(const int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};
#endif

class Solution {
public:
    Node *insert(Node *head, const int insertVal) {
        const auto node = new Node(insertVal);
        if (!head) {
            head = node;
            head->next = head;
        } else {
            auto min = head->val, max = head->val;
            for (auto p = head->next; p != head; p = p->next) {
                min = std::min({min, p->val});
                max = std::max({max, p->val});
            }
            if (min == max) {
                node->next = head->next;
                head->next = node;
            } else {
                auto p = head;
                while (p->val != max || p->next->val != min) {
                    p = p->next;
                }
                if (p->val > insertVal && insertVal > p->next->val) {
                    while (p->next->val < insertVal) {
                        p = p->next;
                    }
                }
                node->next = p->next;
                p->next = node;
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
