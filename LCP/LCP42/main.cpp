#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static bool inside(vector<int> toy, vector<int> circle, int r) {
        long long x1 = toy[0], y1 = toy[1], r1 = toy[2];
        long long x2 = circle[0], y2 = circle[1], r2 = r;
        if (r1 > r2) {
            return false;
        }
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <=
               (r2 - r1) * (r2 - r1);
    }

    static int circleGame(vector<vector<int>> &toys, vector<vector<int>> &circles,
                          int r) {
        auto centers = set<vector<int>>(circles.begin(), circles.end());

        int cnt = 0;
        for (auto &toy: toys) {
            int x1 = toy[0], y1 = toy[1], r1 = toy[2];
            bool find = false;
            for (int x2 = x1 - (r - r1); x2 <= x1 + r - r1; x2++) {
                for (int y2 = y1 - (r - r1); y2 <= y1 + r - r1; y2++) {
                    if (centers.count({x2, y2}) == 0) {
                        continue;
                    }
                    if (inside({x1, y1, r1}, {x2, y2}, r)) {
                        cnt++;
                        find = true;
                    }
                    if (find) {
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> toys = {{1, 3, 2},
                                {4, 3, 1},
                                {7, 1, 2}};
    vector<vector<int>> circles = {{1, 0},
                                   {3, 3}};
    std::cout << s.circleGame(toys, circles, 4) << endl;
    return 0;
}
