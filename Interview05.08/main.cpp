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
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        auto res = vector<int>(length);
        for (int i = x1, group = w / 32; i <= x2; ++i) {
            res[group * y + i / 32] |= 1 << (31 - i % 32);
        }
        return res;
    }
};

int main() {
    Solution().drawLine(10, 64, 13, 31, 3);
    return 0;
}
