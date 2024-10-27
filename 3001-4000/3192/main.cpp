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
    int minOperations(vector<int> &nums) {
        int cnt = 0;
        int target = 1;
        for (auto num: nums) {
            cnt += num ^ target;
            target = num;
        }
        return cnt;
    }
};

int main() {
    auto s = Solution();
    auto nums = vector<int>({});
    return 0;
}
