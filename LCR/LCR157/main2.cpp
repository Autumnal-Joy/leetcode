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
    set<string> res;
    string path;
    void dfs(const int begin, string &goods) {
        if (begin == goods.size()) {
            res.insert(path);
        }
        for (int i = begin; i < goods.size(); ++i) {
            path.push_back(goods[i]);
            std::swap(goods[i], goods[begin]);
            dfs(begin + 1, goods);
            std::swap(goods[i], goods[begin]);
            path.pop_back();
        }
    }

public:
    vector<string> goodsOrder(string goods) {
        ranges::sort(goods);
        dfs(0, goods);
        return {res.begin(), res.end()};
    }
};

#ifdef LEETCODE
int main() {
    Solution().goodsOrder("hjpptvvz");
    return 0;
}
#endif
