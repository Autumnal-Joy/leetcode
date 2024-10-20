#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    vector<int> buildPrefixTable(const string &pattern) {
        const int n = static_cast<int>(pattern.size());
        auto prefix = vector(n, 0);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) j = prefix[j - 1];
            if (pattern[i] == pattern[j]) ++j;
            prefix[i] = j;
        }
        return prefix;
    }
    vector<int> KMP(const string &text, const string &pattern) {
        vector<int> result;
        const int n = static_cast<int>(text.size());
        const int m = static_cast<int>(pattern.size());
        if (m == 0) return result;
        const auto prefix = buildPrefixTable(pattern);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j]) j = prefix[j - 1];
            if (text[i] == pattern[j]) ++j;
            if (j == m) {
                result.push_back(i - m + 1);
                j = prefix[j - 1];
            }
        }
        return result;
    }

public:
    vector<vector<int>> multiSearch(const string &big, vector<string> &smalls) {
        auto res = vector<vector<int>>();
        for (const auto &small: smalls) {
            res.push_back(KMP(big, small));
        }
        return res;
    }
};

int main() {

    return 0;
}
