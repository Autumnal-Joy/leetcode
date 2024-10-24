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
    vector<vector<int>> pathWithObstacles(const vector<vector<int>> &obstacleGrid) {
        const auto n = static_cast<int>(obstacleGrid.size()), m = static_cast<int>(obstacleGrid[0].size());
        if (obstacleGrid[0][0] == 1) {
            return {};
        }
        auto isvalid = [&](int i, int j) {
            return i < n && j < m && obstacleGrid[i][j] == 0;
        };
        auto from = vector(n, vector(m, vector({-1, -1})));
        auto q = queue<vector<int>>();
        q.push({0, 0});
        while (!q.empty()) {
            const auto &front = q.front();
            if (isvalid(front[0] + 1, front[1]) &&
                from[front[0] + 1][front[1]][0] == -1) {
                from[front[0] + 1][front[1]] = front;
                q.push({front[0] + 1, front[1]});
            }
            if (isvalid(front[0], front[1] + 1) &&
                from[front[0]][front[1] + 1][0] == -1) {
                from[front[0]][front[1] + 1] = front;
                q.push({front[0], front[1] + 1});
            }
            q.pop();
        }
        if ((n > 1 || m > 1) && from[n - 1][m - 1] == vector({-1, -1})) {
            return {};
        }
        auto path = vector<vector<int>>({{n - 1, m - 1}});
        while (from[path.back()[0]][path.back()[1]] != vector({-1, -1})) {
            auto &prev = from[path.back()[0]][path.back()[1]];
            path.push_back(std::move(prev));
        }
        ranges::reverse(path);
        return path;
    }
};

int main() {

    return 0;
}
