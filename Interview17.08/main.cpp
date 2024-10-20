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
    int bestSeqAtIndex(const vector<int> &height, const vector<int> &weight) {
        const auto n = static_cast<int>(height.size());
        auto id = vector<int>(n);
        std::iota(id.begin(), id.end(), 0);
        ranges::sort(id, [&](const int a, const int b) {
            return height[a] == height[b] ? weight[a] > weight[b] : height[a] < height[b];
        });

        auto less = [&](const int a, const int b) {
            return weight[a] < weight[b];
        };
        auto path = vector({id[0]});
        for (int i = 1; i < n; ++i) {
            if (less(path.back(), id[i])) {
                path.push_back(id[i]);
            } else {
                auto it = ranges::lower_bound(path, id[i], less);
                *it = id[i];
            }
        }
        return static_cast<int>(path.size());
    }
};

int main() {
    const auto height = vector<int>({65, 70, 56, 75, 60, 68, 67, 45, 98, 45});
    const auto wight = vector<int>({100, 150, 90, 190, 95, 110, 53, 67, 56, 98});
    Solution().bestSeqAtIndex(height, wight);
    return 0;
}
