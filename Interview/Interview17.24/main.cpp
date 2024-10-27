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
    vector<int> getMaxMatrix(vector<vector<int>> &matrix) {
        auto N = static_cast<int>(matrix.size()), M = static_cast<int>(matrix[0].size());

        auto prefixSum = vector<vector<long long>>(N, vector<long long>(M + 1));
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= M; ++j) {
                prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][j - 1];
            }
        }
        auto sum = [&](auto line, auto begin, auto end) {
            return prefixSum[line][end + 1] - prefixSum[line][begin];
        };

        // dp[i][j][k] 表示以 (i,j) 为左下角，(i,k) 为右下角的矩形的最大和
        auto dp = vector<vector<vector<pair<long long, pair<int, int>>>>>(N, vector<vector<pair<long long, pair<int, int>>>>(M, vector<pair<long long, pair<int, int>>>(M)));
        auto maxVal = numeric_limits<long long>::min();
        auto res = vector<int>();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = j; k < M; ++k) {
                    if (i == 0 || dp[i - 1][j][k].first < 0) {
                        dp[i][j][k].first = sum(i, j, k);
                        dp[i][j][k].second = {i, j};
                    } else {
                        dp[i][j][k].first = sum(i, j, k) + dp[i - 1][j][k].first;
                        dp[i][j][k].second = dp[i - 1][j][k].second;
                    }
                    if (dp[i][j][k].first > maxVal) {
                        maxVal = dp[i][j][k].first;
                        res = {dp[i][j][k].second.first, dp[i][j][k].second.second, i, k};
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    auto matrix = vector<vector<int>>{{9, -8, 1, 3, -2},
                                      {-3, 7, 6, -2, 4},
                                      {6, -4, -4, 8, -7}};
    auto s = Solution();
    s.getMaxMatrix(matrix);
    return 0;
}
