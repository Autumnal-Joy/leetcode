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
    int maxMoves(const vector<vector<int>> &grid) {
        const auto m = static_cast<int>(grid.size());
        const auto n = static_cast<int>(grid[0].size());
        auto dp = vector(m, vector(n, false));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = true;
        }
        auto res = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (dp[i][j - 1] && grid[i][j] > grid[i][j - 1] ||
                    i - 1 >= 0 && dp[i - 1][j - 1] && grid[i][j] > grid[i - 1][j - 1] ||
                    i + 1 < m && dp[i + 1][j - 1] && grid[i][j] > grid[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res = std::max(res, j);
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto grid = vector<vector<int>>({
            {65, 200, 263, 220, 91, 183, 2, 187, 175, 61, 225, 120, 39},
            {111, 242, 294, 31, 241, 90, 145, 25, 262, 214, 145, 71, 294},
            {152, 25, 240, 69, 279, 238, 222, 9, 137, 277, 8, 143, 143},
            {189, 31, 86, 250, 20, 63, 188, 209, 75, 22, 127, 272, 110},
            {122, 94, 298, 25, 90, 169, 68, 3, 208, 274, 202, 135, 275},
            {205, 20, 171, 90, 70, 272, 280, 138, 142, 151, 80, 122, 130},
            {284, 272, 271, 269, 265, 134, 185, 243, 247, 50, 283, 20, 232},
            {266, 236, 265, 234, 249, 62, 98, 130, 122, 226, 285, 168, 204},
            {231, 24, 256, 101, 142, 28, 268, 82, 111, 63, 115, 13, 144},
            {277, 277, 31, 144, 49, 132, 28, 138, 133, 29, 286, 45, 93},
            {163, 96, 25, 9, 3, 159, 148, 59, 25, 81, 233, 127, 12},
            {127, 38, 31, 209, 300, 256, 15, 43, 74, 64, 73, 141, 200},
    });
    Solution().maxMoves(grid);
    return 0;
}
#endif
