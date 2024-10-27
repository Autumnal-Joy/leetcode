#include <bits/stdc++.h>

using namespace std;

// 7 6 6 5 4 3 1
class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        std::sort(power.begin(), power.end(), std::greater<>());
        auto num2idx = unordered_map<long long, long long>();
        for (int i = 0; i < power.size(); ++i) {
            if (num2idx.find(power[i]) == num2idx.end()) {
                num2idx[power[i]] = i;
            }
        }
        // dp[i] 表示 [0,i) 的最大和
        auto dp = vector<long long>(power.size() + 1, 0);
        for (long long i = 1; i < dp.size(); ++i) {
            long long current = num2idx[power[i - 1]];
            long long prev = current;
            if (num2idx.find(power[i - 1] + 1) != num2idx.end()) {
                prev = num2idx[power[i - 1] + 1];
            }
            if (num2idx.find(power[i - 1] + 2) != num2idx.end()) {
                prev = num2idx[power[i - 1] + 2];
            }
            long long include = dp[prev] + (i - current) * power[i - 1], exclude = dp[i - 1];
            dp[i] = std::max({include, exclude});
        }
        return dp[power.size()];
    }
};

int main() {
    auto s = Solution();
    auto v = vector<int>({9, 9, 8, 8, 8, 7, 7, 7, 7});
    cout << s.maximumTotalDamage(v) << endl;
    return 0;
}
