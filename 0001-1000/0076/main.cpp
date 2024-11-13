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

class Solution {
    static bool contains(const array<int, 128> &cnt_s, const array<int, 128> &cnt_t) {
        for (int i = 'A'; i <= 'Z'; ++i) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; ++i) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(const string_view &s, const string_view &t) {
        if (s.size() < t.size()) return "";
        auto cnt_s = array<int, 128>{};
        auto cnt_t = array<int, 128>{};
        for (const auto &c: t) {
            ++cnt_t[c];
        }
        const auto n = static_cast<int>(s.size());
        auto res = string_view();
        for (int left = 0, right = 0; right < n;) {
            ++cnt_s[s[right]];
            ++right;
            while (contains(cnt_s, cnt_t)) {
                if (res.empty() || res.size() > right - left) {
                    res = s.substr(left, right - left);
                }
                --cnt_s[s[left]];
                ++left;
            }
        }
        return {res.begin(), res.end()};
    }
};

#ifdef LEETCODE
int main() {
    auto s = string("ADOBECODEBANC");
    auto t = string("ABC");
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}
#endif
