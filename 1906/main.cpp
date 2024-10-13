#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
        auto counters = vector<vector<int>>(nums.size() + 1, vector<int>(101, 0));
        counters[1][nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            counters[i + 1] = counters[i];
            ++counters[i + 1][nums[i]];
        }

        vector<int> res;
        for (const auto &q: queries) {
            auto left = counters[q[0]];
            auto right = counters[q[1] + 1];
            auto minDiff = 100;
            auto last = -1;
            for (int i = 1; i <= 100; ++i) {
                if (left[i] != right[i]) {
                    if (last != -1) {
                        minDiff = std::min({minDiff, i - last});
                    }
                    last = i;
                }
            }
            res.push_back(minDiff == 100 ? -1 : minDiff);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
