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
    int minFlipsMonoIncr(const string &s) {
        const auto n = static_cast<int>(s.size());
        // pre1[i] 表示 s[0..i) 中 1 的个数
        // post0[i] 表示 s[i..n) 中 0 的个数
        auto pre1 = vector(n + 1, 0), post0 = vector(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pre1[i] = pre1[i - 1] + (s[i - 1] == '1');
        }
        for (int i = n - 1; i >= 0; --i) {
            post0[i] = post0[i + 1] + (s[i] == '0');
        }
        auto res = n;
        for (int i = 0; i <= n; ++i) {
            res = std::min({res, pre1[i] + post0[i]});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
