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
    int res = 0;

    void dfs(TreeNode *node, int sum, unordered_map<int, int> &mp, int target) {
        res += mp[sum + node->val - target];
        ++mp[sum + node->val];
        if (node->left) {
            dfs(node->left, sum + node->val, mp, target);
        }
        if (node->right) {
            dfs(node->right, sum + node->val, mp, target);
        }
        --mp[sum + node->val];
    }

public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        // mp[i] 表示从根节点出发的路径和为 i 的路径数
        auto mp = unordered_map<int, int>();
        mp[0] = 1;
        dfs(root, 0, mp, sum);
        return res;
    }
};

int main() {
    auto nodes = vector<int>({1});
    auto q = queue<TreeNode *>();
    auto root = new TreeNode(nodes[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        auto node = q.front();
        q.pop();
        if (nodes[i++] != -1) {
            node->left = new TreeNode(nodes[i - 1]);
            q.push(node->left);
        }
        if (nodes[i++] != -1) {
            node->right = new TreeNode(nodes[i - 1]);
            q.push(node->right);
        }
    }

    cout << Solution().pathSum(root, 0) << endl;
    return 0;
}
