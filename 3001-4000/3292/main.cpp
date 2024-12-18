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

vector<int> z_function(const string &s) {
    const auto n = static_cast<int>(s.size());
    auto z = vector<int>(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

class Solution {
public:
    int minValidStrings(const vector<string> &words, const string &target) {
        const auto m = static_cast<int>(words.size());
        const auto n = static_cast<int>(target.size());
        auto jump = vector(n, 0);
        for (int i = 0; i < m; ++i) {
            const auto z = z_function(words[i] + "#" + target);
            const auto mi = static_cast<int>(words[i].size());
            for (int j = 0; j < n; ++j) {
                jump[j] = std::max(jump[j], z[mi + 1 + j]);
            }
        }
        auto dp = vector(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0, j = 1; i < n && j <= n; ++i) {
            // 从组成 j 个字符的状态，转移到组成 i 个字符的状态
            while (j - i <= jump[i] && j <= n) {
                dp[j] = std::min(dp[j], dp[i] + 1);
                ++j;
            }
        }
        return dp[n] == 0x3f3f3f3f ? -1 : dp[n];
    }
};

#ifdef LEETCODE
int main() {
    auto words = vector<string>{"abc", "aaaaa", "bcdef"};
    auto target = string("aabcdabc");
    Solution().minValidStrings(words, target);
    return 0;
}
#endif
