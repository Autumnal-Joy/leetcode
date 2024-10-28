#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static bool inBoard(const vector<string> &grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
    static bool validate(const vector<string> &grid, int x, int y) {
        return x >= 1 && x < grid.size() - 1 &&
               y >= 1 && y < grid[0].size() - 1 &&
               grid[x - 1][y] != '0' && grid[x + 1][y] != '0' &&
               grid[x][y - 1] != '0' && grid[x][y + 1] != '0';
    }

    static int dfs(vector<string> &grid, int x, int y) {
        if (grid[x][y] == '0' || grid[x][y] == '6') {
            return 0;
        }
        auto st = stack<pair<int, int>>();
        st.emplace(x, y);
        const auto ch = grid[x][y];
        grid[x][y] = '6';
        int cnt = 0;
        int isValid = true;

        while (!st.empty()) {
            auto [xi, yi] = st.top();
            st.pop();
            isValid = isValid && validate(grid, xi, yi);
            ++cnt;
            using P = pair<int, int>;
            for (auto [dx, dy]: {P{-1, 0}, P{1, 0}, P{0, -1}, P{0, 1}}) {
                auto xj = xi + dx, yj = yi + dy;
                if (!inBoard(grid, xj, yj)) continue;
                if (grid[xj][yj] != ch) continue;
                if (grid[xj][yj] == '6') continue;
                st.emplace(xj, yj);
                grid[xj][yj] = '6';
            }
        }
        return isValid ? cnt : 0;
    }

public:
    static int largestArea(vector<string> &grid) {
        int maxArea = 0;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                auto area = dfs(grid, i, j);
                maxArea = std::max({maxArea, area});
            }
        }
        return maxArea;
    }
};

int main() {
    // auto grid = vector<string>{
    //         "11111100000",
    //         "21243101111",
    //         "21224101221",
    //         "11111101111",
    // };
    auto grid = vector<string>{
            "113415514",
            "124112542",
            "313225220",
            "253354005",
            "352014331",
            "304514425",
            "553313413",
            "532352143",
            "220340311",
            "245210141",
    };
    // auto grid = vector<string>({
    //         "000",
    //         "010",
    //         "000",
    // });
    cout << Solution::largestArea(grid) << endl;
    return 0;
}
