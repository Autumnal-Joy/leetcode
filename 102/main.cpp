#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root)
            return {};

        vector<vector<int>> res;
        auto q = queue<TreeNode *>({root});
        while (!q.empty()) {
            auto n = q.size();
            auto temp = vector<int>();
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(std::move(temp));
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
