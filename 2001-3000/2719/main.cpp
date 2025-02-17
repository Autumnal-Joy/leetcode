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
    copy(data.begin(), data.end(), ostream_iterator<int>(ofs, " "));
    ofs << '\n';
}
void write(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    for (const auto &line: data) {
        copy(line.begin(), line.end(), ostream_iterator<int>(ofs, " "));
        ofs << '\n';
    }
}
#endif

#if __cplusplus >= 201703L
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
#endif

#define MAX_I 0x3f3f3f3f
#define MIN_I (-MAX_I)
#define MAX_LL 0x3f3f3f3f3f3f3f3f
#define MIN_LL (-MAX_LL)

class Solution {
    const long long Mod = 1e9 + 7;

public:
    int count(const string &num1, const string &num2, const int min_sum, const int max_sum) {
        const auto &num1_pad = string(num2.size() - num1.size(), '0') + num1;
        auto memo = Array<int, 24, 2, 2, 300>();
        fillArray(memo, -1);

        auto dp = [&](auto &&self, const int i, const bool &lo_lim, const bool &hi_lim, const int sum) -> int {
            if (sum > max_sum) return 0;
            if (i == num1_pad.size()) return sum >= min_sum;

            auto &m = memo[i][lo_lim][hi_lim][sum];
            if (m != -1) return m;

            const auto lo = lo_lim ? num1_pad[i] - '0' : 0;
            const auto hi = hi_lim ? num2[i] - '0' : 9;

            auto res = 0ll;
            for (int d = lo; d <= hi; ++d) {
                res += self(self, i + 1, lo_lim && d == lo, hi_lim && d == hi, sum + d);
                res %= Mod;
            }
            return m = static_cast<int>(res);
        };
        return dp(dp, 0, true, true, 0);
    }
};

#ifdef LEETCODE
int main() {
    Solution().count("123", "321", 10, 20);
    return 0;
}
#endif
