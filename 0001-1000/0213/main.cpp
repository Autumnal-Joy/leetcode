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
    int rob00(const vector<int> &nums, const int i, const int j) {
        if (i == j) return 0;
        const auto mid = i + (j - i) / 2;
        return std::max({
                rob00(nums, i, mid) + rob10(nums, mid + 1, j),
                rob01(nums, i, mid) + rob00(nums, mid + 1, j),
        });
    }
    int rob01(const vector<int> &nums, const int i, const int j) {
        if (i == j) return 0;
        const auto mid = i + (j - i) / 2;
        return std::max({
                rob00(nums, i, mid) + rob11(nums, mid + 1, j),
                rob01(nums, i, mid) + rob01(nums, mid + 1, j),
        });
    }
    int rob10(const vector<int> &nums, const int i, const int j) {
        if (i == j) return 0;
        const auto mid = i + (j - i) / 2;
        return std::max({
                rob10(nums, i, mid) + rob10(nums, mid + 1, j),
                rob11(nums, i, mid) + rob00(nums, mid + 1, j),
        });
    }
    int rob11(const vector<int> &nums, const int i, const int j) {
        if (i == j) return nums[i];
        const auto mid = i + (j - i) / 2;
        return std::max({
                rob10(nums, i, mid) + rob11(nums, mid + 1, j),
                rob11(nums, i, mid) + rob01(nums, mid + 1, j),
        });
    }

public:
    int rob(const vector<int> &nums) {
        const auto n = static_cast<int>(nums.size());
        if (n == 1) return nums[0];
        return std::max({
                rob01(nums, 0, n - 1),
                rob10(nums, 0, n - 1),
        });
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
