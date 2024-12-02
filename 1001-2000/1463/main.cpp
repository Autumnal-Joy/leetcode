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
    int cherryPickup(const vector<vector<int>> &grid) {
        const auto m = static_cast<int>(grid.size());
        const auto n = static_cast<int>(grid[0].size());
        auto dp = vector(m, vector(n, vector(n, -0x3f3f3f3f)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        auto res = 0;
        for (int i = 1; i < m; ++i) {
            for (int to1 = 0; to1 < n; ++to1) {
                for (int to2 = 0; to2 < n; ++to2) {
                    for (int from1 = to1 - 1; from1 <= to1 + 1; ++from1) {
                        for (int from2 = to2 - 1; from2 <= to2 + 1; ++from2) {
                            if (from1 < 0 || from1 >= n || from2 < 0 || from2 >= n) continue;
                            dp[i][to1][to2] = std::max(dp[i][to1][to2], dp[i - 1][from1][from2]);
                        }
                    }
                    dp[i][to1][to2] += grid[i][to1] + (to1 != to2 ? grid[i][to2] : 0);
                    if (i == m - 1) {
                        res = std::max(res, dp[i][to1][to2]);
                    }
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto grid = vector<vector<int>>({{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}});
    Solution().cherryPickup(grid);
    return 0;
}
#endif
