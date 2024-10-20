#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        if (k == 0) {
            return {};
        }
        auto pq = priority_queue<int, vector<int>, greater<>>();
        for (auto &num: arr) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (pq.top() > num) {
                pq.pop();
                pq.push(num);
            }
        }
        auto res = vector<int>();
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main() {

    return 0;
}
