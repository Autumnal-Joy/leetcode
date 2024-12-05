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

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    explicit Node(const int x) : val(x), next(nullptr) {}
    Node(const int x, Node *next) : val(x), next(next) {}
};
#endif

class Solution {
    long long M = 1e9 + 7;

public:
    int countSubMultisets(const vector<int> &nums, const int l, const int r) {
        auto counter = unordered_map<int, int>();
        for (const auto num: nums) {
            ++counter[num];
        }
        const auto zero = counter[0];
        counter.erase(0);
        auto dp = vector(r + 1, zero + 1ll);
        for (auto [x, cnt]: counter) {
            const auto temp = dp;
            for (int j = 0; j <= r; ++j) {
                if (j - x >= 0) {
                    if (j - cnt * x - x >= 0) {
                        dp[j] = (temp[j] + dp[j - x] + M - temp[j - cnt * x - x]) % M;
                    } else {
                        dp[j] = (temp[j] + dp[j - x]) % M;
                    }
                }
            }
        }
        return static_cast<int>((dp[r] + M - (l - 1 >= 0 ? dp[l - 1] : 0)) % M);
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector<int>{0, 0, 1, 2, 3};
    cout << Solution().countSubMultisets(nums, 2, 3) << endl;
    return 0;
}

#endif
