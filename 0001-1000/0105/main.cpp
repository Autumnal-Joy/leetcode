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
    TreeNode *build(vector<int> &preorder, const int begin1, const int end1,
                    vector<int> &inorder, const int begin2, const int end2) {
        if (begin1 == end1) return nullptr;
        const auto root = new TreeNode(preorder[begin1]);
        auto mid = begin2;
        while (inorder[mid] != preorder[begin1]) {
            ++mid;
        }
        root->left = build(preorder, begin1 + 1, begin1 + 1 + mid - begin2,
                           inorder, begin2, mid);
        root->right = build(preorder, begin1 + 1 + mid - begin2, end1,
                            inorder, mid + 1, end2);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
