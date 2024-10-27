#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

template<typename T, size_t N>
class HashArray {
public:
    size_t operator()(const array<T, N> &arr) const {
        return std::accumulate(arr.begin(), arr.end(), static_cast<size_t>(0), [hasher = hash<T>()](const size_t seed, const T &val) {
            return seed ^ hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        });
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        auto adj = unordered_map<int, unordered_set<int>>();
        for (const auto &edge: edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        auto nodes = unordered_set<int>();
        auto path = vector<int>();
        function<bool(int, int)> dfs = [&](const int start, const int from) {
            path.push_back(start);
            if (nodes.contains(start)) {
                return true;
            }
            nodes.insert(start);
            for (const auto neighbor: adj[start]) {
                if (neighbor == from) continue;
                if (dfs(neighbor, start)) {
                    return true;
                }
            }
            nodes.erase(start);
            path.pop_back();
            return false;
        };

        if (dfs(1, 0)) {
            auto circle = unordered_set<array<int, 2>, HashArray<int, 2>>();
            int loc = 0;
            while (path[loc] != path.back()) {
                ++loc;
            }
            while (loc + 1 < path.size()) {
                circle.insert({std::min({path[loc], path[loc + 1]}), std::max({path[loc], path[loc + 1]})});
                ++loc;
            }
            for (int i = static_cast<int>(edges.size()) - 1; i >= 0; --i) {
                if (circle.contains({edges[i][0], edges[i][1]})) {
                    return edges[i];
                }
            }
        }
        return {};
    }
};

int main() {
    auto edges = vector<vector<int>>({
            {2, 7},
            {7, 8},
            {3, 6},
            {2, 5},
            {6, 8},
            {4, 8},
            {2, 8},
            {1, 8},
            {7, 10},
            {3, 9},
    });
    Solution().findRedundantConnection(edges);
    return 0;
}
