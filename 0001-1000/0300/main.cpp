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
    int lengthOfLIS(vector<int> &nums) {
        const auto n = static_cast<int>(nums.size());
        auto path = vector({nums[0]});
        for (int i = 1; i < n; ++i) {
            if (nums[i] > path.back()) {
                path.push_back(nums[i]);
            } else {
                auto it = ranges::lower_bound(path, nums[i]);
                *it = nums[i];
            }
        }
        return static_cast<int>(path.size());
    }
};

int main() {

    return 0;
}
