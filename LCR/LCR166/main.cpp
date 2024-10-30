#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int jewelleryValue(vector<vector<int>> &frame) {
        // dp[i+1][j+1] 表示拿取 frame[i][j] 时的最大价值
        auto dp = vector(frame[0].size() + 1, 0);
        for (int i = 0; i < frame.size(); ++i) {
            for (int j = 0; j < frame[0].size(); ++j) {
                dp[j + 1] = std::max({dp[j + 1], dp[j]}) + frame[i][j];
            }
        }
        return dp.back();
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
