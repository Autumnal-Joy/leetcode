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
    static bool isVowel(const char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    long long countOfSubstrings(const string &word, const int k) {
        const auto n = static_cast<int>(word.size());
        auto mp1 = unordered_map<char, int>();
        auto cntVowel1 = 0, cntNonVowel1 = 0;
        auto res1 = 0ll;
        for (int left = 0, right = 0; right < n;) {
            if (isVowel(word[right])) {
                if (++mp1[word[right]] == 1) {
                    ++cntVowel1;
                }
            } else {
                ++cntNonVowel1;
            }
            ++right;
            while (cntVowel1 >= 5 && cntNonVowel1 >= k) {
                res1 += n - right + 1;
                if (isVowel(word[left])) {
                    if (--mp1[word[left]] == 0) {
                        --cntVowel1;
                    }
                } else {
                    --cntNonVowel1;
                }
                ++left;
            }
        }
        auto mp2 = unordered_map<char, int>();
        auto cntVowel2 = 0, cntNonVowel2 = 0;
        auto res2 = 0ll;
        for (int left = 0, right = 0; right < n;) {
            if (isVowel(word[right])) {
                if (++mp2[word[right]] == 1) {
                    ++cntVowel2;
                }
            } else {
                ++cntNonVowel2;
            }
            ++right;
            while (cntVowel2 >= 5 && cntNonVowel2 >= k + 1) {
                res2 += n - right + 1;
                if (isVowel(word[left])) {
                    if (--mp2[word[left]] == 0) {
                        --cntVowel2;
                    }
                } else {
                    --cntNonVowel2;
                }
                ++left;
            }
        }
        return res1 - res2;
    }
};

#ifdef LOCAL
int main() {
    Solution s;
    s.countOfSubstrings("ieaouqqieaouqq", 1);
    return 0;
}
#endif
