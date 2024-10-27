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
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        auto res = vector<ListNode *>();
        auto dq = deque({tree});
        while (!dq.empty()) {
            const auto size = dq.size();
            auto front = dq.front();
            dq.pop_front();
            res.push_back(new ListNode(front->val));
            if (front->left) { dq.push_back(front->left); }
            if (front->right) { dq.push_back(front->right); }

            auto head = res.back();

            for (int i = 1; i < size; ++i) {
                front = dq.front();
                dq.pop_front();
                head->next = new ListNode(front->val);
                head = head->next;
                if (front->left) { dq.push_back(front->left); }
                if (front->right) { dq.push_back(front->right); }
            }
        }
        return res;
    }
};

TreeNode *buildTree(const vector<int> &nodes) {
    auto q = queue<TreeNode *>();
    auto root = new TreeNode(nodes[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        auto node = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i++] != -1) {
            node->left = new TreeNode(nodes[i - 1]);
            q.push(node->left);
        }
        if (i < nodes.size() && nodes[i++] != -1) {
            node->right = new TreeNode(nodes[i - 1]);
            q.push(node->right);
        }
    }
    return root;
}


int main() {
    auto root = buildTree({1, 2, 3, 4, 5, -1, 7, 8});
    auto res = Solution().listOfDepth(root);
    return 0;
}
