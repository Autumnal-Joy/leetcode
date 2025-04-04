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
    vector<bool> col;
    vector<bool> diag;
    vector<bool> anti_diag;
    int res = 0;
    void dfs(int d, int n) {
        if (d == n) ++res;
        for (int i = 0; i < n; ++i) {
            if (!col[i] && !anti_diag[d + i] && !diag[d - i + n - 1]) {
                col[i] = anti_diag[d + i] = diag[d - i + n - 1] = true;
                dfs(d + 1, n);
                col[i] = anti_diag[d + i] = diag[d - i + n - 1] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        col = vector<bool>(n);
        diag = vector<bool>(2 * n - 1);
        anti_diag = vector<bool>(2 * n - 1);
        dfs(0, n);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    return 0;
}
#endif
