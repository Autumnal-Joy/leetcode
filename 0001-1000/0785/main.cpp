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

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

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
    bool isBipartite(const vector<vector<int>> &graph) {
        const auto n = static_cast<int>(graph.size());
        auto uf = UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (const auto &j: graph[i]) {
                if (uf.find(i) == uf.find(j)) {
                    return false;
                }
                uf.unite(graph[i][0], j);
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
