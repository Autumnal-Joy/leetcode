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
    long long M = 1000000007;
    long long quickPow(long long x, long long n) const {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % M;
            }
            x = x * x % M;
            n >>= 1;
        }
        return res;
    }

public:
    int cuttingBamboo(const int n) const {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n == 5) return 6;
        if (n == 6) return 9;
        auto [quot, rem] = std::div(n, 3);
        if (rem == 0) {
            return static_cast<int>(quickPow(3, quot));
        }
        if (rem == 1) {
            return static_cast<int>(quickPow(3, quot - 1) * 4 % M);
        }
        return static_cast<int>(quickPow(3, quot) * 2 % M);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
