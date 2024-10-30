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
    int nthSuperUglyNumber(const int n, const vector<int> &primes) {
        auto res = vector(n, 1ll);
        auto idx = vector<int>(primes.size());
        for (int i = 1; i < n; ++i) {
            res[i] = primes[0] * res[idx[0]];
            for (int j = 1; j < idx.size(); ++j) {
                res[i] = std::min({res[i], res[i] = primes[j] * res[idx[j]]});
            }
            for (int j = 0; j < idx.size(); ++j) {
                if (res[i] == primes[j] * res[idx[j]]) {
                    ++idx[j];
                }
            }
        }
        return static_cast<int>(res[n - 1]);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
