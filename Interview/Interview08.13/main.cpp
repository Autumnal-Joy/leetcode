#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int pileBox(vector<vector<int>> &box) {
        ranges::sort(box, [](const auto &a, const auto &b) {
            return a[0] > b[0];
        });
        const int n = static_cast<int>(box.size());
        // dp[i] 第 i 个箱子结尾的最大高度
        auto dp = vector(n, 0);
        dp[0] = box[0][2];
        for (int i = 1; i < n; ++i) {
            dp[i] = box[i][2];
            for (int j = 0; j < i; ++j) {
                if (box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2]) {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
        }
        return ranges::max(dp);
    }
};

int main() {
    auto box = vector<vector<int>>({{1, 1, 1}, {2, 3, 4}, {3, 4, 5}, {6, 6, 6}, {7, 8, 9}, {8, 6, 4}});
    cout << Solution().pileBox(box) << endl;
    return 0;
}

