#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        auto crack = unordered_map<int, int>();
        for (const auto &i: wall) {
            int loc = 0;
            for (int j = 0; j < i.size() - 1; ++j) {
                loc += i[j];
                ++crack[loc];
            }
        }
        int maxCrack = 0;
        for (const auto &p: crack) {
            maxCrack = max(maxCrack, p.second);
        }
        return static_cast<int>(wall.size()) - maxCrack;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
