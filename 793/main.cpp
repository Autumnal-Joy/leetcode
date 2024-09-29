#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 5^n <= x < 5*5^n
//     x/5 + x/25 + x/125 + ... + x/5^(n-1) + x/5^n = k

class Solution {
public:
  int countZero(long long x) {
    long long cnt = 0;
    for (long long i = 5; i <= x; i *= 5) {
      cnt += x / i;
    }
    return cnt;
  }
  int preimageSizeFZF(int k) {
    if (k == 0) {
      return 5;
    }
    long long l = 0, r = 5 * (long long)k + 1;
    while (l < r) {
      long long m = l + (r - l) / 2;
      auto cnt = countZero(m);
      if (countZero(m) == k) {
        return 5;
      } else if (cnt < k) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return 0;
  }
};

int main() {
  auto s = Solution();
  cout << s.preimageSizeFZF(3) << endl;
  return 0;
}
