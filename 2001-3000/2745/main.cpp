#include <bits/stdc++.h>

using namespace std;

static auto _ = [] {
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

auto dp = array<array<array<array<int, 3>, 51>, 51>, 51>({});

static auto _2 = [] {
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 50; ++k) {
                if (i >= 1) {
                    dp[i][j][k][0] = std::max(dp[i - 1][j][k][1], dp[i - 1][j][k][2]) + 2;
                }
                if (j >= 1) {
                    dp[i][j][k][1] = dp[i][j - 1][k][0] + 2;
                }
                if (k >= 1) {
                    dp[i][j][k][2] = std::max(dp[i][j][k - 1][1], dp[i][j][k - 1][2]) + 2;
                }
            }
        }
    }
    return 0;
}();


class Solution {
public:
    int longestString(const int x, const int y, const int z) {
        return ranges::max(dp[x][y][z]);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
