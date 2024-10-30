#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class MedianFinder {
    priority_queue<int, vector<int>, std::less<>> maxHeap;
    priority_queue<int, vector<int>, std::greater<>> minHeap;

public:
    MedianFinder() {}

    void addNum(const int num) {
        if (minHeap.size() == maxHeap.size()) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() const {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#ifdef LEETCODE
int main() {
    const auto methods = vector<string>({
            "MedianFinder",
            "addNum",
            "addNum",
            "findMedian",
            "addNum",
            "findMedian",
    });
    const auto data = vector<vector<int>>({
            {},
            {1},
            {2},
            {},
            {3},
            {},
    });
    auto obj = MedianFinder();
    for (int i = 1; i < methods.size(); ++i) {
        if (methods[i] == "addNum") {
            obj.addNum(data[i][0]);
        } else {
            cout << obj.findMedian() << endl;
        }
    }

    return 0;
}
#endif
