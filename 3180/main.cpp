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
    int maxTotalReward(vector<int> &rewardValues) {
        const auto n = static_cast<int>(rewardValues.size());
        ranges::sort(rewardValues);
        // dp[i][j] 表示以 [0,i] 是否能获得 j 分
        auto dp = bitset<4000>();
        dp[0] = dp[rewardValues[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = rewardValues[i] - 1; j >= 0; --j) {
                dp[j + rewardValues[i]] = dp[j + rewardValues[i]] | dp[j];
            }
        }

        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (dp.test(i)) {
                return i;
            }
        }
    }
};

int main() {
    auto rewardValues = vector{1, 2000};
    cout << Solution().maxTotalReward(rewardValues) << endl;
    return 0;
}
