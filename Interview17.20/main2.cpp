#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class MedianFinder {
    vector<int> nums;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    // O(n) 有序数组
    void addNum(int num) {
        auto it = std::upper_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }

    double findMedian() {
        if (nums.size() & 1) {
            return nums[nums.size() / 2];
        } else {
            return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() { return 0; }
