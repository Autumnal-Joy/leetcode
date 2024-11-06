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

    void dfs(vector<int> &nums, const int begin) {
        if (begin == nums.size()) {
            res.push_back(path);
        } else {
            auto used = unordered_set<int>();
            for (int i = begin; i < nums.size(); ++i) {
                if (used.contains(nums[i])) continue;
                used.insert(nums[i]);
                std::swap(nums[begin], nums[i]);
                path.push_back(nums[begin]);
                dfs(nums, begin + 1);
                path.pop_back();
                std::swap(nums[begin], nums[i]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        dfs(nums, 0);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
