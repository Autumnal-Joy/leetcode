#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int atMostNGivenDigitSet(const vector<string> &digits, int n) {
    string s = to_string(n);
    int m = s.size();
    int res = 0;

    // 位数小于 m 的情况
    for (int i = 1; i < m; i++) {
      res += static_cast<int>(pow(digits.size(), i));
    }

    // 位数等于 m 的情况
    bool hasEqual = true; // 是否有相等的数字前缀
    for (int i = 0; i < m; i++) {
      // 前 i 位数字相等
      int cnt = 0; // cnt 为小于等于 s[i] 的数字个数
      while (cnt < digits.size() && digits[cnt][0] <= s[i]) {
        cnt++;
      }
      if (cnt == 0) {
        // 无解
        hasEqual = false;
        break;
      } else if (digits[cnt - 1][0] < s[i]) {
        // 前缀不相等的情况
        res += static_cast<int>(pow(digits.size(), m - i - 1)) * cnt;
        hasEqual = false;
        break;
      } else {
        // 前缀相等的情况
        res += static_cast<int>(pow(digits.size(), m - i - 1)) * (cnt - 1);
      }
    }
    return res + hasEqual;
  }
};

int main() {
  auto s = Solution();
  cout << s.atMostNGivenDigitSet({"3", "4", "8"}, 4) << endl;
  return 0;
}
