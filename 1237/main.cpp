#include <iostream>
#include <vector>

using namespace std;

class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y) {
        return x + y;
    }
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        int x = 1, y = 1000;
        auto res = vector<vector<int>>();
        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            if (val == z) {
                res.push_back({x, y});
            }
            if (val <= z) {
                ++x;
            } else {
                --y;
            }
        }

        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
