#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int minVal = numeric_limits<int>::max(), maxVal = numeric_limits<int>::min();
            for (int j = i; j < n; ++j) {
                minVal = std::min(minVal, nums[j]);
                maxVal = std::max(maxVal, nums[j]);
                ret = ret + maxVal - minVal;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    return 0;
}
