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
    vector<vector<int>> pairSums(vector<int> &nums, int target) {
        auto num2cnt = unordered_map<int, int>();
        auto res = vector<vector<int>>();
        for (auto num: nums) {
            if (num2cnt[target - num]) {
                res.push_back({target - num, num});
                --num2cnt[target - num];
            } else {
                ++num2cnt[num];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
