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
public:
    int maxValueOfCoins(const vector<vector<int>> &piles, const int k) {
        const auto m = static_cast<int>(piles.size());
        // 前 n 个栈刚好取 j 次的最大和
        auto dp = vector(k + 1, -0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0, s = 0; i < m; ++i) {
            const auto n = static_cast<int>(piles[i].size());
            s = std::min(s + n, k);
            auto preSum = vector(n + 1, 0);
            for (int j = 1; j <= n; ++j) {
                preSum[j] = piles[i][j - 1] + preSum[j - 1];
            }
            for (int j = s; j >= 0; --j) {
                for (int cnt = 1; cnt <= j && cnt <= n; ++cnt) {
                    dp[j] = std::max(dp[j], dp[j - cnt] + preSum[cnt]);
                }
            }
        }
        return dp[k];
    }
};

#ifdef LEETCODE
int main() {
    const auto piles = vector<vector<int>>{{1, 100, 3}, {7, 8, 9}};
    Solution().maxValueOfCoins(piles, 2);
    return 0;
}
#endif
