#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int target, const vector<int> &candidates, int begin,
             vector<int> &path, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(path);
        }
        for (int i = begin; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(target - candidates[i], candidates, i, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        auto res = vector<vector<int>>();
        auto path = vector<int>();
        dfs(target, candidates, 0, path, res);
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
