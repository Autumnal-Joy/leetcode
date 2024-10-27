#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    int dfs(const auto &land, int i, int j, auto &visited) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || visited[i][j] || land[i][j] != 0) {
            return 0;
        }
        visited[i][j] = true;
        auto res = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                res += dfs(land, i + di, j + dj, visited);
            }
        }
        return res + 1;
    }

public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        auto res = vector<int>();

        auto visited = vector(land.size(), vector(land[0].size(), false));
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 0 && !visited[i][j]) {
                    res.push_back(dfs(land, i, j, visited));
                }
            }
        }
        ranges::sort(res);
        return res;
    }
};

int main() {

    return 0;
}
