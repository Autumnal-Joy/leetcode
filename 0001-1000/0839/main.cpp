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
    bool similar(const string &a, const string &b) {
        auto d1 = string(), d2 = string();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (d1.size() == 2) {
                    return false;
                }
                d1.push_back(a[i]);
                d2.push_back(b[i]);
            }
        }
        return d1.empty() || d1[0] == d2[1] && d1[1] == d2[0];
    }

public:
    int numSimilarGroups(vector<string> &strs) {
        const int n = static_cast<int>(strs.size());
        auto adj = vector(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (similar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        auto visited = vector(n, false);

        function<void(int)> dfs = [&](const int i) {
            visited[i] = true;
            for (auto j: adj[i]) {
                if (!visited[j]) {
                    dfs(j);
                }
            }
        };

        auto res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++res;
            dfs(i);
        }

        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
