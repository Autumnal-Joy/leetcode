#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    vector<vector<int>> subsets(const vector<int> &nums) {
        auto res = vector<vector<int>>({{}});
        res.reserve(quickPow(2, nums.size()));
        for (auto num: nums) {
            ranges::copy(res, std::back_inserter(res));
            for (int i = 0; i < res.size() >> 1; ++i) {
                res[i].push_back(num);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
