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
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
        const auto sum1 = std::accumulate(array1.begin(), array1.end(), 0ll);
        const auto sum2 = std::accumulate(array2.begin(), array2.end(), 0ll);
        if ((sum1 - sum2) % 2 != 0) return {};
        const auto diff = (sum1 - sum2) / 2;
        auto s = unordered_set<int>();
        for (auto num: array1) {
            s.insert(num);
        }
        for (auto num: array2) {
            if (s.contains(static_cast<int>(num + diff))) {
                return {static_cast<int>(num + diff), num};
            }
        }
        return {};
    }
};

int main() {

    return 0;
}
