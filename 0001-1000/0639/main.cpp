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
    long long Mod = 1e9 + 7;

public:
    int numDecodings(string s) {
        const auto n = static_cast<int>(s.size());
        auto dp = vector(n + 1, 0ll);
        dp[0] = 1;
        if (s[0] == '*') {
            dp[1] = 9;
        } else {
            dp[1] = s[0] == '0' ? 0 : 1;
        }
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == '*' && s[i - 2] == '*') {
                dp[i] = dp[i - 1] * 9 + dp[i - 2] * 15;
            } else if (s[i - 1] == '*') {
                dp[i] = dp[i - 1] * 9 + dp[i - 2] * (s[i - 2] == '1' ? 9 : (s[i - 2] == '2' ? 6 : 0));
            } else if (s[i - 2] == '*') {
                dp[i] = (s[i - 1] != '0' ? dp[i - 1] : 0) + dp[i - 2] * (s[i - 1] <= '6' ? 2 : 1);
            } else {
                dp[i] = dp[i - 1] * (s[i - 1] == '0' ? 0 : 1) + dp[i - 2] * (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6') ? 1 : 0);
            }
            dp[i] %= Mod;
        }
        return dp[n];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
