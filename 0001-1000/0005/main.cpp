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

vector<int> manacher1(const string &s) {
    const auto n = static_cast<int>(s.size());
    auto d1 = vector(n, 0);
    for (int i = 0, l = 0, r = -1; i < s.size(); ++i) {
        int k = i > r ? 1 : std::min({r - i + 1, d1[l + r - i]});
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}
vector<int> manacher2(const string &s) {
    const auto n = static_cast<int>(s.size());
    auto d2 = vector(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = i > r ? 0 : std::min({r - i + 1, d2[l + r - i + 1]});
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    return d2;
}

class Solution {
public:
    string longestPalindrome(const string &s) {
        const auto d1 = manacher1(s);
        const auto d2 = manacher2(s);
        auto begin = 0, len = 1;
        for (int i = 0; i < d1.size(); ++i) {
            if (len < d1[i] * 2 - 1) {
                len = d1[i] * 2 - 1;
                begin = i - d1[i] + 1;
            }
        }
        for (int i = 0; i < d2.size(); ++i) {
            if (len < d2[i] * 2) {
                len = d2[i] * 2;
                begin = i - d2[i];
            }
        }
        return s.substr(begin, len);
    }
};

#ifdef LEETCODE
int main() {
    Solution().longestPalindrome("babbada");
    return 0;
}
#endif
