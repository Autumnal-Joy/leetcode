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

string join(const vector<string_view> &strs, const char ch) {
    auto res = string(strs[0]);
    for (int i = 1; i < strs.size(); ++i) {
        res += ch;
        res += strs[i];
    }
    return res;
}

class Solution {
    vector<string> res;
    vector<string_view> path;

    static bool valid(const string_view &s) {
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        int num = 0;
        for (const char ch: s) {
            num = num * 10 + ch - '0';
        }
        return num >= 0 && num <= 255;
    }

    void dfs(const string_view &s) {
        if (s.empty() && path.size() == 4) {
            res.push_back(join(path, '.'));
        }
        for (int len = 1; len <= std::min({s.size(), 3lu}); ++len) {
            if (const auto &temp = s.substr(0, len);
                valid(temp)) {
                path.push_back(temp);
                dfs(s.substr(len));
                path.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(const string &s) {
        if (s.size() >= 4 && s.size() <= 12) {
            dfs(s);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
