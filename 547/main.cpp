#include <numeric>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int cnt;
public:
    explicit UnionFind(int n) : parent(n), rank(n, 1), cnt(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int root(int val) {
        while (parent[val] != val) {
            parent[val] = parent[parent[val]];
            val = parent[val];
        }
        return val;
    }

    void unite(int val1, int val2) {
        auto p1 = root(val1), p2 = root(val2);
        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p2] = p1;
            ++rank[p1];
        }
        --cnt;
    }

    int count() const {
        return cnt;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = static_cast<int>(isConnected.size());
        UnionFind uf(n);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.count();
    }
};

int main() {
    return 0;
}
