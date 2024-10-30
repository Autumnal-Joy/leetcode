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
    int nthUglyNumber(int n) {
        auto res = vector(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            res[i] = std::min({res[i2] * 2, res[i3] * 3, res[i5] * 5});
            if (res[i] == res[i2] * 2) ++i2;
            if (res[i] == res[i3] * 3) ++i3;
            if (res[i] == res[i5] * 5) ++i5;
        }
        return res[n - 1];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
