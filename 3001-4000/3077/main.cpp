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


constexpr long long INF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    long long maximumStrength(const vector<int> &nums, const int k) {
        const auto n = static_cast<int>(nums.size());
        auto dp = array<array<long long, 2>, 10001>();
        for (int i = 1; i <= k; ++i) {
            const auto coe = 1ll * (i & 1 ? 1 : -1) * (k + 1 - i);
            const auto temp = dp;
            dp[0] = {-INF, -INF};
            for (int j = 1; j <= n - k + i; ++j) {
                dp[j][0] = std::max(dp[j - 1][0], dp[j - 1][1]);
                dp[j][1] = std::max(dp[j - 1][1],
                                    std::max(temp[j - 1][0],
                                             temp[j - 1][1])) +
                           coe * nums[j - 1];
            }
        }
        return std::max(dp[n][0], dp[n][1]);
    }
};

#ifdef LEETCODE
int main() {
    const auto nums = vector({-1, -2, -3});
    Solution().maximumStrength(nums, 1);
    return 0;
}
#endif
