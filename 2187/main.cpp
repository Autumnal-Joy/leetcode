#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static long long trips(const vector<int> &time, long long totalTime) {
    long long res = 0;
    for (auto t : time) {
      res += totalTime / t;
    }
    return res;
  }
  long long minimumTime(const vector<int> &time, int totalTrips) {
    long long left = 1, right = static_cast<long long>(1e7) * totalTrips;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (trips(time, mid) < totalTrips) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

int main() {
  auto s = Solution();
  cout << s.minimumTime({1}, 10000);
  return 0;
}
