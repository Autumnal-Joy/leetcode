#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int minCost = 0;

public:
    int maxRemovals(string source, string pattern, vector<int> &targetIndices) {
        // dp[i][j] 表示 pattern[0:j) 是 source[0:i) 的子序列的最大删除次数
        // del 表示 source[i] 是否可删除
        // 当 source[i] == pattern[j] 时，最优解是匹配的子序列是否包含第 i 个字符，形成的两种分支情况的最大值
        // dp[i + 1][j + 1] = max{dp[i][j], del + dp[i][j + 1]}
        // 当 source[i] != pattern[j] 时，可以贪心的选择删除
        // dp[i + 1][j + 1] = del + dp[i][j + 1];
        auto dp = vector<vector<int>>(source.size() + 1, vector<int>(pattern.size() + 1, numeric_limits<int>::min()));

        int idx = 0;
        for (int i = 0; i <= source.size(); ++i) {
            dp[i][0] = idx;
            if (idx < targetIndices.size() && i == targetIndices[idx]) {
                ++idx;
            }
        }

        idx = 0;
        for (int i = 0; i < source.size(); ++i) {
            bool del = false;
            if (idx < targetIndices.size() && i == targetIndices[idx]) {
                del = true;
                ++idx;
            }
            for (int j = 0; j < pattern.size(); ++j) {
                if (dp[i][j] < 0 && dp[i][j + 1] < 0) {
                    continue;
                }
                if (source[i] == pattern[j]) {
                    dp[i + 1][j + 1] = std::max({dp[i][j], del + dp[i][j + 1]});
                } else {
                    dp[i + 1][j + 1] = del + dp[i][j + 1];
                }
            }
        }

        return dp[source.size()][pattern.size()];
    }
};

int main() {
    auto s = Solution();
    auto source = string("yeyeykyded");
    auto pattern = string("yeyyd");
    auto targetIndices = vector<int>({0, 2, 3, 4});
    cout << s.maxRemovals(source, pattern, targetIndices) << endl;
}
