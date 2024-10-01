#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
  int MAX_SPEED = 1e7 + 1;
  double cost(const vector<int> &dist, double speed) {
    double time = 0;
    for (int d : dist) {
      time = ceil(time);
      time += d / speed;
    }
    return time;
  }

public:
  int minSpeedOnTime(const vector<int> &dist, double hour) {
    int left = 1, right = MAX_SPEED;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (cost(dist, mid) <= hour) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left < MAX_SPEED ? left : -1;
  }
};

int main() {
  auto s = Solution();
  cout << s.minSpeedOnTime({1, 3, 2}, 1.9);
  return 0;
}
