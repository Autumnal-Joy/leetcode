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
    long long countCompleteDayPairs(const vector<int> &hours) {
        auto mp = vector<vector<int>>(25);
        auto res = 0ll;
        for (int i = 0; i < hours.size(); ++i) {
            const auto hour = hours[i] % 24;
            res += static_cast<long long>(mp[24 - hour].size());
            if (hour == 0) {
                res += static_cast<long long>(mp[0].size());
            }
            mp[hour].push_back(i);
        }

        return res;
    }
};

int main() {

    return 0;
}
