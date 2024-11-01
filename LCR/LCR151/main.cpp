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
    vector<vector<int>> decorateRecord(TreeNode *root) {
        auto res = vector<vector<int>>();
        if (!root) {
            return res;
        }
        auto dq = deque<TreeNode *>();
        dq.push_back(root);
        int level = 0;
        while (!dq.empty()) {
            res.emplace_back();
            int n = static_cast<int>(dq.size());
            if (level & 1) {
                while (n--) {
                    const auto back = dq.back();
                    dq.pop_back();
                    res.back().push_back(back->val);
                    if (back->right) {
                        dq.push_front(back->right);
                    }
                    if (back->left) {
                        dq.push_front(back->left);
                    }
                }
            } else {
                while (n--) {
                    const auto front = dq.front();
                    dq.pop_front();
                    res.back().push_back(front->val);
                    if (front->left) {
                        dq.push_back(front->left);
                    }
                    if (front->right) {
                        dq.push_back(front->right);
                    }
                }
            }
            ++level;
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
