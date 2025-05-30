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

template<typename T>
struct is_nd_array<vector<T>> : std::true_type {};

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
    vector<int> smallestSufficientTeam(const vector<string> &req_skills, vector<vector<string>> &people) {
        const auto n = static_cast<int>(req_skills.size());
        const auto m = static_cast<int>(people.size());
        auto mp = unordered_map<string, int>();
        for (int i = 0; i < n; ++i) {
            mp[req_skills[i]] = i;
        }
        auto people_skills = vector<int>();
        for (const auto &person: people) {
            auto skill = 0;
            for (const auto &s: person) {
                skill |= 1 << mp[s];
            }
            people_skills.push_back(skill);
        }
        auto dp = vector(1 << n, vector<int>());
        auto dp2 = vector(1 << n, MAX_I);
        dp2[0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int s1 = 0; s1 < 1 << n; ++s1) {
                const auto s2 = s1 | people_skills[i];
                if (dp2[s2] > dp2[s1] + 1) {
                    dp[s2] = dp[s1];
                    dp[s2].push_back(i);
                    dp2[s2] = dp2[s1] + 1;
                }
            }
        }
        return dp.back();
    }
};

#ifdef LOCAL
int main() {
    auto req_skills = vector<string>({"java", "nodejs", "reactjs"});
    auto people = vector<vector<string>>({{"java"}, {"nodejs"}, {"nodejs", "reactjs"}});
    Solution s;
    s.smallestSufficientTeam(req_skills, people);
    return 0;
}
#endif
