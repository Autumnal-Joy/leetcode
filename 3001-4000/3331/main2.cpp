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
        auto n = static_cast<int>(parent.size());
        auto children = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }

        auto ancestor = array<int, 26>();
        ancestor.fill(-1);
        auto res = vector(n, 1);
        function<void(int)> dfs = [&](const int node) {
            const auto old = ancestor[s[node] - 'a'];
            ancestor[s[node] - 'a'] = node;
            for (const int child: children[node]) {
                const auto anc = ancestor[s[child] - 'a'];
                dfs(child);
                if (anc == -1) {
                    res[node] += res[child];
                } else {
                    res[anc] += res[child];
                }
            }
            ancestor[s[node] - 'a'] = old;
        };
        dfs(0);

        return res;
    }
};

int main() {
    auto parent = vector({-1, 0, 4, 0, 1});
    auto s = string("abbba");
    Solution().findSubtreeSizes(parent, s);
    return 0;
}
