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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        auto n = static_cast<int>(edges.size());
        auto uf = UnionFind(n + 1);
        for (int i = 0; i < n; ++i) {
            auto u = edges[i][0], v = edges[i][1];
            if (uf.find(u) == uf.find(v)) {
                return edges[i];
            }
            uf.unite(u, v);
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
