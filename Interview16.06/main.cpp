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
    int smallestDifference(vector<int> &a, vector<int> &b) {
        ranges::sort(a);
        ranges::sort(b);
        int i = 0, j = 0;
        long long res = numeric_limits<int>::max();
        while (i < a.size() && j < b.size()) {
            res = std::min({res, abs(0ll + a[i] - b[j])});
            if (a[i] < b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return static_cast<int>(res);
    }
};

int main() {

    return 0;
}
