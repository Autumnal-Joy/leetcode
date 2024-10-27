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
    int minOperations(vector<int> &nums) {
        int cnt = 0;
        auto n = static_cast<int>(nums.size());
        for (int i = 1; i + 1 < n; ++i) {
            if (nums[i - 1] == 0) {
                ++cnt;
                nums[i - 1] = 1 - nums[i - 1];
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
            }
        }
        if (nums[n - 2] + nums[n - 1] == 2) {
            return cnt;
        } else {
            return -1;
        }
    }
};

int main() {

    return 0;
}
