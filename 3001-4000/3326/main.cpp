#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static int maxFactor(int num) {
        int f = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                f = i;
                break;
            }
        }
        return num / f;
    }

public:
    int minOperations(vector<int> &nums) {
        auto n = static_cast<int>(nums.size());
        auto cnt = 0;
        for (int i = n - 2; i >= 0; --i) {
            while (nums[i] > nums[i + 1]) {
                const auto f = maxFactor(nums[i]);
                if (f == nums[i]) {
                    return -1;
                }
                nums[i] /= f;
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}
