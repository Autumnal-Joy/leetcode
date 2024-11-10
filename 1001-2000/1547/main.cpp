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
    int minCost(const int n, vector<int> &cuts) {
        ranges::sort(cuts);
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        const auto m = static_cast<int>(cuts.size());
        // dp[i][j] 表示木棍长度从 cuts[i] 到 cuts[j] 的最小分割花费
        auto dp = vector(m, vector(m, 0));
        for (int len = 2; len < m; ++len) {
            for (int i = 0; i + len < m; ++i) {
                // 求 dp[i][i+len]，对应的木棍长度为 [cuts[i], cuts[i+len]]
                auto minCost = numeric_limits<int>::max();
                for (int j = i + 1; j < i + len; ++j) {
                    minCost = std::min({minCost, dp[i][j] + dp[j][i + len]});
                }
                dp[i][i + len] = minCost + cuts[i + len] - cuts[i];
            }
        }
        return dp[0][m - 1];
    }
};

#ifdef LEETCODE
int main() {
    auto cuts = vector({5, 6, 1, 4, 2});
    cout << Solution().minCost(9, cuts) << endl;
    return 0;
}
#endif
