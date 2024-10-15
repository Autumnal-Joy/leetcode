#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        auto s = multiset<int, std::greater<>>();
        for (int i = 0; i < k; ++i) {
            s.insert(nums[i]);
        }
        auto res = vector<int>(nums.size() - k + 1);
        res[0] = *s.begin();
        for (int i = 1; i + k <= nums.size(); ++i) {
            s.erase(s.find(nums[i - 1]));
            s.insert(nums[i + k - 1]);
            res[i] = *s.begin();
        }
        return res;
    }
};

int main() {

    return 0;
}
