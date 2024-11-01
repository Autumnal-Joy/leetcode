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
#endif

class Solution {
public:
    int longestConsecutive(const vector<int> &nums) {
        auto s = unordered_set<int>();
        auto visited = unordered_set<int>();
        for (auto num: nums) {
            s.insert(num);
        }
        auto res = 0;
        for (const auto num: nums) {
            if (s.contains(num - 1)) continue;
            auto cnt = 1, next = num + 1;
            while (s.contains(next)) {
                ++cnt, ++next;
            }
            res = std::max({res, cnt});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
