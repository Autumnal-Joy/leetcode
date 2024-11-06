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
    vector<vector<string>> res;
    vector<string> path;

    void dfs(const string &s, const int begin, const vector<vector<bool>> &isPalindrome) {
        if (begin == s.size()) {
            res.push_back(path);
        }
        for (int i = begin; i < s.size(); ++i) {
            if (isPalindrome[begin][i]) {
                path.push_back(s.substr(begin, i - begin + 1));
                dfs(s, i + 1, isPalindrome);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(const string &s) {
        const auto n = static_cast<int>(s.size());
        auto isPalindrome = vector(n, vector(n, false));
        isPalindrome[0][0] = true;
        for (int i = 1; i < n; ++i) {
            isPalindrome[i][i] = true;
            isPalindrome[i - 1][i] = s[i - 1] == s[i];
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                isPalindrome[i][i + len - 1] = isPalindrome[i + 1][i + len - 2] && s[i] == s[i + len - 1];
            }
        }
        dfs(s, 0, isPalindrome);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
