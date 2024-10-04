#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// abac
// abaca
class Solution {
public:
  int countSubstrings(string s) {
    int cnt = 0;

    // 遍历回文串中心点
    for (int center = 0; center < s.size(); ++center) {
      // 回文串长度为奇数
      for (int i = 0; center - i >= 0 && center + i < s.size(); ++i) {
        if (s[center - i] != s[center + i]) {
          break;
        }
        ++cnt;
      }

      // 回文串长度为偶数
      for (int i = 0; center - i >= 0 && center + i + 1 < s.size(); ++i) {
        if (s[center - i] != s[center + i + 1]) {
          break;
        }
        ++cnt;
      }
    }
    return cnt;
  }
};

int main() {
  auto s = Solution();
  cout << s.countSubstrings("abaca") << endl;
  return 0;
}
