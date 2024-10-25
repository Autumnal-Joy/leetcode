#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 返回 node 子树内，和为 sum 的路径数量
    // 以 node 出发的路径 + dfs左子树 + dfs右子树
    int dfs(TreeNode *node, unordered_map<TreeNode *, unordered_map<int, int>> &mp, int target) {
        auto res = 0;
        if (node->left) {
            res += dfs(node->left, mp, target);
        }
        if (node->right) {
            res += dfs(node->right, mp, target);
        }
        mp[node][node->val] = 1;
        for (auto &[sum, cnt]: mp[node->left]) {
            mp[node][sum + node->val] += cnt;
        }
        for (auto &[sum, cnt]: mp[node->right]) {
            mp[node][sum + node->val] += cnt;
        }

        return res + mp[node][target];
    }

public:
    int pathSum(TreeNode *root, int sum) {
        // mp[node][sum] 表示从 node 出发，和为 sum 的路径数量
        auto mp = unordered_map<TreeNode *, unordered_map<int, int>>();
        return root ? dfs(root, mp, sum) : 0;
    }
};

int main() {
    auto root = new TreeNode(1);
    cout << Solution().pathSum(root, 1) << endl;
    return 0;
}
