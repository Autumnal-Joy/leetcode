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

template<typename T, size_t N>
auto Array() {
    return array<T, N>({});
}
template<typename T, size_t N1, size_t N2>
auto Array() {
    return array<array<T, N2>, N1>({});
}
template<typename T, size_t N1, size_t N2, size_t N3>
auto Array() {
    return array<array<array<T, N3>, N2>, N1>({});
}
#define MAX_I 0x3f3f3f3f
#define MIN_I (-MAX_I)
#define MAX_LL 0x3f3f3f3f3f3f3f3f
#define MIN_LL (-MAX_LL)

class Solution {
    const long long Mod = 1e9 + 7;

public:
    int colorTheGrid(const int m, const int n) {
        const auto N = static_cast<int>(std::pow(3, m));

        auto state = vector(N, vector<int>());
        for (int i = 0; i < N; ++i) {
            auto col = vector(m, 0);
            for (int t = 0, v = i; t < m; ++t) {
                col[t] = v % 3;
                v /= 3;
            }
            state[i] = std::move(col);
        }

        auto adjacent = vector(N, false);
        for (int i = 0; i < N; ++i) {
            adjacent[i] = ranges::adjacent_find(state[i]) != state[i].end();
        }

        auto equal = vector(N, vector(N, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                equal[i][j] = !std::equal(state[i].begin(), state[i].end(), state[j].begin(), std::not_equal_to());
            }
        }

        auto memo = vector(n + 1, vector(N, -1ll));
        auto dfs = [&](auto &&self, const int i, const int pre) {
            if (memo[i][pre] == -1) {
                if (i == n) return 1ll;
                auto res = 0ll;
                for (int j = 0; j < N; ++j) {
                    if (adjacent[j]) continue;
                    if (equal[pre][j]) continue;
                    res = (res + self(self, i + 1, j)) % Mod;
                }
                memo[i][pre] = res;
            }
            return memo[i][pre];
        };

        auto res = 0ll;
        for (int j = 0; j < N; ++j) {
            if (adjacent[j]) continue;
            res = (res + dfs(dfs, 1, j)) % Mod;
        }
        return static_cast<int>(res);
    }
};

#ifdef LEETCODE
int main() {
    Solution().colorTheGrid(3, 2);
    return 0;
}
#endif
