#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace test {
    void copy() {}
}// namespace test


// [0,n]
// k 层
// 没有碎 [k,n] 需要 1 + [0, n-k] 的次数
// 碎了 [0, k-1] 需要 1 + k-1 次
// dp[n] = min{max{1+dp[n-k+1], k}}

class Solution {
public:
    int twoEggDrop(int n) {
        auto dp = vector<int>(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int k = 1; i - k >= 1; ++k) {
                dp[i] = std::min({dp[i], std::max({1 + dp[i - k], k})});
            }
        }
        return dp[n];
    }
};
int main() {
    Solution s;
    cout << s.twoEggDrop(100) << endl;
    return 0;
}
