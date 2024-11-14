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
    auto q = queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        auto node = q.front();
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
    static array<char, 21> encode(unsigned num) {
        auto res = array<char, 21>{};
        for (int i = 0; num; ++i) {
            auto [quo, rem] = std::lldiv(num, 3);
            res[i] = rem;
            num = quo;
        }
        return res;
    }
    static unsigned decode(const array<char, 21> &bits) {
        unsigned res = 0;
        for (int i = 20; i >= 0; --i) {
            res *= 3;
            res += bits[i];
        }
        return res;
    }

public:
    int singleNumber(vector<int> &nums) {
        auto sum = array<char, 21>{};
        for (const auto &num: nums) {
            auto bits = encode(num);
            for (int i = 0; i < 21; ++i) {
                sum[i] += bits[i];
                sum[i] %= 3;
            }
        }
        return static_cast<int>(decode(sum));
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector{2, 2, 2, -1};
    Solution().singleNumber(nums);
    return 0;
}
#endif
