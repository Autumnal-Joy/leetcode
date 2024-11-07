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
    static int findMaximumXOR(const vector<int> &nums) {
        auto res = 0;
        auto seen = unordered_set<int>();
        const unsigned max = ranges::max(nums);
        for (int i = std::bit_width(max); i >= 0; --i) {
            res <<= 1;
            seen.clear();
            const auto target = res + 1;
            for (const auto &num: nums) {
                if (seen.contains(target ^ num >> i)) {
                    res = target;
                    break;
                }
                seen.insert(num >> i);
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto nums = vector({3, 10, 5, 25, 2, 8});
    cout << Solution::findMaximumXOR(nums) << endl;
    return 0;
}
#endif
