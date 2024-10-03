#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  int MAX_TIME = 1000000;
  int MAX_COST = 1000000;

public:
  int minCost(int maxTime, const vector<vector<int>> &edges,
              const vector<int> &passingFees) {
    auto n = passingFees.size();

    // dp[i][j] 表示在时间 j 到达节点 i 的最小花费
    // dp[i][j] = min(dp[k][j - t] + passingFees[j])
    auto dp = vector<vector<int>>(n, vector<int>(maxTime + 1, MAX_COST));
    dp[0][0] = passingFees[0];
    for (int arrivalTime = 1; arrivalTime <= maxTime; arrivalTime++) {
      for (auto &edge : edges) {
        auto time = edge[2];
        int terminal, stop;
        if (arrivalTime >= time) {
          terminal = edge[0], stop = edge[1];
          dp[terminal][arrivalTime] =
              std::min({dp[terminal][arrivalTime],
                        dp[stop][arrivalTime - time] + passingFees[terminal]});
          terminal = edge[1], stop = edge[0];
          dp[terminal][arrivalTime] =
              std::min({dp[terminal][arrivalTime],
                        dp[stop][arrivalTime - time] + passingFees[terminal]});
        }
      }
    }

    auto minCost = *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    return minCost < MAX_COST ? minCost : -1;
  }
};

int main() {
  auto s = Solution();
  cout << s.minCost(25,
                    {{0, 1, 10},
                     {1, 2, 10},
                     {2, 5, 10},
                     {0, 3, 1},
                     {3, 4, 10},
                     {4, 5, 15}},
                    {5, 1, 2, 20, 20, 3})
       << endl;
  return 0;
}
