#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    void dfs(string &s, int idx, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
        }
        for (int i = idx; i < s.size(); ++i) {
            std::swap(s[i], s[idx]);
            dfs(s, idx + 1, ans);
            std::swap(s[idx], s[i]);
        }
    }
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        sort(S.begin(), S.end());
        dfs(S, 0, ans);
        return ans;
    }
};

int main() {

    return 0;
}
