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
    static bool canBuy(const vector<int> &needs, const vector<int> &pack) {
        for (int i = 0; i < needs.size(); ++i) {
            if (needs[i] < pack[i]) {
                return false;
            }
        }
        return true;
    }
    int dfs(vector<vector<int>> &packs, vector<int> &needs, map<vector<int>, int> &memo) {
        if (const auto it = memo.find(needs); it != memo.end()) return it->second;
        int res = 0;
        for (const auto &pack: packs) {
            if (!canBuy(needs, pack)) continue;
            for (int i = 0; i < needs.size(); ++i) {
                needs[i] -= pack[i];
            }
            res = std::max({res, dfs(packs, needs, memo) + pack.back()});
            for (int i = 0; i < needs.size(); ++i) {
                needs[i] += pack[i];
            }
        }
        memo[needs] = res;
        return res;
    }

public:
    int shoppingOffers(const vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        const int n = static_cast<int>(price.size());
        auto total = 0;
        for (int i = 0; i < n; ++i) {
            total += price[i] * needs[i];
        }
        auto packs = vector<vector<int>>();
        for (auto &pack: special) {
            auto sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += price[i] * pack[i];
            }
            if (sum > pack[n]) {
                pack[n] = sum - pack[n];
                packs.push_back(std::move(pack));
            }
        }
        auto memo = map<vector<int>, int>();
        return total - dfs(packs, needs, memo);
    }
};

#ifdef LEETCODE
int main() {
    auto price = vector({2, 5});
    auto special = vector<vector<int>>({{3, 0, 5}, {1, 2, 10}});
    auto needs = vector({3, 2});
    cout << Solution().shoppingOffers(price, special, needs) << endl;

    return 0;
}
#endif
