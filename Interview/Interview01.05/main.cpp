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
    bool oneEditAway(const string &first, const string &second) {
        const auto m = static_cast<int>(first.size());
        const auto n = static_cast<int>(second.size());
        if (std::abs(m - n) > 1) {
            return false;
        }
        if (m == n) {
            auto cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (first[i] != second[i]) {
                    if (++cnt > 1) {
                        return false;
                    }
                }
            }
            return true;
        }
        if (m < n) {
            return oneEditAway(second, first);
        }
        auto offset = 0;
        for (int i = 0; i < n; ++i) {
            while (i + offset < m && first[i + offset] != second[i]) {
                ++offset;
            }
            if (offset > 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}
