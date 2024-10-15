#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries) {
        auto counter = unordered_map<int, int>();
        for (auto num: nums) {
            ++counter[num];
        }

        auto maxVal = *std::max_element(nums.begin(), nums.end());
        // gcd[i] 表示 gcd 为 i 的 pair 个数
        auto gcd = vector<long long>(maxVal + 1, 0);
        for (int i = maxVal; i >= 1; --i) {
            // c 表示整除 i 的个数，gcd[i] = c * (c - 1) / 2 - gcd[2*i] -  gcd[3*i] - ...
            int c = 0;
            for (int j = i; j <= maxVal; j += i) {
                c += counter[j];
                gcd[i] -= gcd[j];
            }
            gcd[i] += 1ll * c * (c - 1) / 2;
        }

        // 0 2 3 3 4
        // 0 2 5 8 12
        for (int i = 1; i < gcd.size(); ++i) {
            gcd[i] += gcd[i - 1];
        }

        auto res = vector<int>();
        for (auto &q: queries) {
            auto it = std::lower_bound(gcd.begin(), gcd.end(), q + 1);
            res.push_back(it - gcd.begin());
        }
        return res;
    }
};

int main() {

    return 0;
}
