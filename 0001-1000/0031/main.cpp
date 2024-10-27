#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// 31736520
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return;
        int loc = n - 2;
        while (loc >= 0) {
            if (nums[loc + 1] > nums[loc]) {
                break;
            }
            --loc;
        }
        if (loc < 0) {
            ranges::reverse(nums);
            return;
        }
        int loc2 = loc;
        while (loc2 + 1 < n && nums[loc2 + 1] > nums[loc]) {
            ++loc2;
        }
        swap(nums[loc], nums[loc2]);
        std::reverse(nums.begin() + loc + 1, nums.end());
    }
};

int main() {

    return 0;
}
