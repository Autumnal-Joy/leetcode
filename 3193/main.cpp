#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long m = 1e9 + 7;

    // [0, end] 有 cnt 个逆序对且满足 requirements 的排列数
    auto dfs(int end, int cnt, vector<vector<long long>> &memo, const unordered_map<int, int> &end2cnt) -> long long {
        if (end == 0) {
            return memo[end][cnt] = cnt == 0;
        }
        if (cnt < 0) {
            return 0;
        }
        if (memo[end][cnt] != -1) {
            return memo[end][cnt];
        }
        auto it = end2cnt.find(end - 1);
        if (it != end2cnt.end()) {
            // 前有 end 个数，新元素最多贡献 end 个逆序对
            auto r = it->second;
            if (r <= cnt && cnt <= end + r) {
                return memo[end][cnt] = dfs(end - 1, r, memo, end2cnt);
            } else {
                return memo[end][cnt] = 0;
            }

        } else {
            if (cnt > end) {
                return memo[end][cnt] = (dfs(end, cnt - 1, memo, end2cnt) - dfs(end - 1, cnt - 1 - end, memo, end2cnt) + dfs(end - 1, cnt, memo, end2cnt) + m) % m;
            } else {
                return memo[end][cnt] = (dfs(end, cnt - 1, memo, end2cnt) + dfs(end - 1, cnt, memo, end2cnt)) % m;
            }
            //            // 遍历新元素贡献的逆序对数
            //            long long sum = 0;
            //            for (int i = 0; i <= std::min({end, cnt}); ++i) {
            //                sum = (sum + dfs(end - 1, cnt - i, memo, end2cnt)) % m;
            //            }
            //            return memo[end][cnt] = sum;
        }
    }

    int numberOfPermutations(int n, vector<vector<int>> &requirements) {
        auto end2cnt = unordered_map<int, int>();
        for (auto &r: requirements) {
            end2cnt[r[0]] = r[1];
        }
        auto memo = vector<vector<long long>>(n + 1, vector<long long>(n * (n - 1) / 2 + 1, -1));
        return dfs(n - 1, end2cnt[n - 1], memo, end2cnt);
    }
};


int main() {
    Solution s;
    auto requirements = vector<vector<int>>({{2, 2}, {0, 0}});
    cout << s.numberOfPermutations(3, requirements) << endl;
    return 0;
}
