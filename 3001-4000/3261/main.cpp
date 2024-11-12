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

namespace BinarySearch {
    template<std::predicate<const int> Pred>
    static int last(int left, int right, Pred pred) {
        while (left + 1 < right) {
            const int mid = left + (right - left) / 2;
            if (pred(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
    template<std::predicate<const int> Pred>
    static int first(int left, int right, Pred pred) {
        while (left + 1 < right) {
            const int mid = left + (right - left) / 2;
            if (pred(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
}// namespace BinarySearch

class Solution {
public:
    vector<long long> countKConstraintSubstrings(const string &s, const int k, vector<vector<int>> &queries) {
        const auto n = static_cast<int>(s.size());
        auto pre0 = vector(n, 0);
        auto pre1 = vector(n, 0);
        pre0[0] = s[0] == '0', pre1[0] = s[0] == '1';
        for (int i = 1; i < n; ++i) {
            pre0[i] = pre0[i - 1] + (s[i] == '0');
            pre1[i] = pre1[i - 1] + (s[i] == '1');
        }
        auto maxRight = vector(n, 0);
        auto preSum = vector(n, 0ll);
        for (int i = 0; i < n; ++i) {
            auto pred = [&](const int j) {
                const auto cnt0 = pre0[j] - (i - 1 >= 0 ? pre0[i - 1] : 0);
                const auto cnt1 = pre1[j] - (i - 1 >= 0 ? pre1[i - 1] : 0);
                return cnt0 <= k || cnt1 <= k;
            };
            maxRight[i] = BinarySearch::last(i - 1, n, pred);
            preSum[i] = (i - 1 >= 0 ? preSum[i - 1] : 0ll) + maxRight[i] - i + 1;
        }
        auto res = vector<long long>(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            const auto l = queries[i][0], r = queries[i][1];
            auto pred = [&](const int j) {
                return maxRight[j] <= r;
            };
            const auto r_edge = BinarySearch::last(l - 1, r + 1, pred);
            if (r_edge >= l) {
                res[i] += preSum[r_edge] - (l - 1 >= 0 ? preSum[l - 1] : 0);
            }
            res[i] += 1ll * (r - r_edge) * (r - r_edge + 1) / 2;
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto s = string("00");
    constexpr auto k = 1;
    auto queries = vector<vector<int>>({
            {0, 0},
            {1, 1},
            {0, 1},
    });
    Solution().countKConstraintSubstrings(s, k, queries);
    return 0;
}
#endif
