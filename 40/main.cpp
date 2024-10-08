#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void
    dfs(int target, const vector<int> &candidates, int begin, vector<bool> &visited, vector<int> &path,
        vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
        }
        int last = -1;
        for (int i = begin; i < candidates.size(); ++i) {
            if (visited[i] || candidates[i] > target || (last != -1 && candidates[last] == candidates[i])) { continue; }
            path.push_back(candidates[i]);
            last = i;
            visited[i] = true;
            dfs(target - candidates[i], candidates, i, visited, path, res);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        auto res = vector<vector<int>>();
        auto path = vector<int>();
        auto visited = vector<bool>(candidates.size(), false);
        dfs(target, candidates, 0, visited, path, res);
        return res;
    }
};

int main() {
    Solution s;
    auto candidates = vector<int>{10, 1, 2, 7, 6, 1, 5};
    s.combinationSum2(candidates, 8);
    return 0;
}
