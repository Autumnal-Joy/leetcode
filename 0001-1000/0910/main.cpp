#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 1, 4, 4, 6  5
// 1, 6
class Solution {
public:
    int smallestRangeII(const vector<int> &nums, int k) {
        auto sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        int res = sorted.back() - sorted.front();
        for (int i = 1; i < sorted.size(); i++) {
            // [0, i-1] + k, [i, n-1] - k
            auto maxVal =
                    std::max({sorted[i - 1] + k, sorted[sorted.size() - 1] - k});
            auto minVal = std::min({sorted[0] + k, sorted[i] - k});
            res = std::min({res, maxVal - minVal});
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    assert(s.smallestRangeII({1}, 0) == 0);
    assert(s.smallestRangeII({0, 10}, 2) == 6);
    assert(s.smallestRangeII({1, 3, 6}, 3) == 3);
    assert(s.smallestRangeII({1, 4, 4, 6}, 3) == 3);
    assert(s.smallestRangeII({7, 8, 8}, 5) == 1);
    assert(s.smallestRangeII(
                   {8038, 9111, 5458, 8483, 5052, 9161, 8368, 2094, 8366, 9164,
                    53, 7222, 9284, 5059, 4375, 2667, 2243, 5329, 3111, 5678,
                    5958, 815, 6841, 1377, 2752, 8569, 1483, 9191, 4675, 6230,
                    1169, 9833, 5366, 502, 1591, 5113, 2706, 8515, 3710, 7272,
                    1596, 5114, 3620, 2911, 8378, 8012, 4586, 9610, 8361, 1646,
                    2025, 1323, 5176, 1832, 7321, 1900, 1926, 5518, 8801, 679,
                    3368, 2086, 7486, 575, 9221, 2993, 421, 1202, 1845, 9767,
                    4533, 1505, 820, 967, 2811, 5603, 574, 6920, 5493, 9490,
                    9303, 4648, 281, 2947, 4117, 2848, 7395, 930, 1023, 1439,
                    8045, 5161, 2315, 5705, 7596, 5854, 1835, 6591, 2553, 8628},
                   4643) == 8870);
    return 0;
}
