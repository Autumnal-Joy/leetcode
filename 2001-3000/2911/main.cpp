#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
        const auto node = q.front();
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

#define Array2(type, x, y) array<array<type, y>, x>

#define Array3(type, x, y, z) array<array<array<type, z>, y>, x>

const int MX = 201;
vector<vector<int>> factor(MX);
int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            factor[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
public:
    int minimumChanges(const string &s, const int k) {
        const auto n = static_cast<int>(s.size());
        auto semi = Array2(int, 200, 200)();
        for (auto &s1: semi) {
            s1.fill(0x3f3f3f3f);
        }

        for (int l = 0; l < n - 1; ++l) {
            for (int r = l + 1; r < n; ++r) {
                const auto len = r - l + 1;
                const auto str = string_view(s).substr(l, len);
                for (const auto &d: factor[len]) {
                    int cnt = 0;
                    for (int offset = 0; offset < d; offset++) {
                        for (int i = offset, j = len - d + offset; i < j; i += d, j -= d) {
                            cnt += str[i] != str[j];
                        }
                    }
                    semi[l][r] = std::min(semi[l][r], cnt);
                }
            }
        }

        auto dp = Array2(int, 101, 201)();
        for (auto &d1: dp) d1.fill(0x3f3f3f3f);
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int j2 = 0; j2 < j; ++j2) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j2] + semi[j2][j - 1]);
                }
            }
        }

        return dp[k][n];
    }
};

#ifdef LEETCODE
int main() {
    const auto s = string("abcac");
    Solution().minimumChanges(s, 2);
    return 0;
}
#endif
