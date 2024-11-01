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
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> decorateRecord(TreeNode *root) {
        auto res = vector<int>();
        if (!root) {
            return res;
        }
        auto dq = deque<TreeNode *>();
        dq.push_back(root);
        while (!dq.empty()) {
            int n = static_cast<int>(dq.size());
            while (n--) {
                const auto front = dq.front();
                dq.pop_front();
                res.push_back(front->val);
                if (front->left) {
                    dq.push_back(front->left);
                }
                if (front->right) {
                    dq.push_back(front->right);
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
