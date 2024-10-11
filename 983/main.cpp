#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int MAX_COST = 365 * 1000;

public:
    int mincostTickets(const vector<int> &days, const vector<int> &costs) {
        // dp[i][j] 表示到 days[i] 天，通行证剩余 j 天的最小花费
        auto dp = vector<vector<int>>(days.size(), vector<int>(30, MAX_COST));
        dp[0][0] = costs[0];
        dp[0][6] = costs[1];
        dp[0][29] = costs[2];

        for (int i = 1; i < days.size(); i++) {
            auto prevDay = days[i - 1], nextDay = days[i];
            auto diff = nextDay - prevDay;

            // 不买票
            for (int j = 0; j + diff < 30; j++) {
                dp[i][j] = std::min({dp[i][j], dp[i - 1][j + diff]});
            }

            // 买票
            int minCost = *std::min_element(dp[i - 1].begin(), dp[i - 1].end());
            dp[i][0] = std::min({dp[i][0], minCost + costs[0]});
            dp[i][6] = std::min({dp[i][6], minCost + costs[1]});
            dp[i][29] = std::min({dp[i][29], minCost + costs[2]});
        }
        return *std::min_element(dp.back().begin(), dp.back().end());
    }
};

int main() {
    auto s = Solution();
    cout << s.mincostTickets({1, 4, 6, 7, 8, 20}, {2, 7, 15});
    return 0;
}
