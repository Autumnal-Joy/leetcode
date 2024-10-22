#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *build(vector<int> &list, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(list[mid]);
        root->left = build(list, start, mid);
        root->right = build(list, mid + 1, end);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> list;
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }
        return build(list, 0, list.size());
    }
};

int main() {
    auto s = Solution();
    return 0;
}
