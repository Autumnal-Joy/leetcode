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

// 21012
// 2102 + 2103 + 2100 + 2013 + 10000
// 大于1：进位
// 等于1：不变
// 小于1：退位
class Solution {
    static long long quickPow(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }

public:
    static int solve(const string &s, const int i) {
        auto res = 0;
        if (s[i] > '1') {
            res = (std::atoi(s.substr(0, i).c_str()) + 1) * quickPow(10, static_cast<int>(s.size()) - i - 1);
        } else if (s[i] == '1') {
            res = std::atoi((s.substr(0, i) + s.substr(i + 1)).c_str()) + 1;
        } else {
            res = std::atoi(s.substr(0, i).c_str()) * quickPow(10, static_cast<int>(s.size()) - i - 1);
        }
        return res;
    }
    int countDigitOne(int n) {
        const auto s = std::to_string(n);
        auto res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += solve(s, i);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    Solution().countDigitOne(12345);
    return 0;
}
#endif
