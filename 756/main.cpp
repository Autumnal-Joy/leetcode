#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  set<pair<string, string>> memo;
  map<string, vector<char>> allowedMap;

  // bottom 是否合法
  bool dfs(const string &bottom, string upper) {
    if (bottom.size() == 1) {
      return true;
    }
    if (upper.size() == bottom.size() - 1) {
      return dfs(upper, "");
    }
    auto alpha = allowedMap[bottom.substr(upper.size(), 2)];
    for (auto c : alpha) {
      upper.push_back(c);
      auto failed = memo.count({bottom, upper});
      if (!failed) {
        if (dfs(bottom, upper)) {
          return true;
        } else {
          memo.insert({bottom, upper});
        }
      }
      upper.pop_back();
    }
    return false;
  }

  bool pyramidTransition(string bottom, vector<string> &allowed) {
    for (auto &s : allowed) {
      allowedMap[s.substr(0, 2)].push_back(s.back());
    }
    return dfs(bottom, "");
  }
};

int main() {
  auto s = Solution();
  // F
  // AF
  // DEF
  // ABCD
  string bottom = "ABCD";
  vector<string> allowed = {"ABC", "BCA", "CDA", "ABD", "BCE",
                            "CDF", "DEA", "EFF", "AFF"};
  cout << s.pyramidTransition(bottom, allowed) << endl;
  return 0;
}
