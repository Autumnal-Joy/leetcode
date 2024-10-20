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
    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
        auto counter = unordered_map<int, int>();
        auto need = 0;
        auto target = unordered_set<int>();
        for (const auto &num: small) {
            target.insert(num);
        }
        const auto n = static_cast<int>(big.size()), m = static_cast<int>(small.size());
        auto left = 0, right = 0, minLen = n + 1;
        auto res = vector<int>();

        while (right < n) {
            ++counter[big[right]];
            if (target.contains(big[right]) && counter[big[right]] == 1) {
                ++need;
            }
            ++right;
            while (need == m) {
                if (right - left < minLen) {
                    minLen = right - left;
                    res = {left, right - 1};
                }
                --counter[big[left]];
                if (target.contains(big[left]) && counter[big[left]] == 0) {
                    --need;
                }
                ++left;
            }
        }

        return res;
    }
};

int main() {

    return 0;
}
