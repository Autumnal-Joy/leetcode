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
    auto q = queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        auto node = q.front();
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

class Solution {
public:
    bool checkInclusion(const string &s1, const string &s2) {
        const auto m = static_cast<int>(s1.size());
        const auto n = static_cast<int>(s2.size());
        if (s1.size() > s2.size()) return false;
        auto cnt_s1 = array<int, 26>{};
        auto cnt_s2 = array<int, 26>{};
        for (const auto &c: s1) {
            ++cnt_s1[c - 'a'];
        }
        for (int left = 0, right = 0; right < n;) {
            ++cnt_s2[s2[right] - 'a'];
            ++right;
            if (right - left > m) {
                --cnt_s2[s2[left] - 'a'];
                ++left;
            }
            if (right - left == m && cnt_s1 == cnt_s2) {
                return true;
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
