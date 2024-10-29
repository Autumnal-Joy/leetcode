#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    vector<string> res;
    string path;

    void dfs(const int depth, const int ch) {
        if (depth == 0) {
            res.push_back(path);
        } else if (ch == '0') {
            path.push_back('1');
            dfs(depth - 1, '1');
            path.pop_back();
        } else {
            path.push_back('0');
            dfs(depth - 1, '0');
            path.pop_back();
            path.push_back('1');
            dfs(depth - 1, '1');
            path.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        dfs(n, '1');
        return res;
    }
};

int main() {

    return 0;
}
