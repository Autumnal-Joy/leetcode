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
    void preorder(const TreeNode *tree, vector<string> &v) {
        if (!tree) {
            v.emplace_back();
            return;
        }
        v.push_back(std::to_string(tree->val));
        preorder(tree->left, v);
        preorder(tree->right, v);
    }

    vector<int> buildPrefixTable(const vector<string> &pattern) {
        const int n = static_cast<int>(pattern.size());
        auto prefix = vector(n, 0);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) j = prefix[j - 1];
            if (pattern[i] == pattern[j]) ++j;
            prefix[i] = j;
        }
        return prefix;
    }
    bool KMP(const vector<string> &text, const vector<string> &pattern) {
        vector<string> result;
        const int n = static_cast<int>(text.size());
        const int m = static_cast<int>(pattern.size());
        if (m == 0) return true;
        const auto prefix = buildPrefixTable(pattern);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j]) j = prefix[j - 1];
            if (text[i] == pattern[j]) ++j;
            if (j == m) {
                return true;
            }
        }
        return false;
    }

public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        auto v1 = vector<string>();
        auto v2 = vector<string>();
        preorder(t1, v1);
        preorder(t2, v2);
        return KMP(v1, v2) && KMP(v1, v2);
    }
};

int main() {

    return 0;
}
