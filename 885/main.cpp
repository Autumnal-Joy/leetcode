#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {

        auto inBound = [&](int x, int y) {
            return 0 <= x && x < rows && 0 <= y && y < cols;
        };

        vector<vector<int>> res;
        int step = 1, direction = 0;
        auto delta = vector<pair<int, int>>({{0,  1},
                                             {1,  0},
                                             {0,  -1},
                                             {-1, 0}});
        while (res.size() < rows * cols) {
            for (int i = 0; i < step; ++i) {
                if (inBound(rStart, cStart)) {
                    res.push_back({rStart, cStart});
                }
                rStart += delta[direction].first;
                cStart += delta[direction].second;
            }
            direction = (direction + 1) % 4;

            if ((direction & 1) == 0) {
                ++step;
            }
        }

        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
