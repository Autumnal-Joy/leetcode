#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int cal(const vector<int> &piles, int k) {
    int res = 0;
    for (auto p : piles) {
      res += (p + k - 1) / k;
    }
    return res;
  }
  int minEatingSpeed(vector<int> piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());

    while (left < right) {
      int mid = left + (right - left) / 2;
      int time = cal(piles, mid);
      if (time <= h) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};

int main() {
  auto s = Solution();
  cout << s.minEatingSpeed(vector<int>{3, 6, 7, 11}, 8) << endl;
  return 0;
}
