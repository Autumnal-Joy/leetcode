#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<string> digit2str = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> res;
  void dfs(const string &digits, int idx, string &path) {
    if (idx == digits.size()) {
      res.push_back(path);
      return;
    }

    for (auto c : digit2str[digits[idx] - '0']) {
      path.push_back(c);
      dfs(digits, idx + 1, path);
      path.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    string path;
    dfs(digits, 0, path);
    return res;
  }
};

int main() {
  auto s = Solution();
  return 0;
}
