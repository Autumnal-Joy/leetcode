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
    int res = 0;
    static int digit(int x) {
        auto res = 0;
        while (x) {
            auto [quot, rem] = std::div(x, 10);
            res += rem;
            x = quot;
        }
        return res;
    }
    void dfs(int x, int y, int m, int n, int cnt, vector<vector<bool>> &visited) {
        ++res;
        visited[x][y] = true;
        if (x + 1 < m && !visited[x + 1][y] && digit(x + 1) + digit(y) <= cnt) {
            dfs(x + 1, y, m, n, cnt, visited);
        }
        if (y + 1 < n && !visited[x][y + 1] && digit(x) + digit(y + 1) <= cnt) {
            dfs(x, y + 1, m, n, cnt, visited);
        }
    }

public:
    int wardrobeFinishing(int m, int n, int cnt) {
        auto visited = vector(m, vector(n, false));
        dfs(0, 0, m, n, cnt, visited);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
