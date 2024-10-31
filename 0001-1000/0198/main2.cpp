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

class Solution {
public:
    int rob(const vector<int> &nums) {
        // dp[i] 表示 [0,i) 能偷到的最大值
        // prev[i] 表示 [0,i) 最大值时偷的最后一个房子的下标
        auto dp = vector(nums.size() + 1, 0);
        auto prev = vector(nums.size() + 1, -1);
        if (nums[0]) {
            dp[1] = nums[0];
            prev[1] = 0;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (prev[i] == i - 1 && dp[i - 1] + nums[i] < dp[i]) {
                dp[i + 1] = dp[i];
                prev[i + 1] = i - 1;
            } else {
                dp[i + 1] = dp[i - 1] + nums[i];
                prev[i + 1] = i;
            }
        }
        return dp[nums.size()];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
