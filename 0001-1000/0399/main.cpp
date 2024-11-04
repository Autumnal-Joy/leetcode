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
    bool dfs(unordered_map<string, unordered_map<string, double>> &weight,
             unordered_set<string> &visited, const string &start, const string &end, double &res) {
        if (start == end) {
            res = 1;
            return true;
        }
        visited.insert(start);
        for (const auto &[next, value]: weight[start]) {
            if (visited.contains(next)) { continue; }
            if (dfs(weight, visited, next, end, res)) {
                res *= value;
                return true;
            }
        }
        return false;
    }

public:
    vector<double> calcEquation(const vector<vector<string>> &equations, const vector<double> &values, const vector<vector<string>> &queries) {
        auto weight = unordered_map<string, unordered_map<string, double>>();
        auto nodes = unordered_set<string>();
        for (int i = 0; i < equations.size(); ++i) {
            nodes.insert(equations[i][0]);
            nodes.insert(equations[i][1]);
            weight[equations[i][0]][equations[i][1]] = values[i];
            weight[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        auto res = vector<double>();
        for (const auto &query: queries) {
            if (!nodes.contains(query[0]) || !nodes.contains(query[1])) {
                res.push_back(-1);
                continue;
            }
            if (query[0] == query[1]) {
                res.push_back(1);
                continue;
            }
            auto visited = unordered_set<string>();
            dfs(weight, visited, query[0], query[1], res.emplace_back(-1));
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
