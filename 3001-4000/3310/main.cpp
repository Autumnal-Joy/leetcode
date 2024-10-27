#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int val) {
        while (val != parent[val]) {
            parent[val] = parent[parent[val]];
            val = parent[val];
        }
        return val;
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
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
        auto node2neighbors = vector<set<int>>(n);
        auto uf = UnionFind(n);
        for (const auto &item: invocations) {
            node2neighbors[item[0]].insert(item[1]);
            uf.unite(item[0], item[1]);
        }

        auto isSuspect = vector<bool>(n);
        isSuspect[k] = true;
        auto q = queue<int>({k});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto neighbor: node2neighbors[node]) {
                if (!isSuspect[neighbor]) {
                    isSuspect[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        bool canDelete = true;
        for (int i = 0; i < n; ++i) {
            if (uf.find(i) == uf.find(k) && !isSuspect[i]) {
                canDelete = false;
                break;
            }
        }

        auto res = vector<int>();

        if (canDelete) {
            for (int i = 0; i < n; ++i) {
                if (uf.find(i) != uf.find(k)) {
                    res.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
