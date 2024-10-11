#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        auto m = grid.size(), n = grid[0].size();
        auto countRowServers = vector<int>(m);
        auto countColServers = vector<int>(n);
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++countRowServers[i];
                    ++countColServers[j];
                }
            }
        }

        int res = 0;
        for (auto i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 &&
                    (countRowServers[i] > 1 || countColServers[j] > 1)) {
                    ++res;
                }
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
