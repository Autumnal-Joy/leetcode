#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

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
    string concat(string str, const char num) {
        if (str == "-") return str;
        const auto it = ranges::upper_bound(str, num, std::greater());
        str.insert(it, num);
        return str;
    }

public:
    string largestNumber(const vector<int> &cost, const int target) {
        const auto n = static_cast<int>(cost.size());
        auto dp = vector(target + 1, string("-"));
        dp[0] = "";
        for (int i = 0; i < n; ++i) {
            for (int j = cost[i]; j <= target; ++j) {
                dp[j] = std::max(dp[j], concat(dp[j - cost[i]], '1' + i), [](const string &lhs, const string &rhs) {
                    if (rhs == "-") return false;
                    if (lhs == "-") return true;
                    if (lhs.size() != rhs.size()) {
                        return lhs.size() < rhs.size();
                    }
                    return lhs < rhs;
                });
            }
        }
        return dp[target] == "-" ? "0" : dp[target];
    }
};

#ifdef LEETCODE
int main() {
    const auto cost = vector({4, 3, 2, 5, 6, 7, 2, 5, 5});
    Solution().largestNumber(cost, 9);
    return 0;
}
#endif
