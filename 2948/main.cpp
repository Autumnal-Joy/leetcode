#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// 对数组按照值排序下标数组，将下标数组分段，根据下标从小到大填充原数组
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
        int n = static_cast<int>(nums.size());
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) { return nums[i] < nums[j]; });

        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int begin = i++;
            while (i < n && nums[ids[i]] - nums[ids[i - 1]] <= limit) {
                ++i;
            }
            vector<int> subIds(ids.begin() + begin, ids.begin() + i);
            sort(subIds.begin(), subIds.end());
            for (int j = 0; j < subIds.size(); j++) {
                ans[subIds[j]] = nums[ids[begin + j]];
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
