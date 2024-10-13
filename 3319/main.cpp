#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> count;
    pair<bool, int> isPerfect(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }
        auto [left, leftCount] = isPerfect(root->left);
        auto [right, rightCount] = isPerfect(root->right);
        if (!left || !right || leftCount != rightCount) {
            return {false, 0};
        }
        count.push_back(leftCount + 1);
        return {true, leftCount + 1};
    }
    int kthLargestPerfectSubtree(TreeNode *root, int k) {
        isPerfect(root);
        std::sort(count.begin(), count.end(), std::greater<>());
        return count.size() >= k ? (1 << count[k - 1]) - 1 : -1;
    }
};

int main() {
    Solution s;
    s.kthLargestPerfectSubtree(new TreeNode(1), 1);
    return 0;
}
