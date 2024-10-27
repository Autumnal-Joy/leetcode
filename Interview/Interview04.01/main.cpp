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
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {
        auto isVisited = vector(n, false);
        auto adj = vector<unordered_set<int>>(n);
        for (const auto &g: graph) {
            adj[g[0]].insert(g[1]);
        }
        isVisited[start] = true;
        auto dq = deque<int>({start});
        while (!dq.empty()) {
            auto front = dq.front();
            dq.pop_front();
            for (auto node: adj[front]) {
                if (isVisited[node]) continue;
                if (node == target) return true;
                isVisited[node] = true;
                dq.push_back(node);
            }
        }
        return false;
    }
};

int main() {

    return 0;
}
