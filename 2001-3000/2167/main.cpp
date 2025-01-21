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

#define Array1(type, size1) array<type, size1>
#define Array2(type, size1, size2) array<array<type, size2>, size1>
#define Array3(type, size1, size2, size3) array<array<array<type, size3>, size2>, size1>

constexpr long long N = 2 * 1e5 + 1;

class Solution {
public:
    int minimumTime(const string &s) {
        const auto n = static_cast<int>(s.size());
        auto prefix = Array1(int, N)();
        prefix[0] = s[0] != '0';
        for (int i = 1; i < n; ++i) {
            prefix[i] = s[i] == '0' ? prefix[i - 1] : std::min(prefix[i - 1] + 2, i + 1);
        }

        auto suffix = Array1(int, N)();
        suffix[n - 1] = s[n - 1] != '0';
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = s[i] == '0' ? suffix[i + 1] : std::min(suffix[i + 1] + 2, n - i);
        }

        auto res = std::min(prefix[n - 1], suffix[0]);
        for (int i = 0; i <= n - 2; ++i) {
            res = std::min(res, prefix[i] + suffix[i + 1]);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    Solution().minimumTime("100010001011010010110100101");
    return 0;
}
#endif
