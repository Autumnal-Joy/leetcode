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
    static int maxGoodNumber(vector<int> &nums) {
        auto len = vector<int>(nums.size());
        std::transform(nums.begin(), nums.end(), len.begin(), [](auto n) {
            return std::log2(n) + 1;
        });

        int res = 0;
        auto ids = vector<int>(nums.size());
        std::iota(ids.begin(), ids.end(), 0);
        do {
            auto newRes = nums[ids[0]];
            newRes = (newRes << len[ids[1]]) + nums[ids[1]];
            newRes = (newRes << len[ids[2]]) + nums[ids[2]];
            res = std::max(res, newRes);
        } while (std::next_permutation(ids.begin(), ids.end()));

        return res;
    }
};

int main() {
    auto nums = vector<int>({1, 2, 3});
    cout << Solution::maxGoodNumber(nums) << endl;
    return 0;
}
