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
    static long long solve(const long long num) {
        auto base = 1ll;
        auto cnt = 0ll;
        auto len = 1;
        while (num >= base * 10) {
            cnt += 9 * base * len;
            base *= 10;
            ++len;
        }
        cnt += (num - base + 1) * len;
        return cnt;
    }
    static int findNthDigit(int n) {
        auto left = 0ll, right = n + 1ll;
        auto cnt = 0ll;
        while (left + 1 < right) {
            const auto mid = left + (right - left) / 2;
            if (cnt = solve(mid); cnt < n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return std::to_string(left + 1)[n - solve(left) - 1] - '0';
    }
};

#ifdef LEETCODE
int main() {
    cout << Solution::findNthDigit(11);
    return 0;
}
#endif
