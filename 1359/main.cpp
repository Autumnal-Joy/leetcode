#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 设题意的排列数为 a，则如果允许交换 Pi 与 Di，那么排列数变为 a * 2
// 让 i 取值从 1 到 n，则排列数变为 a * 2^n，即全排列
// 因此 a = 2n! / 2^n = (2n-1)!! * n!
class Solution {
public:
  int countOrders(int n) {
    long long result = 1;
    long long mod = 1e9 + 7;

    for (int i = 1; i <= n; i++) {
      result = ((result * i) % mod) * (2 * i - 1) % mod;
    }

    return static_cast<int>(result);
  }
};

int main() {
  auto s = Solution();
  return 0;
}
