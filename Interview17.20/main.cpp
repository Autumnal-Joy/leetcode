#include <set>

using namespace std;

class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    // O(logn) 红黑树
    void addNum(int num) {
        nums.insert(num);
        if (nums.size() == 1) {
            left = right = nums.begin();
        } else {
            if (nums.size() & 1) {
                if (num < *left) {
                    right--;
                } else if (num >= *right) {
                    left++;
                } else {
                    left++;
                    right = left;
                }
            } else {
                if (num < *left) {
                    left--;
                } else {
                    right++;
                }
            }
        }
    }

    double findMedian() { return (*left + *right) / 2.0; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() { return 0; }
