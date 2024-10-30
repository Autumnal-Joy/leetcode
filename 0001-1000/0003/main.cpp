#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto mp = bitset<256>();
        auto left = 0, right = 0;
        auto res = 0;
        while (right < s.size()) {
            mp.flip(s[right]);
            ++right;
            while (mp.test(s[right - 1]) == 0) {
                mp.flip(s[left]);
                ++left;
            }
            res = std::max({res, right - left});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    Solution().lengthOfLongestSubstring("abcabcbb");
    return 0;
}
#endif
