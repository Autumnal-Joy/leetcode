#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
  string findReplaceString(const string& s, const vector<int> &indices,
                           const vector<string> &sources,
                           const vector<string> &targets) {
    vector<int> ops(indices.size());
    std::iota(ops.begin(), ops.end(), 0);
    std::sort(ops.begin(), ops.end(),
              [&](int i, int j) { return indices[i] < indices[j]; });

    string res;
    size_t offset = 0;
    for (int op : ops) {
      auto index = indices[op];
      const auto &source = sources[op];
      const auto &target = targets[op];

      if (s.substr(index, source.size()) == source) {
        res += s.substr(offset, index - offset);
        res += target;
        offset = index + source.size();
      }
    }
    if (offset < s.size()) {
      res += s.substr(offset);
    }
    return res;
  }
};

int main() {
  auto s = Solution();
  cout << s.findReplaceString("vmokgggqzp", {3, 5, 1}, {"kg", "ggq", "mo"},
                              {"s", "so", "bfr"})
       << endl;
  return 0;
}
