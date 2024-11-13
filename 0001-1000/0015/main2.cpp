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
    vector<vector<int>> threeSum(const vector<int> &nums) {
        auto s = unordered_set<array<int, 3>, HashArray<int, 3>>();
        auto visited = unordered_set<int>();
        for (int i = 0; i < nums.size(); ++i) {
            if (visited.contains(nums[i])) continue;
            visited.insert(nums[i]);
            auto mp = unordered_map<int, int>();
            for (int j = i + 1; j < nums.size(); ++j) {
                if (i == j) continue;
                if (mp.contains(-nums[i] - nums[j]) &&
                    i != mp[-nums[i] - nums[j]] &&
                    j != mp[-nums[i] - nums[j]]) {
                    auto arr = array{nums[i], nums[j], -nums[i] - nums[j]};
                    ranges::sort(arr);
                    s.insert(arr);
                }
                mp[nums[j]] = j;
            }
        }
        auto res = vector<vector<int>>();
        for (auto array: s) {
            res.push_back({array[0], array[1], array[2]});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
