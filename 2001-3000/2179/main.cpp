#include <bits/stdc++.h>
#define DEBUG

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

class BIT {
    int n;
    vector<int> data;

    static int lb(const int n) {
        return n & -n;
    }

public:
    explicit BIT(const int n) : n(n), data(n + 1) {}
    void add(int i, const int delta) {
        while (i <= n) {
            data[i] += delta;
            i += lb(i);
        }
    }
    [[nodiscard]] int sum(int i) const {
        auto res = 0;
        while (i > 0) {
            res += data[i];
            i -= lb(i);
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(const vector<int> &nums1, const vector<int> &nums2) {
        const auto n = static_cast<int>(nums1.size());
        auto mp = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            mp[nums2[i]] = i;
        }
        auto res = 0ll;
        auto bit = BIT(n);
        for (int i = 0; i < n; ++i) {
            const auto v = mp[nums1[i]];
            const auto less = bit.sum(v) + 0ll;
            const auto greater = n - v - 1 - (i - less);
            res += less * greater;
            bit.add(v + 1, 1);
        }
        return res;
    }
};

#ifdef LOCAL
int main() {
    Solution s;
    auto nums1 = vector{4, 0, 1, 3, 2};
    auto nums2 = vector{4, 1, 0, 3, 2};
    s.goodTriplets(nums1, nums2);
    return 0;
}
#endif
