#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        auto m = map<int, int>();
        for (int i = 0; i < intervals.size(); ++i) {
            m[intervals[i][0]] = i;
        }
        auto res = vector<int>(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i) {
            auto it = m.lower_bound(intervals[i][1]);
            if (it != m.end()) {
                res[i] = it->second;
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
