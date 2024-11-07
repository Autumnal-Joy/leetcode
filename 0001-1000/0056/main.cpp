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
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        auto ls = list<pair<int, int>>();
        ranges::sort(intervals, [](const auto &a, const auto &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for (const auto &interval: intervals) {
            ls.emplace_back(interval[0], interval[1]);
        }
        auto it = ls.begin();
        while (it != ls.end()) {
            auto next = std::next(it);
            while (next != ls.end() && next->first <= it->second) {
                it->second = max(it->second, next->second);
                next = ls.erase(next);
            }
            ++it;
        }
        auto res = vector<vector<int>>();
        for (const auto &p: ls) {
            res.emplace_back(vector({p.first, p.second}));
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto intervals = vector<vector<int>>({
            {1, 2},
            {1, 3},
            {2, 6},
            {8, 10},
            {15, 18},
    });
    auto res = Solution().merge(intervals);
    return 0;
}
#endif
