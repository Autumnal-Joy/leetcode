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

class BitSum {
    vector<int> bitCnt;
    int sum = 0;

public:
    BitSum() : bitCnt(32) {}

    auto val() {
        if (sum == 0) {
            for (int i = 0; i < 32; ++i) {
                if (bitCnt[i]) {
                    sum |= 1 << i;
                }
            }
        }
        return sum;
    }

    auto operator+=(int val) {
        sum = 0;
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                ++bitCnt[i];
            }
        }
    }

    auto operator-=(int val) {
        sum = 0;
        for (int i = 0; i < 32; ++i) {
            if (val & (1 << i)) {
                --bitCnt[i];
            }
        }
    }
};

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        auto bitSum = BitSum();

        int left = 0, right = 0;
        int res = numeric_limits<int>::max();

        while (true) {
            if (left != right) {
                res = std::min({res, std::abs(bitSum.val() - k)});
            }
            if (bitSum.val() < k) {
                if (right == nums.size()) {
                    break;
                }
                bitSum += nums[right];
                ++right;
            } else {
                bitSum -= nums[left];
                ++left;
            }
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
