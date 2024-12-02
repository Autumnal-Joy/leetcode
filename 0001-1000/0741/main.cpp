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
public:
    // n = 4
    // i 0  1   2    3   4  5 6
    // j 0 01 012 0123 123 23 3
    int cherryPickup(const vector<vector<int>> &grid) {
        const auto n = static_cast<int>(grid.size());
        auto dp = vector(2 * n - 1, vector(n, vector(n, -0x3f3f3f3f)));
        dp[0][0][0] = grid[0][0];
        for (int i = 1; i < 2 * n - 1; ++i) {
            for (int j = std::max(0, i + 1 - n); j < std::min(n, i + 1); ++j) {
                for (int k = std::max(0, i + 1 - n); k < std::min(n, i + 1); ++k) {
                    if (grid[i - j][j] == -1 || grid[i - k][k] == -1) continue;
                    if (j - 1 >= 0 && k - 1 >= 0) {
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
                    }
                    if (j - 1 >= 0) {
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k]);
                    }
                    if (k - 1 >= 0) {
                        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    }
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j][k] += grid[i - j][j] + (j == k ? 0 : grid[i - k][k]);
                }
            }
        }
        return std::max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};

#ifdef LEETCODE
int main() {
    const auto grid = vector<vector<int>>({
            {0, 1, -1},
            {1, 0, -1},
            {1, 1, 1},
    });
    Solution().cherryPickup(grid);
    return 0;
}
#endif
