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
    static bool check(const vector<int> &nums, const int mid) {
        if (mid & 1) {
            return nums[mid] == nums[mid - 1];
        }
        return nums[mid] == nums[mid + 1];
    }

public:
    int singleNonDuplicate(const vector<int> &nums) {
        const auto n = static_cast<int>(nums.size());
        if (nums.size() == 1 || nums[0] != nums[1]) return nums[0];
        // 二分查找连续成对元素的最大下标
        auto left = 0, right = n;
        while (left + 1 < right) {
            if (const auto mid = left + (right - left) / 2;
                check(nums, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
