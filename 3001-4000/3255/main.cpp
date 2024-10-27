#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 1,2,3,5,6,7
class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        vector<int> ans(nums.size() - k + 1, -1);
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] == nums[i - 1] + 1) {
                ++cnt;
            } else {
                cnt = 1;
            }
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
