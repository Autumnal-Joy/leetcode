#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const auto n = static_cast<int>(nums.size());
        auto dp = vector<int>(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            auto maxVal = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    maxVal = std::max({maxVal, dp[j] + 1});
                }
            }
            dp[i] = maxVal;
        }
        return ranges::max(dp);
    }
};

int main() {

    return 0;
}
