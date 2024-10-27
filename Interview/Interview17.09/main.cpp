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
    int getKthMagicNumber(int k) {
        auto dp = vector<int>(k);
        dp[0] = 1;
        auto p3 = 0, p5 = 0, p7 = 0;
        for (int i = 1; i < k; ++i) {
            auto t1 = dp[p3] * 3, t2 = dp[p5] * 5, t3 = dp[p7] * 7;
            const auto minVal = std::min({t1, t2, t3});
            if (t1 == minVal) p3++;
            if (t2 == minVal) p5++;
            if (t3 == minVal) p7++;
            dp[i] = minVal;
        }
        return dp[k - 1];
    }
};

int main() {
    Solution().getKthMagicNumber(10);
    return 0;
}
