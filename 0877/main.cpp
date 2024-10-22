#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        auto n = piles.size() >> 1;
        // dp[i][j] 表示第 i (i=0..n-1) 轮后，左边拿走 j (j=0..2i+2)
        // 堆石头的最大分数差
        auto dp = vector<vector<int>>(n, vector<int>(n * 2 + 1, 0));
        dp[0][0] = piles[2 * n - 1] - piles[2 * n - 2];
        dp[0][1] =
                std::max({piles[2 * n - 1] - piles[0], piles[0] - piles[2 * n - 1]});
        dp[0][2] = piles[0] - piles[1];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 2 * i; j++) {
                // 第 i-1 轮之后，piles 剩余 2n-2i 堆石头
                if (j >= 2) {
                    // 拿走左边 2 堆
                    dp[i][j] =
                            std::max({dp[i][j], dp[i - 1][j - 2] + piles[j - 1] - piles[j]});
                }
                if (j >= 1) {
                    // 拿走左右各 1 堆
                    dp[i][j] = std::max(
                            {dp[i][j],
                             dp[i - 1][j - 1] + piles[j + 2 * n - 2 * i - 1] - piles[j],
                             dp[i - 1][j - 1] + piles[j] - piles[j + 2 * n - 2 * i - 1]});
                }
                // 拿走右边 2 堆
                dp[i][j] =
                        std::max({dp[i][j], dp[i - 1][j] + piles[j + 2 * n - 2 * i - 1] -
                                                    piles[j + 2 * n - 2 * i - 2]});
            }
        }
        return *std::max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main() {
    auto s = Solution();
    return 0;
}
