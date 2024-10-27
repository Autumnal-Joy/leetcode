#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int val) {
        if (val != parent[val]) {
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }
    void unite(int x, int y) {
        auto p1 = find(x), p2 = find(y);
        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
            ++rank[p2];
        }
    }
    void separate(int x) {
        parent[x] = x;
    }
};

// 1. 入度都为 1，有环，并查集解
// 2. 存在入度为 2，有环，返回入度为 2 且在环内的边
// 3. 存在入度为 2，无环，返回入度为 2 的最后一个边

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
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        const int n = static_cast<int>(edges.size());

        auto parent = unordered_map<int, vector<int>>();
        for (const auto &edge: edges) {
            parent[edge[1]].push_back(edge[0]);
        }

        const auto it = ranges::find_if(parent, [](const auto &p) {
            return p.second.size() == 2;
        });
        if (it == parent.end()) {
            // 1. 入度都为 1，有环，并查集解
            auto uf = UnionFind(static_cast<int>(n + 1));
            for (const auto &edge: edges) {
                if (uf.find(edge[0]) == uf.find(edge[1])) {
                    return edge;
                }
                uf.unite(edge[0], edge[1]);
            }
            return {};
        }

        // 2. 存在入度为 2，有环，返回入度为 2 且在环内的边
        auto path = unordered_set<array<int, 2>, HashArray<int, 2>>();
        auto p = it->second[0];
        path.insert({p, it->first});
        while (parent.contains(p) && !parent[p].empty() && p != it->first) {
            path.insert({parent[p][0], p});
            p = parent[p][0];
        }
        if (p == it->first) {
            return {it->second[0], it->first};
        }

        path = unordered_set<array<int, 2>, HashArray<int, 2>>();
        p = it->second[1];
        path.insert({it->first, p});
        while (parent.contains(p) && !parent[p].empty() && p != it->first) {
            path.insert({parent[p][0], p});
            p = parent[p][0];
        }
        if (p == it->first) {
            return {it->second[1], it->first};
        }

        // 3. 存在入度为 2，无环，返回入度为 2 的最后一个边
        for (int i = n - 1; i >= 0; --i) {
            if (edges[i][1] == it->first) {
                return edges[i];
            }
        }
        return {};
    }
};

int main() {
    auto edges = vector<vector<int>>({
            {1, 2},
            {1, 3},
            {2, 3},
    });
    Solution().findRedundantDirectedConnection(edges);
    return 0;
}
