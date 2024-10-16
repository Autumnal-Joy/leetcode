#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// [0, 4567654321)
// x...x123
// k=7
// len[0,4) * (k+1)^6
// len[0,5) * (k+1)^5
// len[0,6) * (k+1)^4
// len[0,6] * (k+1)^3
class Solution {
    long long quickPow(long long x, long long n) {
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
    long long numberOfPowerfulInt(long long finish, long long limit, string &s) {
        auto finishString = to_string(finish);
        auto sSize = static_cast<long long>(s.size()), fSize = static_cast<long long>(finishString.size());
        long long res = 0;
        bool prefixEqual = true;
        for (int i = 0; i + sSize < fSize; ++i) {
            long long bound = finishString[i] - '0';
            if (bound <= limit) {
                res += bound * quickPow(limit + 1, fSize - sSize - i - 1);
            } else {
                res += quickPow(limit + 1, fSize - sSize - i);
                prefixEqual = false;
                break;
            }
        }
        if (fSize >= sSize && prefixEqual) {
            auto suffix = finishString.substr(fSize - sSize, sSize);
            res += stoll(suffix) > stoll(s);
        }
        return res;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return numberOfPowerfulInt(finish + 1, limit, s) - numberOfPowerfulInt(start, limit, s);
    }
};

int main() {
    auto s = Solution();
    cout << s.numberOfPowerfulInt(1, 6543, 5, "124") << endl;
    return 0;
}
