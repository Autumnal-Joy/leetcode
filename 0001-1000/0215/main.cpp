#ifdef LEETCODE
#include <bits/stdc++.h>
#include <span>

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
    int findK(const span<int> &nums, const int k) {
        if (nums.size() == 1) return nums[0];
        const auto m = static_cast<int>(nums.size()) / 2;
        const auto pivot = nums[m];
        nums[m] = nums[0];
        auto i = 0, j = static_cast<int>(nums.size()) - 1;
        while (i != j) {
            while (i != j && nums[j] < pivot) --j;
            if (i != j) nums[i++] = nums[j];
            while (i != j && nums[i] > pivot) ++i;
            if (i != j) nums[j--] = nums[i];
        }
        nums[i] = pivot;
        if (i < k - 1) {
            return findK(nums.subspan(i + 1), k - i - 1);
        }
        if (i == k - 1) {
            return pivot;
        }
        return findK(nums.subspan(0, i), k);
    }

public:
    int findKthLargest(vector<int> &nums, const int k) {
        const auto sp = span(nums.begin(), nums.end());
        return findK(sp, k);
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({-1, 2, 0});
    auto res = Solution().findKthLargest(nums, 2);
    return 0;
}
#endif
