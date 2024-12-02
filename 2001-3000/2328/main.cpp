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
TreeNode *vec2tree(const vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    auto q = queue<TreeNode *>();
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        auto node = q.front();
        q.pop();
        if (vec[i] != -1) {
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        if (i + 1 < vec.size() && vec[i + 1] != -1) {
            node->right = new TreeNode(vec[i + 1]);
            q.push(node->right);
        }
    }
    return root;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};
ListNode *vec2list(const vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}
vector<vector<int>> read(const string &filename) {
    auto res = vector<vector<int>>();
    auto ifs = ifstream(filename);
    auto line = string();
    while (getline(ifs, line)) {
        auto vec = vector<int>();
        auto iss = istringstream(line);
        for (int val; iss >> val;) {
            vec.push_back(val);
        }
        res.push_back(std::move(vec));
    }
    return res;
}
void write(const vector<int> &data, const string &filename) {
    auto ofs = ofstream(filename);
    ranges::copy(data, ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        ranges::copy(line, ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}
#endif

class Solution {
    long long M = 1e9 + 7;
    int m = 0;
    int n = 0;
    vector<vector<long long>> dp;
    long long dfs(const vector<vector<int>> &grid, const int i, const int j) {
        if (!dp[i][j]) {
            dp[i][j] = 1;
            if (i - 1 >= 0 && grid[i - 1][j] < grid[i][j]) {
                dp[i][j] = (dp[i][j] + dfs(grid, i - 1, j)) % M;
            }
            if (i + 1 < m && grid[i + 1][j] < grid[i][j]) {
                dp[i][j] = (dp[i][j] + dfs(grid, i + 1, j)) % M;
            }
            if (j - 1 >= 0 && grid[i][j - 1] < grid[i][j]) {
                dp[i][j] = (dp[i][j] + dfs(grid, i, j - 1)) % M;
            }
            if (j + 1 < n && grid[i][j + 1] < grid[i][j]) {
                dp[i][j] = (dp[i][j] + dfs(grid, i, j + 1)) % M;
            }
        }
        return dp[i][j];
    }

public:
    int countPaths(const vector<vector<int>> &grid) {
        m = static_cast<int>(grid.size());
        n = static_cast<int>(grid[0].size());
        dp = vector(m, vector(n, 0ll));
        auto res = 0ll;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = (res + dfs(grid, i, j)) % M;
            }
        }
        return static_cast<int>(res);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
