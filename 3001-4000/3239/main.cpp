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
        auto cnt_row = 0, cnt_col = 0;
        for (int i = 0; i < m; ++i) {
            for (int begin = 0, end = n - 1; begin < end; ++begin, --end) {
                if (grid[i][begin] != grid[i][end]) {
                    ++cnt_row;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int begin = 0, end = m - 1; begin < end; ++begin, --end) {
                if (grid[begin][i] != grid[end][i]) {
                    ++cnt_col;
                }
            }
        }
        return std::min({cnt_col, cnt_row});
    }
};

#ifdef LEETCODE
int main() {
    auto grid = vector<vector<int>>({
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 1},
    });
    cout << Solution().minFlips(grid) << endl;
    return 0;
}
#endif
