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
        function<void(int)> rebuild = [&](const int node) {
            const auto old = ancestor[s[node] - 'a'];
            ancestor[s[node] - 'a'] = node;
            const auto size = children[node].size();
            for (int i = 0; i < size; ++i) {
                auto child = children[node][i];
                if (child == -1) continue;
                if (const auto anc = ancestor[s[child] - 'a']; anc != -1 && anc != node) {
                    children[anc].push_back(child);
                    children[node][i] = -1;
                }
                rebuild(child);
            }
            ancestor[s[node] - 'a'] = old;
        };
        rebuild(0);

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
