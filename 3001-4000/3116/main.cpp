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
    long long findKthSmallest(vector<int> &coins, int k) {
        auto n = static_cast<int>(coins.size());
        auto lcm = vector<vector<long long>>(n);

        function<void(int, int, long long, vector<long long> &)> getLcm =
                [&](int idx, int depth, long long lcm, vector<long long> &container) {
                    if (depth == 0) {
                        container.push_back(lcm);
                    } else if (n - idx >= depth) {
                        getLcm(idx + 1, depth - 1, std::lcm(lcm, coins[idx]), container);
                        getLcm(idx + 1, depth, lcm, container);
                    }
                };
        for (int i = 0; i < lcm.size(); ++i) {
            getLcm(0, i + 1, 1, lcm[i]);
        }

        auto check = [&](long long x) {
            long long cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (auto l: lcm[i]) {
                    cnt += (i & 1 ? -1 : 1) * x / l;
                }
            }
            return cnt;
        };

        long long l = 1, r = 1ll * *min_element(coins.begin(), coins.end()) * k + 1;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            auto cnt = check(mid);
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};

int main() {
    auto s = Solution();
    auto coins = vector<int>({3, 6, 9});
    cout << s.findKthSmallest(coins, 3);
    return 0;
}
