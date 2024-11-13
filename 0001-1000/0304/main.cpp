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

class NumMatrix {
    vector<vector<int>> sum;

public:
    explicit NumMatrix(const vector<vector<int>> &matrix) : sum(matrix) {
        for (int i = 0; i < sum.size(); ++i) {
            for (int j = 0; j < sum[0].size(); ++j) {
                sum[i][j] += j - 1 >= 0 ? sum[i][j - 1] : 0;
            }
            for (int j = 0; j < sum[0].size(); ++j) {
                sum[i][j] += i - 1 >= 0 ? sum[i - 1][j] : 0;
            }
        }
    }

    int sumRegion(const int row1, const int col1, const int row2, const int col2) const {
        return sum[row2][col2] -
               (col1 - 1 >= 0 ? sum[row2][col1 - 1] : 0) -
               (row1 - 1 >= 0 ? sum[row1 - 1][col2] : 0) +
               (row1 - 1 >= 0 && col1 - 1 >= 0 ? sum[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
