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

template<typename Pred>
int last(int l, int r, Pred pred) {
    while (l + 1 < r) {
        const auto m = l + (r - l) / 2;
        if (pred(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

class Solution {
public:
    int jobScheduling(const vector<int> &st, const vector<int> &et, const vector<int> &pf) {
        const auto n = static_cast<int>(st.size());
        auto id = vector(n, 0);
        std::iota(id.begin(), id.end(), 0);
        ranges::sort(id, [&](const auto &l, const auto &r) {
            return et[l] < et[r];
        });
        auto dp = vector(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            const auto j = last(-1, i - 1, [&](const auto &k) {
                return et[id[k]] <= st[id[i - 1]];
            });
            dp[i] = std::max(dp[i], dp[j + 1] + pf[id[i - 1]]);
        }

        return dp[n];
    }
};

#ifdef LEETCODE
int main() {
    const auto st = vector({1, 2, 3, 3});
    const auto et = vector({3, 4, 5, 6});
    const auto pf = vector({50, 10, 40, 70});
    Solution().jobScheduling(st, et, pf);
    return 0;
}
#endif
