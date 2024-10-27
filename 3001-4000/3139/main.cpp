#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    long long MOD = 1e9 + 7;

public:
    int minCostToEqualizeArray(vector<int> &nums, int cost1, int cost2) {
        auto n = static_cast<int>(nums.size());
        auto [m, M] = ranges::minmax(nums);
        if (2 * cost1 <= cost2) {
            return static_cast<int>((1ll * M * n - std::accumulate(nums.begin(), nums.end(), 0ll)) * cost1 % MOD);
        }
        if (nums.size() == 2) {
            return static_cast<int>(1ll * (M - m) * cost1 % MOD);
        }
        auto sum = accumulate(nums.begin(), nums.end(), 0ll);
        long long res = numeric_limits<long long>::max();
        for (int x = M; x <= 2 * M; ++x) {
            auto s = 1ll * n * x - sum;
            auto d = x - m;
            if (d <= s - d) {
                res = std::min({res, s / 2 * cost2 + (s & 1) * cost1});
            } else {
                res = std::min({res, (2 * d - s) * cost1 + (s - d) * cost2});
            }
        }
        return static_cast<int>(res % MOD);
    }
};

int main() {
    auto s = Solution();
    auto nums = vector<int>({1, 14, 14, 15});
    cout << s.minCostToEqualizeArray(nums, 2, 1) << endl;
    return 0;
}
