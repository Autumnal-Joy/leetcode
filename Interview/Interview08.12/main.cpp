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
    vector<vector<string>> solveNQueens(int n) {
        auto vertical = vector<bool>(n);
        auto diag = vector<bool>(n * 2 - 1);
        auto antiDiag = vector<bool>(n * 2 - 1);

        auto path = vector<int>();
        auto res = vector<vector<int>>();

        function<void(int)> dfs = [&](const int depth) {
            if (depth == n) {
                res.push_back(path);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (vertical[i] or diag[i - depth + n] or antiDiag[i + depth]) {
                    continue;
                }
                vertical[i] = diag[i - depth + n] = antiDiag[i + depth] = true;
                path.push_back(i);
                dfs(depth + 1);
                path.pop_back();
                vertical[i] = diag[i - depth + n] = antiDiag[i + depth] = false;
            }
        };

        dfs(0);

        auto res2 = vector<vector<string>>();
        ranges::transform(res, std::back_inserter(res2), [&](const auto &solution) {
            auto temp = vector<string>();
            for (auto loc: solution) {
                temp.emplace_back(n, '.');
                temp.back()[loc] = 'Q';
            }
            return temp;
        });
        return res2;
    }
};

int main() {
    Solution().solveNQueens(4);
    return 0;
}
