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
    int countPyramids(vector<vector<int>> &grid) {
        const auto m = static_cast<int>(grid.size());
        const auto n = static_cast<int>(grid[0].size());
        auto dp1 = vector(m, vector(n, 0));
        dp1[m - 1] = grid[m - 1];
        for (int i = m - 2; i >= 0; --i) {
            dp1[i][0] = grid[i][0];
            dp1[i][n - 1] = grid[i][n - 1];
            for (int j = 1; j + 1 < n; ++j) {
                if (!grid[i][j]) continue;
                dp1[i][j] = 1 + std::min({
                                        dp1[i + 1][j - 1],
                                        dp1[i + 1][j],
                                        dp1[i + 1][j + 1],
                                });
            }
        }
        auto dp2 = vector(m, vector(n, 0));
        dp2[0] = grid[0];
        for (int i = 1; i < m; ++i) {
            dp2[i][0] = grid[i][0];
            dp2[i][n - 1] = grid[i][n - 1];
            for (int j = 1; j + 1 < n; ++j) {
                if (!grid[i][j]) continue;
                dp2[i][j] = 1 + std::min({
                                        dp2[i - 1][j - 1],
                                        dp2[i - 1][j],
                                        dp2[i - 1][j + 1],
                                });
            }
        }
        auto res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += std::max({dp1[i][j] + dp2[i][j] - 2, 0});
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto grid = vector<vector<int>>({
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 0, 1},
    });
    Solution().countPyramids(grid);
    return 0;
}
#endif
