#include <bits/stdc++.h>

using namespace std;

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
    int movesToChessboard(const vector<vector<int>> &board) {
        const auto n = static_cast<int>(board.size());

        auto pattern1 = 0, pattern2 = 0;
        for (int i = 0; i < n; ++i) {
            pattern1 = (pattern1 << 1) | (i & 1);
            pattern2 = (pattern2 << 1) | ((i + 1) & 1);
        }

        auto row = vector<int>();
        auto col = vector<int>();
        for (int i = 0; i < n; ++i) {
            int val = 0;
            for (int j = 0; j < n; ++j) {
                val = (val << 1) | board[i][j];
            }
            if (ranges::find(row, val) == row.end()) {
                row.push_back(val);
            }
        }
        if (row.size() != 2 || (pattern1 ^ pattern2) != (row[0] ^ row[1])) {
            return -1;
        }
        for (int j = 0; j < n; ++j) {
            int val = 0;
            for (int i = 0; i < n; ++i) {
                val = (val << 1) | board[i][j];
            }
            if (ranges::find(col, val) == col.end()) {
                col.push_back(val);
            }
        }
        if (col.size() != 2 || (pattern1 ^ pattern2) != (col[0] ^ col[1])) {
            return -1;
        }

        auto step = 0;
        const auto row_diff1 = __builtin_popcount(row[0] ^ pattern1),
                   row_diff2 = __builtin_popcount(row[0] ^ pattern2);
        if (row_diff1 & 1 && row_diff2 & 1) {
            return -1;
        }
        if (row_diff1 & 1) {
            step += row_diff2 >> 1;
        } else if (row_diff2 & 1) {
            step += row_diff1 >> 1;
        } else {
            step += std::min(row_diff1, row_diff2) >> 1;
        }
        const auto col_diff1 = __builtin_popcount(col[0] ^ pattern1),
                   col_diff2 = __builtin_popcount(col[0] ^ pattern2);
        if (col_diff1 & 1 && col_diff2 & 1) {
            return -1;
        }
        if (col_diff1 & 1) {
            step += col_diff2 >> 1;
        } else if (col_diff2 & 1) {
            step += col_diff1 >> 1;
        } else {
            step += std::min(col_diff1, col_diff2) >> 1;
        }
        return step;
    }
};


#ifdef LEETCODE
int main() {
    auto board = vector<vector<int>>({
            {0, 0, 0},
            {0, 0, 1},
            {0, 0, 0},
    });
    auto board1 = vector<vector<int>>({
            {1, 1, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
    });
    Solution().movesToChessboard(board);
    return 0;
}
#endif
