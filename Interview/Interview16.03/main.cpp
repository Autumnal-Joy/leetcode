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
    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2) {
        double s1_x = start1[0], s1_y = start1[1], e1_x = end1[0], e1_y = end1[1];
        double s2_x = start2[0], s2_y = start2[1], e2_x = end2[0], e2_y = end2[1];
        if (s1_x == e1_x && s2_x == e2_x) {
            if (s1_x != s2_x) {
                return {};
            }
            if (s1_y > e1_y) {
                swap(s1_y, e1_y);
            }
            if (s2_y > e2_y) {
                swap(s2_y, e2_y);
            }
            if (s1_y > e2_y || s2_y > e1_y) {
                return {};
            }
            return {0.0 + s1_x, 0.0 + std::max({s1_y, s2_y})};
        }
        if (s1_x == e1_x) {
            if (s1_y > e1_y) {
                swap(s1_y, e1_y);
            }
            const auto k2 = 1.0 * (e2_y - s2_y) / (e2_x - s2_x);
            const auto b2 = 1.0 * s2_y - k2 * s2_x;
            const auto jointY = k2 * s1_x + b2;
            if (jointY >= s1_y && jointY <= e1_y) {
                return {0.0 + s1_x, jointY};
            }
            return {};
        }
        if (s2_x == e2_x) {
            if (s2_y > e2_y) {
                swap(s2_y, e2_y);
            }
            const auto k2 = 1.0 * (e1_y - s1_y) / (e1_x - s1_x);
            const auto b2 = 1.0 * s1_y - k2 * s1_x;
            const auto jointY = k2 * s2_x + b2;
            if (jointY > s2_y && jointY < s1_y) {
                return {0.0 + s2_x, jointY};
            }
            return {};
        }
        if (s1_x > e1_x) {
            swap(s1_x, e1_x);
            swap(s1_y, e1_y);
        }
        if (s2_x > e2_x) {
            swap(s2_x, e2_x);
            swap(s2_y, e2_y);
        }
        const auto k1 = 1.0 * (e1_y - s1_y) / (e1_x - s1_x);
        const auto b1 = 1.0 * s1_y - k1 * s1_x;
        const auto k2 = 1.0 * (e2_y - s2_y) / (e2_x - s2_x);
        const auto b2 = 1.0 * s2_y - k2 * s2_x;
        if (k1 == k2) {
            if (b1 != b2) {
                return {};
            }
            if (k1 > 0 && s1_x > e2_x || s2_x > e1_x) {
                return {};
            }
            auto jointX = 0.0 + std::max({s1_x, s2_x});
            auto jointY = 0.0 + k2 * jointX + b2;
            return {jointX, jointY};
        }
        const auto jointX = 1.0 * (b2 - b1) / (k1 - k2);
        const auto jointY = 1.0 * k1 * jointX + b1;
        if (jointX >= s1_x && jointX <= e1_x && jointX >= s2_x && jointX <= e2_x) {
            return {jointX, jointY};
        }
        return {};
    }
};

int main() {
    auto start1 = vector({0, 0});
    auto end1 = vector({1, 0});
    auto start2 = vector({1, 1});
    auto end2 = vector({0, -1});
    Solution().intersection(start1, end1, start2, end2);
    return 0;
}
