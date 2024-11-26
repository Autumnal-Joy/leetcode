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
    vector<bitset<9>> row;
    vector<bitset<9>> col;
    vector<vector<bitset<9>>> block;

    [[nodiscard]] pair<int, int> next(const vector<vector<char>> &board) const {
        auto res = make_pair(-1, -1);
        auto minCnt = 10ul;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                const auto &digits = ~(row[i] | col[j] | block[i / 3][j / 3]);
                if (digits.count() < minCnt) {
                    minCnt = digits.count();
                    res = make_pair(i, j);
                }
            }
        }
        return res;
    }
    bool dfs(vector<vector<char>> &board, const int cnt) {
        if (cnt == 0) { return true; }
        const auto [i, j] = next(board);
        const auto exist = row[i] | col[j] | block[i / 3][j / 3];
        for (int digit = 0; digit < 9; ++digit) {
            if (exist[digit]) continue;
            row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
            board[i][j] = '1' + digit;
            if (dfs(board, cnt - 1)) { return true; }
            board[i][j] = '.';
            row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = false;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        row = vector<bitset<9>>(9);
        col = vector<bitset<9>>(9);
        block = vector(3, vector<bitset<9>>(3));
        int cnt = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                const auto digit = board[i][j] - '1';
                row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
            }
        }
        dfs(board, cnt);
    }
};

#ifdef LEETCODE
int main() {
    auto board = vector<vector<char>>({
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    });
    Solution().solveSudoku(board);
    return 0;
}
#endif
