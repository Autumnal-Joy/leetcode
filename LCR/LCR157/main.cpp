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
    void dfs(string &s, const int idx, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
        }
        auto used = set<char>();
        for (int i = idx; i < s.size(); ++i) {
            if (used.contains(s[i])) continue;
            used.insert(s[i]);
            std::swap(s[i], s[idx]);
            dfs(s, idx + 1, ans);
            std::swap(s[idx], s[i]);
        }
    }

public:
    vector<string> goodsOrder(string goods) {
        ranges::sort(goods);
        auto res = vector<string>();
        dfs(goods, 0, res);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    Solution().goodsOrder("hjpptvvz");
    return 0;
}
#endif
