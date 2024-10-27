#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// 1 2 3 4 5
// 5 6 7 8 0

class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>> &edges) {
        auto node2adjs = vector<unordered_set<int>>(n);
        for (const auto &edge: edges) {
            node2adjs[edge[0]].insert(edge[1]);
            node2adjs[edge[1]].insert(edge[0]);
        }

        auto deg2nodes = vector<unordered_set<int>>(5);
        for (int i = 0; i < n; ++i) {
            deg2nodes[node2adjs[i].size()].insert(i);
        }

        if (!deg2nodes[1].empty()) {
            // 一行
            auto res = vector<vector<int>>(1, vector<int>(n));
            res[0][0] = *deg2nodes[1].begin();
            for (int i = 1; i < n; ++i) {
                res[0][i] = *node2adjs[res[0][i - 1]].begin();
                node2adjs[res[0][i]].erase(res[0][i - 1]);
            }
            return res;
        } else if (deg2nodes[4].empty()) {
            // 两行
            auto res = vector<vector<int>>(2, vector<int>(n / 2));
            auto start1 = *deg2nodes[2].begin();
            auto start2 = 0;
            for (auto node: node2adjs[start1]) {
                if (node2adjs[node].size() == 2) {
                    start2 = node;
                    break;
                }
            }
            res[0][0] = start1;
            res[1][0] = start2;
            node2adjs[start1].erase(start2);
            node2adjs[start2].erase(start1);

            for (int i = 1; i < n / 2; ++i) {
                auto left1 = res[0][i - 1];
                auto left2 = res[1][i - 1];
                auto next1 = *node2adjs[left1].begin();
                auto next2 = *node2adjs[left2].begin();
                node2adjs[next1].erase(left1);
                node2adjs[next1].erase(next2);
                node2adjs[next2].erase(left2);
                node2adjs[next2].erase(next1);
                res[0][i] = next1;
                res[1][i] = next2;
            }
            return res;
        } else {
            auto start = *deg2nodes[2].begin();
            auto res = vector<vector<int>>({{start}});
            for (auto node: node2adjs[start]) {
                node2adjs[node].erase(start);
            }
            auto findMinDegNeighbor = [&](const auto &node) {
                auto minDeg = 5, idx = -1;
                for (auto &neighbor: node2adjs[node]) {
                    if (node2adjs[neighbor].size() < minDeg) {
                        minDeg = node2adjs[neighbor].size();
                        idx = neighbor;
                    }
                }
                return idx;
            };

            auto &firstLine = res[0];
            while (true) {
                auto prev = firstLine.back();
                auto next = findMinDegNeighbor(prev);
                firstLine.push_back(next);
                node2adjs[prev].erase(next);
                node2adjs[next].erase(prev);
                if (node2adjs[next].size() == 1) {
                    break;
                }
            }

            auto rowCnt = firstLine.size();
            res.resize(n / rowCnt, vector<int>(firstLine.size()));

            auto findCommonNeighbor = [&](const auto &n1, const auto &n2) {
                for (const auto &neighbor1: node2adjs[n1]) {
                    for (const auto &neighbor2: node2adjs[n2]) {
                        if (neighbor1 == neighbor2) {
                            return neighbor1;
                        }
                    }
                }
                return -1;
            };

            for (int rowID = 1; rowID < res.size(); ++rowID) {
                for (int colID = 0; colID < res[0].size(); ++colID) {
                    auto up = res[rowID - 1][colID];
                    if (colID == 0) {
                        auto next = *node2adjs[up].begin();
                        node2adjs[up].erase(next);
                        node2adjs[next].erase(up);
                        res[rowID][colID] = next;
                    } else {
                        auto left = res[rowID][colID - 1];
                        auto next = findCommonNeighbor(up, left);
                        node2adjs[up].erase(next);
                        node2adjs[next].erase(up);
                        node2adjs[left].erase(next);
                        node2adjs[next].erase(left);
                        res[rowID][colID] = next;
                    }
                }
            }

            return res;
        }
    }
};

int main() {
    auto s = Solution();
    auto edges = vector<vector<int>>({{0, 1}, {0, 2}, {0, 4}, {1, 3}, {2, 5}, {3, 4}, {4, 5}});
    s.constructGridLayout(6, edges);
    return 0;
}
