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
    int maxFrequency(const vector<int> &nums, const int k, const int numOperations) {
        if (nums.size() == 1) return 1;
        auto freq = map<long long, long long>();
        for (const auto &num: nums) {
            freq[num]++;
        }
        auto preSum = map<long long, long long>();
        long long prev = -1e10;
        for (auto &[num, cnt]: freq) {
            preSum[num] = preSum[prev] + cnt;
            prev = num;
        }
        long long res = 0;
        for (auto it = freq.begin(); it != freq.end(); it = next(it)) {
            long long num = it->first;
            long long cnt = std::prev(preSum.upper_bound(num + k))->second - std::prev(preSum.lower_bound(num - k))->second;
            res = std::max(res, std::min(cnt, freq[num] + numOperations));
        }
        for (auto left = freq.begin(), right = freq.begin(); right != freq.end();) {
            const auto temp = right->first;
            right = next(right);
            while (temp - left->first > k * 2) {
                left = next(left);
            }
            auto cnt = std::prev(preSum.upper_bound(temp))->second -
                       std::prev(preSum.lower_bound(left->first))->second;
            res = std::max(res, std::min(cnt, 0ll + numOperations));
        }

        return static_cast<int>(res);
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector<int>({5, 64});
    Solution().maxFrequency(nums, 42, 2);
    return 0;
}
#endif
