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

vector<int> manacher1(const string &s) {
    const auto n = static_cast<int>(s.size());
    auto d1 = vector(n, 0);
    for (int i = 0, l = 0, r = -1; i < s.size(); ++i) {
        int k = i > r ? 1 : std::min({r - i + 1, d1[l + r - i]});
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}
vector<int> manacher2(const string &s) {
    const auto n = static_cast<int>(s.size());
    auto d2 = vector(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = i > r ? 0 : std::min({r - i + 1, d2[l + r - i + 1]});
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    return d2;
}

class Solution {
public:
    int countSubstrings(const string &s) {
        auto d1 = manacher1(s);
        auto d2 = manacher2(s);
        return std::reduce(d1.begin(), d1.end(), 0) + std::reduce(d2.begin(), d2.end(), 0);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
