#include <bits/stdc++.h>

using namespace std;

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

struct Counter {
    array<int, 26> cnt{};
    Counter() {}
    explicit Counter(const string_view &str) {
        count(str);
    }
    void count(const string_view &str) {
        for (const auto &c: str) {
            ++cnt[c - 'a'];
        }
    }
    Counter &operator+=(const Counter &other) {
        for (int i = 0; i < 26; ++i) {
            cnt[i] += other.cnt[i];
        }
        return *this;
    }
    bool operator==(const Counter &other) const {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != other.cnt[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
    static bool check(const vector<Counter> &ctrs, const int repeat) {
        auto newCtrs = vector<Counter>(ctrs.size() / repeat);
        for (int i = 0; i < ctrs.size(); ++i) {
            newCtrs[i / repeat] += ctrs[i];
        }
        return std::all_of(newCtrs.begin() + 1, newCtrs.end(), [&](const auto &ctr) {
            return newCtrs[0] == ctr;
        });
    }

public:
    int minAnagramLength(const string &s) {
        const auto &str = string_view(s);
        const auto n = static_cast<int>(str.size());
        const auto &ctr = Counter(str);
        auto k = std::gcd(ctr.cnt[0], ctr.cnt[1]);
        for (int i = 2; i < 26; ++i) {
            k = std::gcd(k, ctr.cnt[i]);
        }
        const auto len = n / k;
        auto ctrs = vector<Counter>(k);
        for (int i = 0; i < k; ++i) {
            ctrs[i].count(str.substr(i * len, len));
        }
        for (int repeat = 1; repeat <= k; ++repeat) {
            if (k % repeat) continue;
            if (check(ctrs, repeat)) {
                return repeat * len;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
