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

class Solution {
public:
    int bestTeamScore(const vector<int> &scores, vector<int> &ages) {
        const auto n = static_cast<int>(scores.size());
        auto index = vector(n, 0);
        std::iota(index.begin(), index.end(), 0);
        ranges::sort(index, [&](const int i, const int j) {
            if (ages[i] == ages[j]) return scores[i] < scores[j];
            return ages[i] < ages[j];
        });
        auto dp = vector(n, 0);
        auto res = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = scores[index[i]];
            for (int j = 0; j < i; ++j) {
                if (scores[index[j]] > scores[index[i]]) continue;
                dp[i] = std::max(dp[i], dp[j] + scores[index[i]]);
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto scores = vector({319776, 611683, 835240, 602298, 430007, 574, 142444, 858606, 734364, 896074});
    auto ages = vector({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    Solution().bestTeamScore(scores, ages);
    return 0;
}
#endif
