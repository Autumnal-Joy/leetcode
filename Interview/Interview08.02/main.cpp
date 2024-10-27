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
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        auto path = vector<vector<int>>();
        auto isVisited = vector(obstacleGrid.size(), vector(obstacleGrid[0].size(), false));
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x == obstacleGrid.size() || y == obstacleGrid[0].size() || obstacleGrid[x][y] || isVisited[x][y]) {
                return false;
            }
            path.push_back({x, y});
            isVisited[x][y] = true;
            if (x + 1 == obstacleGrid.size() && y + 1 == obstacleGrid[0].size() || dfs(x + 1, y) || dfs(x, y + 1)) {
                return true;
            }
            path.pop_back();
            return false;
        };
        dfs(0, 0);
        return path;
    }
};

int main() {

    return 0;
}
