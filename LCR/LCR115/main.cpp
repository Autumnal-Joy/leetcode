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
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences) {
        const auto n = static_cast<int>(nums.size());
        auto in = vector<int>(n + 1);
        auto out = vector<unordered_set<int>>(n + 1);
        for (const auto &seq: sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                if (!out[seq[i - 1]].contains(seq[i])) {
                    ++in[seq[i]];
                    out[seq[i - 1]].emplace(seq[i]);
                }
            }
        }
        auto start = vector<int>();
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) {
                start.push_back(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (start.size() != 1) {
                return false;
            }
            const auto num = start.back();
            start.pop_back();
            if (nums[i - 1] != num) return false;
            for (const auto &next: out[num]) {
                --in[next];
                if (in[next] == 0) {
                    start.push_back(next);
                }
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({4, 1, 5, 2, 6, 3});
    auto sequences = vector<vector<int>>({{5, 2, 6, 3}, {4, 1, 5, 2}});
    Solution().sequenceReconstruction(nums, sequences);
    return 0;
}
#endif
