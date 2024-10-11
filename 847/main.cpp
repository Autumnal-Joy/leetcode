#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int MAX_LEN = 12 * 12;

    vector<vector<int>> floyd(const vector<vector<int>> &graph) const {
        auto dis =
                vector<vector<int>>(graph.size(), vector<int>(graph.size(), MAX_LEN));

        for (int i = 0; i < graph.size(); i++) {
            dis[i][i] = 0;
        }

        for (int i = 0; i < graph.size(); i++) {
            for (auto adj: graph[i]) {
                dis[i][adj] = 1;
            }
        }

        for (int k = 0; k < graph.size(); k++) {
            for (int i = 0; i < graph.size(); i++) {
                for (int j = 0; j < graph.size(); j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        return dis;
    }

public:
    int shortestPathLength(const vector<vector<int>> &graph) {
        // dp[i][j] 表示状态 i 时到达节点 j 的最短路径长度
        // 状态 i 用二进制表示，第 j 位为 1 表示节点 j 已经访问过
        auto dp = vector<vector<int>>(1 << graph.size(),
                                      vector<int>(graph.size(), MAX_LEN));
        for (int i = 0; i < graph.size(); i++) {
            dp[1 << i][i] = 0;
        }

        auto dis = floyd(graph);

        auto solve = [&](auto &&self, int state, int end) -> int {
            if (dp[state][end] == MAX_LEN) {
                int prev = state & ~(1 << end);
                for (int i = 0; i < graph.size(); i++) {
                    if (prev & (1 << i)) {
                        dp[state][end] =
                                std::min({dp[state][end], self(self, prev, i) + dis[i][end]});
                    }
                }
            }

            return dp[state][end];
        };

        for (int i = 0; i < graph.size(); i++) {
            solve(solve, (1 << graph.size()) - 1, i);
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};

int main() {
    auto s = Solution();
    cout << s.shortestPathLength({{1},
                                  {0, 2, 4},
                                  {1, 3, 4},
                                  {2},
                                  {1, 2}})
         << endl;
    return 0;
}
