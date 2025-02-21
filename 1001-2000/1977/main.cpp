#include <bits/stdc++.h>

#ifdef LOCAL
#include "lc_structures.h"
#include "log.h"
#else
#define dbg(x...) (x)
#endif

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

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

TreeNode *vec2tree(const std::vector<int> &vec) {
    if (vec.empty()) {
        return nullptr;
    }
    auto *root = new TreeNode(vec[0]);
    auto q = std::queue<TreeNode *>();
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

ListNode *vec2list(const std::vector<int> &vec) {
    ListNode head;
    ListNode *p = &head;
    for (const auto &val: vec) {
        p->next = new ListNode(val);
        p = p->next;
    }
    return head.next;
}

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

class Solution {

public:
    int numberOfCombinations(const string &num) {
        const auto n = static_cast<int>(num.size());
        auto lcm = vector(n + 1, vector(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcm[i][j] = lcm[i + 1][j + 1] + 1;
                }
            }
        }

        auto lower = [&](const int i, const int j, const int len) {
            const auto common = lcm[i][j];
            return common >= len || num[i + common] < num[j + common];
        };

        // dp[i][j] = sum(dp[i-len][len]), len from 1 to j
        // 状态转移两个维度的下标都在变，不容易优化
        auto dp = vector(n + 1, vector(n + 1, 0ll));
        dp[0][0] = 1ll;
        auto sum = vector(n + 1, vector(n + 1, 0ll));
        for (int i = 1; i <= n; ++i) {
            sum[0][i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (num[i - j] == '0') continue;
                dp[i][j] = sum[i - j][j];
                if (i - 2 * j >= 0 && lower(i - 2 * j, i - j, j)) {
                    dp[i][j] += dp[i - j][j];
                    dp[i][j] %= MOD;
                }
            }
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = (sum[i][j - 1] + dp[i][j - 1]) % MOD;
            }
        }
        return static_cast<int>(std::reduce(dp[n].begin(), dp[n].end()) % MOD);
    }
};

#ifdef LOCAL
int main() {
    Solution s;
    dbg(s.numberOfCombinations("327"));
    return 0;
}
#endif
