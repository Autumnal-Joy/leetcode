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
    int maxCollectedFruits(vector<vector<int>> &fruits) {
        auto n = static_cast<int>(fruits.size());
        auto res = 0;
        for (int i = 0; i < n; ++i) {
            res += fruits[i][i];
            fruits[i][i] = 0;
        }
        // dp[i][j] 表示到(i,j)的最大收集果实数
        auto dp1 = vector(n, vector(n, 0));
        dp1[n - 1][0] = fruits[n - 1][0];
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i + j >= n - 1 && i > j) {
                    dp1[i][j] = std::max({
                                        i - 1 >= 0 ? dp1[i - 1][j - 1] : 0,
                                        dp1[i][j - 1],
                                        i + 1 < n ? dp1[i + 1][j - 1] : 0,
                                }) +
                                fruits[i][j];
                }
            }
        }
        auto dp2 = vector(n, vector(n, 0));
        dp2[0][n - 1] = fruits[0][n - 1];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + j >= n - 1 && i < j) {
                    dp2[i][j] = std::max({
                                        j - 1 >= 0 ? dp2[i - 1][j - 1] : 0,
                                        dp2[i - 1][j],
                                        j + 1 < n ? dp2[i - 1][j + 1] : 0,
                                }) +
                                fruits[i][j];
                }
            }
        }
        return res + dp1[n - 1][n - 2] + dp2[n - 2][n - 1];
    }
};

#ifdef LEETCODE
int main() {
    auto fruits = vector<vector<int>>{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << Solution().maxCollectedFruits(fruits) << endl;
    return 0;
}
#endif
