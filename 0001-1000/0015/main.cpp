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

template<typename T, size_t N>
class HashArray {
public:
    size_t operator()(const array<T, N> &arr) const {
        return std::reduce(arr.begin(), arr.end(), size_t{}, [hasher = hash<T>()](const size_t seed, const T &val) {
            return seed ^ hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        });
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        const auto n = static_cast<int>(nums.size());
        ranges::sort(nums);
        auto res = vector<vector<int>>();
        auto s1 = unordered_set<int>();
        for (int i = 0; i < n; ++i) {
            if (s1.contains(nums[i])) continue;
            s1.insert(nums[i]);
            auto p1 = i + 1, p2 = n - 1;
            while (p1 < p2) {
                if (p1 != i + 1 && nums[p1] == nums[p1 - 1]) {
                    ++p1;
                } else {
                    if (nums[p1] + nums[p2] == -nums[i]) {
                        res.push_back({nums[i], nums[p1], nums[p2]});
                        ++p1;
                    } else if (nums[p1] + nums[p2] > -nums[i]) {
                        --p2;
                    } else {
                        ++p1;
                    }
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({-4, -1, -1, 0, 1, 2});
    Solution().threeSum(nums);
    return 0;
}
#endif
