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
    int maxAliveYear(vector<int> &birth, vector<int> &death) {
        auto n = static_cast<int>(birth.size());
        auto diff = vector<int>(102, 0);
        for (int i = 0; i < n; ++i) {
            diff[birth[i] - 1900]++;
            diff[death[i] + 1 - 1900]--;
        }
        int maxAlive = 0, maxAliveYear = 0;
        int cnt = 0;
        for (int i = 1900; i <= 2000; ++i) {
            cnt += diff[i - 1900];
            if (cnt > maxAlive) {
                maxAlive = cnt;
                maxAliveYear = i;
            }
        }
        return maxAliveYear;
    }
};

int main() {

    return 0;
}
