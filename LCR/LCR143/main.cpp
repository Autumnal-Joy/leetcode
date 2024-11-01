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
    bool match(TreeNode *A, TreeNode *B) {
        if (!A || !B) return false;
        bool flag = false;
        if (A->val == B->val) {
            flag = true;
            if (B->left) {
                flag &= match(A->left, B->left);
            }
            if (B->right) {
                flag &= match(A->right, B->right);
            }
        }
        return flag;
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!A || !B) return false;
        return match(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
