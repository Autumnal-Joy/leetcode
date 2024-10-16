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
    long long minSum(vector<int> &nums1, vector<int> &nums2) {
        auto sum1 = std::accumulate(nums1.begin(), nums1.end(), 0ll);
        auto sum2 = std::accumulate(nums2.begin(), nums2.end(), 0ll);
        auto cnt1 = std::count_if(nums1.begin(), nums1.end(), [](auto x) { return x == 0; });
        auto cnt2 = std::count_if(nums2.begin(), nums2.end(), [](auto x) { return x == 0; });
        if (sum1 + cnt1 == sum2 + cnt2) {
            return sum1 + cnt1;
        } else {
            if (sum1 + cnt1 < sum2 + cnt2 && cnt1) {
                return sum2 + cnt2;
            } else if (sum1 + cnt1 > sum2 + cnt2 && cnt2) {
                return sum1 + cnt1;
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}
