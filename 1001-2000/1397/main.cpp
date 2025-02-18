#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

#ifdef LEETCODE

#ifndef TREE_NODE
#define TREE_NODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x = 0) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
#endif

#ifndef LIST_NODE
#define LIST_NODE
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
#endif

#endif

using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

template<class T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

constexpr int MAX_I = 0x3f3f3f3f;
constexpr int MIN_I = -MAX_I;
constexpr int MOD = 1e9 + 7;
constexpr ll MAX_LL = 0x3f3f3f3f'3f3f3f3f;
constexpr ll MIN_LL = -MAX_LL;
constexpr double EPS = 1e-8;

vector<vector<int>> read2d(const string &filename) {
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
void write1d(const vector<int> &data, const string &filename) {
    auto ofs = ofstream(filename);
    std::copy(data.begin(), data.end(), ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write2d(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        std::copy(line.begin(), line.end(), ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}

template<typename T, size_t N, size_t... Ns>
auto Array() {
    if constexpr (sizeof...(Ns) == 0) {
        return array<T, N>{};
    } else {
        return array<decltype(Array<T, Ns...>()), N>{};
    }
}

template<typename T>
struct is_nd_array : std::false_type {};

template<typename T, size_t N>
struct is_nd_array<array<T, N>> : std::true_type {};

template<typename T, typename V>
void fillArray(T &arr, const V &val) {
    if constexpr (is_nd_array<T>::value) {
        for (auto &elem: arr) {
            fillArray(elem, val);
        }
    } else {
        arr = val;
    }
}

template<typename T>
void print(const T &x) { cerr << x; }

void print(const char &x) { cerr << '\'' << x << '\''; }
void print(const string &x) { cerr << '\"' << x << '\"'; }
void print(const char *const &x) { cerr << '\"' << x << '\"'; }
void print(const bool &x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void print(const pair<T, V> &x) {
    cerr << "{";
    print(x.first);
    cerr << ", ";
    print(x.second);
    cerr << "}";
}

template<typename T, typename... Args>
void print(T t, Args... v) { print(t), print(v...); }

template<std::ranges::range T>
void print(const T &x) {
    cerr << "{";
    int f = 0;
    for (auto &i: x) {
        cerr << (f++ ? ", " : "");
        print(i);
    }
    cerr << "}";
}

#define dbg(x...)                                                \
    cerr << __func__ << ":" << __LINE__ << " [" << #x << "] = "; \
    print(x);                                                    \
    cerr << endl;

vector<int> buildPrefixTable(const string &pattern) {
    const int n = static_cast<int>(pattern.size());
    auto prefix = vector(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) j = prefix[j - 1];
        if (pattern[i] == pattern[j]) ++j;
        prefix[i] = j;
    }
    return prefix;
}


class Solution {
public:
    int findGoodStrings(const int n, const string &s1, const string &s2, const string &evil) {
        auto prefix = buildPrefixTable(evil);

        auto memo = Array<int, 501, 2, 2, 51>();
        fillArray(memo, -1);

        auto dfs = [&](auto &&self, const int i, const bool lo_lim, const bool hi_lim, const int j) -> int {
            auto &m = memo[i][lo_lim][hi_lim][j];
            if (m != -1) return m;

            if (j == evil.size()) return 0;
            if (i == n) return 1;

            const auto lo = lo_lim ? s1[i] : 'a';
            const auto hi = hi_lim ? s2[i] : 'z';
            auto res = 0ll;
            for (char c = lo; c <= hi; ++c) {
                auto t = j;
                while (t > 0 && c != evil[t]) t = prefix[t - 1];
                res += self(self, i + 1, lo_lim && c == lo, hi_lim && c == hi, t + (c == evil[t]));
            }
            return m = static_cast<int>(res % MOD);
        };

        return dfs(dfs, 0, true, true, 0);
    }
};

#ifdef LEETCODE
int main() {
    auto s = Solution();
    auto s1 = "sa", s2 = "sz", evil = "sd";
    dbg(s.findGoodStrings(2, s1, s2, evil));
    return 0;
}
#endif
