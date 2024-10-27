#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long m = 1000000007;

    char greater(char x) {
        if (x == 'F') return 'W';
        if (x == 'W') return 'E';
        return 'F';
    }
    char less(char x) {
        if (x == 'F') return 'E';
        if (x == 'W') return 'F';
        return 'W';
    }
    int countWinningSequences(string s) {
        auto n = static_cast<int>(s.size());
        // dp[X][i][n+j] 表示第 i 轮出 X，得分差为 j 的总排列数
        auto dp = unordered_map<char, vector<vector<long long>>>(
                {{'F', vector<vector<long long>>(n + 1, vector<long long>(2 * n + 1, 0))},
                 {'W', vector<vector<long long>>(n + 1, vector<long long>(2 * n + 1, 0))},
                 {'E', vector<vector<long long>>(n + 1, vector<long long>(2 * n + 1, 0))}});

        dp[greater(s[0])][1][n + 1] = 1;
        dp[less(s[0])][1][n - 1] = 1;
        dp[s[0]][1][n + 0] = 1;

        // i 表示已经完成的回合数
        for (int i = 1; i < n; ++i) {
            // j 表示第 i+1 轮的得分
            for (int j = 0; j <= 2 * n; ++j) {
                auto rival = s[i];
                if (j > 0) {
                    // 第 i+1 轮胜利后得 j 分，需要第 i 轮得 j-1 分
                    dp[greater(rival)][i + 1][j] = dp[rival][i][j - 1] + dp[less(rival)][i][j - 1];
                    dp[greater(rival)][i + 1][j] %= m;
                }
                if (j < 2 * n) {
                    // 第 i+1 轮失败后得 j 分，需要第 i 轮得 j+1 分
                    dp[less(rival)][i + 1][j] = dp[rival][i][j + 1] + dp[greater(rival)][i][j + 1];
                    dp[less(rival)][i + 1][j] %= m;
                }
                // 第 i+1 轮平局后得 j 分，需要第 i 轮得 j 分
                dp[rival][i + 1][j] = dp[less(rival)][i][j] + dp[greater(rival)][i][j];
                dp[rival][i + 1][j] %= m;
            }
        }
        long long res = 0;
        for (auto X: string("FWE")) {
            for (auto it = dp[X][n].begin() + n + 1; it < dp[X][n].end(); ++it) {
                res = res + *it;
                res %= m;
            }
        }
        return static_cast<int>(res);
    }
};


int main() {
    Solution s;
    cout << s.countWinningSequences("FFF") << endl;
    return 0;
}
