#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// 4 1 5 3 0 2
// 0 1 1 3 7 10
// 0 1 1     10
// (0,0) (1,1) (2,1) (5,10)
// [0,3] + [0,4] + [0,5] = 10 - 1 = 9

// TLE
class Solution {
    long long m = 1e9 + 7;

public:
    long long solve(int begin, int end, int target) {
        if (begin > end) { return 0; }
        if (begin == end) { return begin >= target; }
        if (begin + 1 == end) {
            return std::max({std::min({begin, target}) - std::max({target - end, 0}) + 1, 0});
        }
        long long res = 0;
        auto mid = begin + (end - begin) / 2;
        auto sumLeft = (begin + mid) * (mid - begin + 1) / 2;
        auto sumRight = (mid + 1 + end) * (end - mid) / 2;
        for (int i = std::max({0, target - sumRight}); i <= std::min({target, sumLeft}); ++i) {
            res = (res + (solve(begin, mid, target - i) * solve(mid + 1, end, i)) % m) % m;
        }
        return res;
    }

    int numberOfPermutations(int n, vector<vector<int>> &requirements) {
        std::sort(requirements.begin(), requirements.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        auto res = 1ll;
        auto prevEnd = -1, prevCnt = 0;
        for (int i = 0; i < requirements.size(); ++i) {
            auto nextEnd = requirements[i][0], nextCnt = requirements[i][1];
            res = (res * solve(prevEnd + 1, nextEnd, nextCnt - prevCnt)) % m;
            prevEnd = nextEnd, prevCnt = nextCnt;
        }
        return res;
    }
};

int main() {
    Solution s;
    // 0 0 0 x 1
    // 0 1 2 4 3
    // 0 1 3 2 4
    auto requirements = vector<vector<int>>({{2, 0}, {0, 0}, {1, 0}, {4, 1}});
    cout << s.numberOfPermutations(3, requirements) << endl;
    return 0;
}
