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
TreeNode *vec2tree(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    queue<TreeNode *> q;
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        TreeNode *node = q.front();
        q.pop();
        if (vec[i] != -1) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != -1) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vec2list(const vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}
#endif

class Solution {
public:
    int largestRectangleArea(const vector<int> &heights) {
        const auto n = static_cast<int>(heights.size());
        auto res = 0;
        auto rightMinimal = vector(n, n);
        auto leftMinimal = vector(n, -1);
        auto rightStack = stack<int>();
        auto leftStack = stack<int>();
        for (int i = 0; i < n; ++i) {
            while (!rightStack.empty() && heights[i] < heights[rightStack.top()]) {
                rightMinimal[rightStack.top()] = i;
                rightStack.pop();
            }
            rightStack.push(i);

            auto k = n - i - 1;
            while (!leftStack.empty() && heights[k] < heights[leftStack.top()]) {
                leftMinimal[leftStack.top()] = k;
                leftStack.pop();
            }
            leftStack.push(k);
        }

        for (int j = 0; j < n; ++j) {
            const auto left = leftMinimal[j] + 1;
            const auto right = rightMinimal[j] - 1;
            res = std::max({res, heights[j] * (right - left + 1)});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    return 0;
}
#endif