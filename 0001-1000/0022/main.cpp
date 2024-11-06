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
    vector<string> res;
    string path;
    void dfs(const int cnt1, const int cnt2, const int n) {
        if (cnt1 == n && cnt2 == n) {
            res.push_back(path);
        } else {
            if (cnt1 != n) {
                path.push_back('(');
                dfs(cnt1 + 1, cnt2, n);
                path.pop_back();
            }
            if (cnt1 != cnt2) {
                path.push_back(')');
                dfs(cnt1, cnt2 + 1, n);
                path.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
