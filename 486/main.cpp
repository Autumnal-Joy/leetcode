#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    static int sum(const vector<int> &nums, int start, int end) {
        return std::accumulate(nums.begin() + start, nums.begin() + end, 0);
    }

    int maxPointForPlayer1(const vector<int> &nums, int start, int end) {
        if (end - start == 1) {
            return nums[start];
        }
        if (end - start == 2) {
            return std::max(nums[start], nums[start + 1]);
        }
        auto total = sum(nums, start, end);
        auto case1 = total - maxPointForPlayer1(nums, start + 1, end);
        auto case2 = total - maxPointForPlayer1(nums, start, end - 1);
        return std::max({case1, case2});
    }

    bool predictTheWinner(const vector<int> &nums) {
        auto total = sum(nums, 0, nums.size());
        auto score = maxPointForPlayer1(nums, 0, nums.size());
        return score >= total - score;
    }
};

int main() {
    Solution s;
    cout << s.predictTheWinner({1, 3, 1}) << endl;
    return 0;
}
