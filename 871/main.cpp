#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int maxFuel = 1e9;

public:
    static int pos(const vector<vector<int>> &stations, int i) {
        return stations[i][0];
    }

    static int fuel(const vector<vector<int>> &stations, int i) {
        return stations[i][1];
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        if (stations.empty()) {
            return startFuel >= target ? 0 : -1;
        }

        startFuel -= stations[0][0];
        int n = static_cast<int>(stations.size());
        // fuel[i][j] 表示从第 i 个加油站出发，加了 j 次油到达目的地的最小初始油量
        auto dpFuel = vector<vector<int>>(n, vector<int>(n + 1, maxFuel));

        auto distance = target - pos(stations, n - 1);
        dpFuel[n - 1][0] = distance;
        dpFuel[n - 1][1] = std::max(distance - fuel(stations, n - 1), 0);

        for (int i = n - 2; i >= 0; --i) {
            distance = pos(stations, i + 1) - pos(stations, i);
            dpFuel[i][0] = target - pos(stations, i);
            for (int j = 1; j < n - i + 1; ++j) {
                // i 站不加油，i+1 站加 j 次油
                // i 站加油，i+1 站加 j-1 次油
                dpFuel[i][j] = std::min(
                        {distance + dpFuel[i + 1][j],
                         std::max(
                                 {distance + dpFuel[i + 1][j - 1] - fuel(stations, i), 0})});
            }
        }
        auto it = std::find_if(dpFuel[0].begin(), dpFuel[0].end(),
                               [&](int num) { return num <= startFuel; });

        if (it != dpFuel[0].end()) {
            int index = static_cast<int>(std::distance(dpFuel[0].begin(), it));
            return index;
        } else {
            return -1;
        }
    }
};

int main() {
    auto s = Solution();
    return 0;
}
