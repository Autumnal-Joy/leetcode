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
    double myPow(double x, int n) {
        if (std::abs(x - 1) < 1e-15) {
            return x;
        }
        if (n < 0) {
            return 1 / x / myPow(x, -(n + 1));
        }
        if (n == 0) {
            return 1;
        }
        auto ret = 1.0;
        auto temp = x;
        while (n) {
            if (n & 1) {
                ret *= x;
                n -= 1;
            } else {
                x *= x, n >>= 1;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
