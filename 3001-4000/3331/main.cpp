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
    vector<int> findSubtreeSizes(vector<int> &parent, string s) {
        const auto n = static_cast<int>(parent.size());
        auto clone = parent;
        for (int i = 1; i < n; ++i) {
            auto p = parent[i];
            while (p != -1 && s[p] != s[i]) {
                p = parent[p];
            }
            if (p != -1) {
                clone[i] = p;
            }
        }

        auto children = vector<vector<int>>(n);
        for (int i = 1; i < n; ++i) {
            children[clone[i]].push_back(i);
        }
        auto res = vector<int>(n);
        function<int(int)> count = [&](const int node) {
            auto size = 1;
            for (const auto &child: children[node]) {
                if (child != -1) {
                    size += count(child);
                }
            }
            res[node] = size;
            return size;
        };
        count(0);

        return res;
    }
};

int main() {
    auto parent = vector({-1, 0, 4, 0, 1});
    auto s = string("abbba");
    Solution().findSubtreeSizes(parent, s);
    return 0;
}
