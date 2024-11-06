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

    void dfs(vector<int> &candidates, const int begin, const int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (begin == candidates.size()) {
            return;
        }
        auto used = unordered_set<int>();
        for (int i = begin; i < candidates.size(); ++i) {
            if (used.contains(candidates[i])) continue;
            used.insert(candidates[i]);
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        ranges::sort(candidates);
        dfs(candidates, 0, target);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto candidates = vector({10, 1, 2, 7, 6, 1, 5});
    auto res = Solution().combinationSum2(candidates, 8);
    return 0;
}
#endif
