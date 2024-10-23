#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    int dfs(const vector<vector<int>> &box, const int idx, const int w, const int d, const int h,
            unordered_map<int, int> &memo) {
        if (idx == box.size()) return 0;
        int res = 0;
        for (int i = idx; i < box.size(); ++i) {
            if (box[i][0] > w && box[i][1] > d && box[i][2] > h) {
                if (!memo.contains(i)) {
                    memo[i] = dfs(box, i + 1, box[i][0], box[i][1], box[i][2], memo);
                }
                res = std::max({res, box[i][2] + memo[i]});
            }
        }
        return res;
    }

public:
    int pileBox(vector<vector<int>> &box) {
        ranges::sort(box, [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        auto memo = unordered_map<int, int>();
        return dfs(box, 0, 0, 0, 0, memo);
    }
};

int main() {
    return 0;
}
