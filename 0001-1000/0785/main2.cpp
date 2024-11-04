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

class Solution {
public:
    bool isBipartite(const vector<vector<int>> &graph) {
        const auto n = static_cast<int>(graph.size());
        auto visited = vector<bool>(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            auto div = vector<unordered_set<int>>(2);
            div[0].insert(i);
            auto dq = deque<int>();
            dq.push_back(i);
            auto id = 0;
            while (!dq.empty()) {
                auto sz = dq.size();
                while (sz--) {
                    const auto front = dq.front();
                    dq.pop_front();
                    for (const auto &next: graph[front]) {
                        if (div[id].contains(next)) return false;
                        if (visited[next]) continue;
                        visited[next] = true;
                        div[1 - id].insert(next);
                        dq.push_back(next);
                    }
                }
                id = 1 - id;
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
