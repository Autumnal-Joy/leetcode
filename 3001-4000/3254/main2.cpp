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
    vector<int> resultsArray(vector<int> &nums, int k) {
        const auto n = static_cast<int>(nums.size());
        auto res = vector<int>();
        auto cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (i == 0 || nums[i] == nums[i - 1] + 1) {
                ++cnt;
            } else {
                cnt = 1;
            }
        }
        if (cnt == k) {
            res.push_back(nums[k - 1]);
        } else {
            res.push_back(-1);
        }
        for (int i = k; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                cnt = std::min({cnt + 1, k});
            } else {
                cnt = 1;
            }
            if (cnt == k) {
                res.push_back(nums[i]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
