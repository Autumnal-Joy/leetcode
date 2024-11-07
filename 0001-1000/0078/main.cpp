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
    void dfs(const vector<int> &nums, int i) {
        if (i == nums.size()) {
            res.push_back(path);
        } else {
            dfs(nums, i + 1);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(const vector<int> &nums) {
        dfs(nums, 0);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
