#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static int maximumLength(const vector<int> &nums, int k) {
    if (nums.size() == 1) {
      return 1;
    }
    if (nums.size() == 2) {
      return nums[0] == nums[1] || k > 0 ? 2 : 1;
    }

    // dp[i][j] 表示满足k=i且以j结尾的子序列的最大长度
    auto dp = vector<vector<int>>(k + 1, vector<int>(nums.size(), 0));
    for (int i = 0; i <= k; i++) {
      dp[i][0] = 1;
    }

    for (int i = 0; i <= k; i++) {
      for (int j = 1; j < nums.size(); j++) {
        for (int l = 0; l < j; l++) {
          if (nums[l] == nums[j]) {
            dp[i][j] = std::max({dp[i][j], dp[i][l] + 1});
          } else if (i == 0) {
            dp[i][j] = std::max({dp[i][j], 1});
          } else {
            dp[i][j] = std::max({dp[i][j], dp[i - 1][l] + 1});
          }
        }
      }
    }

    return *std::max_element(dp[k].begin(), dp[k].end());
  }
};

int main() {
  auto s = Solution();
  cout << Solution::maximumLength({29, 30, 30}, 0) << endl;
  return 0;
}
