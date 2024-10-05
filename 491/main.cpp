#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  struct VectorHash {
    size_t operator()(const vector<int> &v) const {
      hash<int> hasher;
      size_t seed = 0;
      for (int num : v) {
        seed ^= hasher(num) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };

public:
  unordered_set<vector<int>, VectorHash> res;

  // depth 表示前 depth-1 个元素已经被选过了
  void backtrack(const vector<int> &nums, vector<int> &state, int depth) {
    for (int i = depth; i < nums.size(); ++i) {
      if (!state.empty() && nums[i] < state.back()) {
        continue;
      }
      state.push_back(nums[i]);
      if (state.size() > 1) {
        res.insert(state);
      }
      backtrack(nums, state, i + 1);
      state.pop_back();
    }
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    auto state = vector<int>();
    backtrack(nums, state, 0);
    return {res.begin(), res.end()};
  }
};

int main() {
  auto s = Solution();
  auto nums = vector<int>({1, 10, 1, 1, 1, 1});
  cout << s.findSubsequences(nums).size() << endl;
  return 0;
}
