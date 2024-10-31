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
    int solve00(const vector<int> &nums, int begin, int end) {
        if (end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin) / 2;
        return std::max({
                solve00(nums, begin, mid) + solve10(nums, mid, end),
                solve01(nums, begin, mid) + solve00(nums, mid, end),
        });
    }
    int solve01(const vector<int> &nums, int begin, int end) {
        if (end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin) / 2;
        return std::max({
                solve00(nums, begin, mid) + solve11(nums, mid, end),
                solve01(nums, begin, mid) + solve01(nums, mid, end),
        });
    }
    int solve10(const vector<int> &nums, int begin, int end) {
        if (end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin) / 2;
        return std::max({
                solve10(nums, begin, mid) + solve10(nums, mid, end),
                solve11(nums, begin, mid) + solve00(nums, mid, end),
        });
    }
    int solve11(const vector<int> &nums, int begin, int end) {
        if (end - begin < 1) {
            return 0;
        }
        if (end - begin == 1) {
            return nums[begin];
        }
        auto mid = begin + (end - begin) / 2;
        return std::max({
                solve10(nums, begin, mid) + solve11(nums, mid, end),
                solve11(nums, begin, mid) + solve01(nums, mid, end),
        });
    }

    int rob(const vector<int> &nums) {
        return solve11(nums, 0, static_cast<int>(nums.size()));
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
