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

class Trie {
public:
    array<Trie *, 2> children{};
    bool isEndOfWord = false;
    int val{};

    void insert(const int num) {
        const auto &word = bitset<32>(num).to_string();
        auto node = this;
        for (int i = 31; i >= 0; --i) {
            const auto bit = num >> i & 1;
            if (!node->children[bit]) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
        node->isEndOfWord = true;
        node->val = num;
    }
};

ostream &operator<<(ostream &os, const Trie &trie) {
    if (trie.isEndOfWord) {
        os << trie.val << endl;
    }
    for (const auto child: trie.children) {
        if (child) {
            os << *child;
        }
    }
    return os;
}

class Solution {
public:
    static int findMaximumXOR(const vector<int> &nums) {
        auto trie = Trie();
        for (const auto num: nums) {
            trie.insert(num);
        }
        auto res = 0;
        for (const auto num: nums) {
            auto node = &trie;
            for (int i = 31; i >= 0; --i) {
                if (const auto bit = num >> i & 1;
                    node->children[1 - bit]) {
                    node = node->children[1 - bit];
                } else {
                    node = node->children[bit];
                }
            }
            res = std::max({res, num ^ node->val});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto nums = vector({3, 10, 5, 25, 2, 8});
    cout << Solution::findMaximumXOR(nums) << endl;
    return 0;
}
#endif
