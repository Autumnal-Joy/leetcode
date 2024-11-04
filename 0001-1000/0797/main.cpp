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
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int start) {
        path.push_back(start);
        if (start + 1 == graph.size()) {
            res.push_back(path);
        } else {
            for (const auto next: graph[start]) {
                dfs(graph, next);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        dfs(graph, 0);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
