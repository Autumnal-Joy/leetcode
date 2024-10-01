#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static int maxIncreaseKeepingSkyline(const vector<vector<int>> &grid) {
    size_t n = grid.size();
    vector<int> rowMax(n);
    vector<int> colMax(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        rowMax[i] = std::max({rowMax[i], grid[i][j]});
        colMax[j] = std::max({colMax[j], grid[i][j]});
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res += std::min({rowMax[i], colMax[j]}) - grid[i][j];
      }
    }
    return res;
  }
};

int main() {
  auto s = Solution();
  cout << s.maxIncreaseKeepingSkyline(
              {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}})
       << endl;
  return 0;
}
