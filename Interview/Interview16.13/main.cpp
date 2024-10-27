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
    vector<double> cutSquares(vector<int> &square1, vector<int> &square2) {
        double center1x = square1[0] + square1[2] / 2.0, center1y = square1[1] + square1[2] / 2.0;
        double center2x = square2[0] + square2[2] / 2.0, center2y = square2[1] + square2[2] / 2.0;
        if (center1x == center2x) {
            double yMin = std::min({square1[1], square2[1]});
            double yMax = std::max({square1[1] + square1[2], square2[1] + square2[2]});
            return {center1x, yMin, center2x, yMax};
        }
        double left1 = square1[0], bottom1 = square1[1], right1 = left1 + square1[2], top1 = bottom1 + square1[2];
        double left2 = square2[0], bottom2 = square2[1], right2 = left2 + square2[2], top2 = bottom2 + square2[2];
        double k = (center2y - center1y) / (center2x - center1x);
        double b = center1y - k * center1x;
        if (std::abs(k) < 1) {
            auto xMin = std::min({left1, left2}), yMin = k * xMin + b;
            auto xMax = std::max({right1, right2}), yMax = k * xMax + b;
            if (xMin < xMax) {
                return {xMin, yMin, xMax, yMax};
            } else {
                return {xMax, yMax, xMin, yMin};
            }
        } else {
            auto yMin = std::min({bottom1, bottom2}), xMin = (yMin - b) / k;
            auto yMax = std::max({top1, top2}), xMax = (yMax - b) / k;
            if (xMin < xMax) {
                return {xMin, yMin, xMax, yMax};
            } else {
                return {xMax, yMax, xMin, yMin};
            }
        }
    }
};

int main() {
    auto s1 = vector({-1, 6, 3});
    auto s2 = vector({1, 0, 5});
    Solution().cutSquares(s1, s2);
    return 0;
}
