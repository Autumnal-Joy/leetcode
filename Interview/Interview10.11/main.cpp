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
    void wiggleSort(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) return;
        auto temp = nums;
        ranges::sort(temp, std::greater<>());
        auto i = 0, j = (n + 1) / 2;
        for (int k = 0; k < n; ++k) {
            nums[k] = k & 1 ? temp[j++] : temp[i++];
        }
    }
};

int main() {

    return 0;
}
