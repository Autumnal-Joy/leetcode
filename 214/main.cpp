#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 寻找最长回文前缀字符串

//   abbab
//  babba
class Solution {
  vector<int> computePrefix(const string &pattern) {
    int n = pattern.size();
    vector<int> prefix(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
      // 如果字符不匹配，更新j的值
      while (j > 0 && pattern[i] != pattern[j]) {
        j = prefix[j - 1];
      }
      // 如果字符匹配，增加j的值
      if (pattern[i] == pattern[j]) {
        ++j;
      }
      prefix[i] = j;
    }
    return prefix;
  }

public:
  string shortestPalindrome(string s) {
    string rev(s);
    reverse(rev.begin(), rev.end());
    string pattern = s + "#" + rev;
    auto prefix = computePrefix(pattern);
    int n = s.size();
    int len = prefix.back();
    return rev.substr(0, n - len) + s;
  }
};

int main() {
  auto s = Solution();
  cout << s.shortestPalindrome("aaacecaaa") << endl;
  cout << s.shortestPalindrome("abcd") << endl;
  cout << s.shortestPalindrome("abb") << endl;
  return 0;
}
