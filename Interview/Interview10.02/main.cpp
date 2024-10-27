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
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        auto mp = unordered_map<string_view, vector<string>>();
        for (const auto &str: strs) {
            auto key = string(str);
            ranges::sort(key);
            mp[key].push_back(str);
        }
        auto res = vector<vector<string>>();
        res.reserve(mp.size());
        for (auto &it: mp) {
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {

    return 0;
}
