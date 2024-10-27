#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

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
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        auto meetingMap = map<int, vector<pair<int, int>>>();
        for (const auto &m: meetings) {
            meetingMap[m[2]].emplace_back(m[0], m[1]);
        }

        auto uf = UnionFind(n);
        uf.unite(0, firstPerson);

        for (const auto &[_, meeting]: meetingMap) {
            for (const auto &[expert1, expert2]: meeting) {
                uf.unite(expert1, expert2);
            }

            for (const auto &[expert1, expert2]: meeting) {
                if (uf.find(expert1) != uf.find(0)) {
                    uf.separate(expert1);
                    uf.separate(expert2);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (uf.find(0) == uf.find(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    auto meetings = vector<vector<int>>();
    auto is = ifstream("../2092/input.txt");
    int expert1, expert2, time;
    for (int i = 0; i < 10000; i++) {
        is >> expert1 >> expert2 >> time;
        meetings.push_back({expert1, expert2, time});
    }
    auto res = s.findAllPeople(10010, meetings, 10000);
    return 0;
}
