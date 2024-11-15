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
    int minFlips(const vector<vector<int>> &grid) {
        const auto m = static_cast<int>(grid.size());
        const auto n = static_cast<int>(grid[0].size());
        auto res = 0;
        if (m & 1 && n & 1 && grid[m / 2][n / 2] & 1) {
            ++res;
        }
        if (m & 1 || n & 1) {
            auto cnt1 = 0, cnt_diff = 0;
            if (m & 1) {
                for (int i = 0, mid = m / 2; i < n / 2; ++i) {
                    cnt1 += grid[mid][i] + grid[mid][n - 1 - i];
                    cnt_diff += grid[mid][i] != grid[mid][n - 1 - i];
                }
            }
            if (n & 1) {
                for (int i = 0, mid = n / 2; i < m / 2; ++i) {
                    cnt1 += grid[i][mid] + grid[m - 1 - i][mid];
                    cnt_diff += grid[i][mid] != grid[m - 1 - i][mid];
                }
            }
            cnt1 %= 4;
            res += std::max({std::min({cnt1, 4 - cnt1}), cnt_diff});
        }
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                auto cnt = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                res += std::min({cnt, 4 - cnt});
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto grid = vector<vector<int>>({
            {0, 0, 1},
            {0, 0, 1},
            {1, 0, 1},
            {1, 0, 0},
            {0, 1, 1},
    });
    Solution().minFlips(grid);
    return 0;
}
#endif
