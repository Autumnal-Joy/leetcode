#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static bool isNumeric(const string &s) {
        return s[0] >= '0' && s[0] <= '9';
    }

public:
    vector<string> findLongestSubarray(vector<string> &array) {
        auto n = static_cast<int>(array.size());
        auto prefix1 = vector(n + 1, 0);
        auto prefix2 = vector(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix1[i] = prefix1[i - 1] + isNumeric(array[i - 1]);
            prefix2[i] = prefix2[i - 1] + !isNumeric(array[i - 1]);
        }
        auto mp = unordered_map<int, int>();
        int len = 0, begin = 0, end = 0;
        for (int i = 0; i <= n; ++i) {
            if (auto diff = prefix1[i] - prefix2[i]; !mp.contains(diff)) {
                mp[diff] = i;
            } else {
                if (i - mp[diff] > len) {
                    len = i - mp[diff];
                    begin = mp[diff];
                    end = i;
                }
            }
        }
        return {array.begin() + begin, array.begin() + end};
    }
};

int main() {

    return 0;
}
