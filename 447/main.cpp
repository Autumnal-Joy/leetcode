#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  static int dis(const vector<int> &p1, const vector<int> &p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
           (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }

public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    auto n = points.size();

    int res = 0;

    for (int i = 0; i < n; ++i) {
      auto distanceSet = unordered_map<int, int>();

      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        distanceSet[dis(points[i], points[j])]++;
      }
      for (auto p : distanceSet) {
        res += p.second * (p.second - 1);
      }
    }

    return res;
  }
};

int main() {
  auto s = Solution();
  vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
  cout << s.numberOfBoomerangs(points) << endl;
  return 0;
}
