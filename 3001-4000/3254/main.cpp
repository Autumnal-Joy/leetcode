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
    vector<int> resultsArray(const vector<int> &nums, const int k) {
        const auto n = static_cast<int>(nums.size());
        auto res = vector(n - k + 1, -1);
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (i != 0 && nums[i] != nums[i - 1] + 1) {
                cnt = 0;
            }
            ++cnt;
            if (cnt >= k) {
                res[i - k + 1] = nums[i];
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
