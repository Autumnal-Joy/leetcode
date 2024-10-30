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
    static long long cnt(const long long num,
                         const long long a,
                         const long long b,
                         const long long c) {
        const auto cntA = num / a;
        const auto cntB = num / b;
        const auto cntC = num / c;
        const auto cntAB = num / std::lcm(a, b);
        const auto cntAC = num / std::lcm(a, c);
        const auto cntBC = num / std::lcm(b, c);
        const auto cntABC = num / std::lcm(std::lcm(a, b), c);
        return cntA + cntB + cntC - cntAB - cntAC - cntBC + cntABC;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        auto left = 1, right = numeric_limits<int>::max();
        while (left < right) {
            if (const auto mid = left + (right - left) / 2;
                cnt(mid, a, b, c) < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

#ifdef LEETCODE
int main() {
    Solution().nthUglyNumber(5, 2, 11, 13);
    return 0;
}
#endif
