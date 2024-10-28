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
    int maxScore(int n, int k, vector<vector<int>> &stayScore, vector<vector<int>> &travelScore) {
        // dp[i][j] 表示第 i 天在第 j 个城市的最大分数
        auto dp = vector(k, vector(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[0][j] = stayScore[0][j];
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dp[0][j] < travelScore[k][j]) {
                    dp[0][j] = travelScore[k][j];
                }
            }
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + stayScore[i][j];
            }
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (dp[i][j] < dp[i - 1][k] + travelScore[k][j]) {
                        dp[i][j] = dp[i - 1][k] + travelScore[k][j];
                    }
                }
            }
        }

        return ranges::max(dp[k - 1]);
    }
};

int main() {

    return 0;
}
