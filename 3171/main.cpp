#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    static auto bitCntAdd(vector<int> &bitCnt, int val) {
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                ++bitCnt[i];
            }
        }
    }

    static auto bitCntDel(vector<int> &bitCnt, int val) {
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                --bitCnt[i];
            }
        }
    }

    static auto bitCntValue(const vector<int> &bitCnt) {
        int sum = 0;
        for (int i = 0; i < 32; ++i) {
            if (bitCnt[i]) {
                sum |= 1 << i;
            }
        }
        return sum;
    }


public:
    int minimumDifference(vector<int> &nums, int k) {
        if (nums.size() == 1) {
            return std::abs(nums[0] - k);
        }

        auto bitCnt = vector<int>(32);
        bitCntAdd(bitCnt, nums[0]);
        int left = 0, right = 1;
        int res = numeric_limits<int>::max();

        while (true) {
            int sum = bitCntValue(bitCnt);

            if (left != right) {
                res = std::min({res, std::abs(sum - k)});
            }

            if (sum < k) {
                bitCntAdd(bitCnt, nums[right]);
                ++right;
                if (right == nums.size()) {
                    break;
                }
            } else {
                bitCntDel(bitCnt, nums[left]);
                ++left;
            }
        }

        int sum = bitCntValue(bitCnt);
        res = std::min({res, std::abs(sum - k)});

        while (left < right && sum > k) {
            bitCntDel(bitCnt, nums[left]);
            sum = bitCntValue(bitCnt);
            res = std::min({res, std::abs(sum - k)});
            ++left;
        }


        return res;
    }
};


int main() {
    Solution s;
    auto nums = vector<int>{42, 49, 95, 76, 66};
    cout << s.minimumDifference(nums, 12) << endl;
    return 0;
}
