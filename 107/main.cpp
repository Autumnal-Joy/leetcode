#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) {
            return {};
        }

        queue<TreeNode *> q = queue<TreeNode *>({root, nullptr});

        auto res = vector<vector<int>>();
        auto temp = vector<int>();

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else {
                res.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution s;
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    s.levelOrderBottom(root);
    return 0;
}
