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
    bool patternMatching(const string &pattern, const string &value) {
        auto cnt = vector(2, 0);
        for (int i = 0; i < 2; ++i) {
            cnt[i] = static_cast<int>(ranges::count(pattern.begin(), pattern.end(), 'a' + i));
        }
        const auto n = static_cast<int>(value.size());
        const auto str = string_view(value);
        for (int i = 0; i <= n; ++i) {
            auto len = vector(2, 0);
            if (cnt[0] == 0) {
                len[1] = n / cnt[1];
            } else if (cnt[1] == 0) {
                len[0] = n / cnt[0];
            } else {
                len[0] = i, len[1] = (n - len[0] * cnt[0]) / cnt[1];
            }
            if (len[0] * cnt[0] + len[1] * cnt[1] != n || len[0] < 0 || len[1] < 0) {
                continue;
            }
            auto mp = unordered_map<char, string_view>();
            auto offset = 0;
            auto flag = true;
            for (const auto &ch: pattern) {
                if (!mp.contains(ch)) {
                    mp[ch] = str.substr(offset, len[ch - 'a']);
                } else if (mp[ch] != str.substr(offset, len[ch - 'a'])) {
                    flag = false;
                    break;
                }
                if (mp.contains('a') && mp.contains('b') && mp['a'] == mp['b']) {
                    flag = false;
                    break;
                }
                offset += len[ch - 'a'];
            }
            if (flag) {
                return flag;
            }
        }
        return false;
    }
};

int main() {
    Solution().patternMatching("abba", "dogcatcatdog");
    return 0;
}
