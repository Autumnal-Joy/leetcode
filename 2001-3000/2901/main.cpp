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

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(const vector<string> &words, vector<int> &groups) {
        const auto n = static_cast<int>(words.size());
        auto dist = [&](const int l, const int r) {
            auto d = 0;
            for (int i = 0; i < words[l].size(); ++i) {
                d += words[l][i] != words[r][i];
            }
            return d;
        };

        auto dp = vector(n, vector<int>());
        auto idx = -1, sz = 0;
        for (int i = 0; i < n; ++i) {
            dp[i].push_back(i);
            if (static_cast<int>(dp[i].size()) > sz) {
                idx = i, sz = static_cast<int>(dp[i].size());
            }
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() != words[j].size() || groups[i] == groups[j] || dist(i, j) != 1) continue;
                if (dp[i].size() >= dp[j].size()) {
                    dp[j] = dp[i];
                }
            }
        }
        auto res = vector<string>();
        ranges::transform(dp[idx], std::back_inserter(res), [&](const auto i) {
            return words[i];
        });
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto words = vector<string>({"bdb", "aaa", "ada"});
    auto groups = vector({2, 1, 3});
    Solution().getWordsInLongestSubsequence(words, groups);
    return 0;
}
#endif
