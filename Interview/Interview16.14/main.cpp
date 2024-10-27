#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    class HashPair {
        hash<double> hash_double;

    public:
        size_t operator()(const pair<int, int> &p) const {
            size_t seed = 0;
            seed ^= hash_double(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash_double(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
    static pair<double, double> direction(const auto &p1, const auto &p2) {
        double dx = p2[0] - p1[0], dy = p2[1] - p1[1];
        if (std::abs(dx) > 1e-6) {
            return {1, dy / dx};
        }
        return {0, 1};
    }

public:
    vector<int> bestLine(const vector<vector<int>> &points) {

        auto res = vector<int>();
        auto maxCnt = 0;
        for (int i = 0; i < points.size(); ++i) {
            auto mp = unordered_map<pair<double, double>, vector<int>, HashPair>();
            for (int j = i + 1; j < points.size(); ++j) {
                auto d = direction(points[i], points[j]);
                mp[d].push_back(j);
            }
            auto temp = vector<int>();
            for (const auto &[_, dots]: mp) {
                if (dots.size() > temp.size() || dots.size() == temp.size() && dots[0] < temp[0]) {
                    temp = dots;
                }
            }
            if (temp.size() > maxCnt) {
                res = {i, temp[0]};
                maxCnt = static_cast<int>(temp.size());
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> points = {
            {0, 0},
            {1, 1},
            {1, 0},
            {2, 0},
            {2, 2},
    };
    auto res = Solution().bestLine(points);
    return 0;
}
