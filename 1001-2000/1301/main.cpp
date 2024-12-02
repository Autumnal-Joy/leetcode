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

public:
    vector<int> pathsWithMaxScore(const vector<string> &board) {
        const auto n = static_cast<int>(board.size());
        auto point = vector(n, vector(n, 0));
        auto cnt = vector(n, vector(n, 0ll));
        point[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (cnt[i + 1][n - 1] && board[i][n - 1] != 'X') {
                point[i][n - 1] = point[i + 1][n - 1] + board[i][n - 1] - '0';
                cnt[i][n - 1] = 1;
            }
        }
        for (int j = n - 2; j >= 0; --j) {
            if (cnt[n - 1][j + 1] && board[n - 1][j] != 'X') {
                point[n - 1][j] = point[n - 1][j + 1] + board[n - 1][j] - '0';
                cnt[n - 1][j] = 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (board[i][j] == 'X') continue;
                point[i][j] = std::max(
                        point[i + 1][j + 1],
                        std::max(
                                point[i][j + 1],
                                point[i + 1][j]));
                if (point[i][j] == point[i + 1][j + 1]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i + 1][j + 1]) % M;
                }
                if (point[i][j] == point[i][j + 1]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i][j + 1]) % M;
                }
                if (point[i][j] == point[i + 1][j]) {
                    cnt[i][j] = (cnt[i][j] + cnt[i + 1][j]) % M;
                }
                if (cnt[i][j]) {
                    point[i][j] += board[i][j] == 'E' ? 0 : board[i][j] - '0';
                }
            }
        }
        return {(point[0][0]), static_cast<int>(cnt[0][0])};
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
