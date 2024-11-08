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
    bool containsNearbyAlmostDuplicate(const vector<int> &nums, const int indexDiff,
                                       const int valueDiff) {
        auto s = multiset<int>();
        long long minDiff = 0ll + valueDiff + 1;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = s.upper_bound(nums[i]);
            if (it != s.begin()) {
                minDiff = std::min({minDiff, 0ll + nums[i] - *std::prev(it)});
            }
            if (it != s.end()) {
                minDiff = std::min({minDiff, 0ll + *it - nums[i]});
            }
            if (minDiff <= valueDiff) return true;
            s.insert(it, nums[i]);
            if (i >= indexDiff) {
                s.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {
    Solution s;
    const auto nums = vector({1, 5, 9, 1, 5, 9});
    cout << s.containsNearbyAlmostDuplicate(nums, 2, 3) << endl;
    return 0;
}
#endif
