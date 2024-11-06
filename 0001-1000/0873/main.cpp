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

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
    int lenLongestFibSubseq(const vector<int> &arr) {
        const auto n = static_cast<int>(arr.size());
        auto idx = unordered_map<int, int>();
        for (int i = 0; i < n; ++i) {
            idx[arr[i]] = i;
        }
        // dp[i][j] 表示以 arr[i] 和 arr[j] 结尾的最长斐波那契子序列的长度
        auto dp = vector(n, vector(n, 2));
        auto res = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] - arr[i] < arr[i] && idx.contains(arr[j] - arr[i])) {
                    dp[i][j] = dp[idx[arr[j] - arr[i]]][i] + 1;
                    res = std::max({res, dp[i][j]});
                }
            }
        }
        return res == 2 ? 0 : res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
