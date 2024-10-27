#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    enum class Rotate {
        turnLeft,
        turnRight,
    };
    auto turn(const auto &direction, const auto &rotate) {
        auto table = string("URDL");
        auto idx = ranges::find(table, direction) - table.begin();
        if (rotate == Rotate::turnRight) {
            idx = (idx + 1) % 4;
        } else {
            idx = (idx + 3) % 4;
        }
        return table[idx];
    }
    auto move(const auto &loc, const auto &direction) {
        auto [x, y] = loc;
        if (direction == 'U') {
            return make_pair(x - 1, y);
        }
        if (direction == 'R') {
            return make_pair(x, y + 1);
        }
        if (direction == 'D') {
            return make_pair(x + 1, y);
        }
        return make_pair(x, y - 1);
    }
    class HashPair {
    public:
        size_t operator()(const pair<int, int> &p) const {
            size_t seed = 0;
            seed ^= p.first + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

public:
    vector<string> printKMoves(int K) {
        auto black = unordered_set<pair<int, int>, HashPair>();
        auto loc = make_pair(0, 0);
        auto direction = 'R';
        auto left = 0, right = 0, up = 0, down = 0;
        for (int i = 0; i < K; ++i) {
            if (!black.contains(loc)) {
                black.insert(loc);
                direction = turn(direction, Rotate::turnRight);
            } else {
                black.erase(loc);
                direction = turn(direction, Rotate::turnLeft);
            }
            loc = move(loc, direction);
            left = std::min({left, loc.second});
            right = std::max({right, loc.second});
            up = std::min({up, loc.first});
            down = std::max({down, loc.first});
        }


        auto res = vector<string>(down - up + 1);
        for (int i = up; i <= down; ++i) {
            auto row = string(right - left + 1, '_');
            for (int j = left; j <= right; ++j) {
                if (black.contains({i, j})) {
                    row[j - left] = 'X';
                }
            }
            res[i - up] = std::move(row);
        }
        res[loc.first - up][loc.second - left] = direction;
        return res;
    }
};

int main() {

    return 0;
}
