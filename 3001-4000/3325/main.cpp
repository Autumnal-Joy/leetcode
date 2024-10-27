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
    int numberOfSubstrings(string s, int k) {
        auto counter = vector(26, 0);
        auto check = [&](const auto &cnt) {
            return ranges::any_of(cnt, [&](const auto &c) {
                return c >= k;
            });
        };
        auto n = static_cast<int>(s.size());
        auto res = 0;
        auto left = 0, right = 0;
        while (right < n) {
            ++counter[s[right] - 'a'];
            ++right;
            while (check(counter)) {
                res += n - right + 1;
                --counter[s[left] - 'a'];
                ++left;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
