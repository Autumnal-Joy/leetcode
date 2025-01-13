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
    int minDifficulty(const vector<int> &jobDifficulty, int d) {
        const auto n = static_cast<int>(jobDifficulty.size());
        if (n < d) {
            return -1;
        }
        auto dp = array<int, 301>({});
        for (int j = 1; j <= n; ++j) {
            dp[j] = std::max(dp[j - 1], jobDifficulty[j - 1]);
        }
        dp[0] = 0x3f3f3f3f;
        for (int i = 2; i <= d; ++i) {
            for (int j = n; j >= 1; --j) {
                dp[j] = 0x3f3f3f3f;
                for (int j2 = j - 1, maxVal = 0; j2 >= 0; --j2) {
                    maxVal = std::max(maxVal, jobDifficulty[j2]);
                    dp[j] = std::min(dp[j], dp[j2] + maxVal);
                }
            }
        }
        return dp[n] < 0x3f3f3f3f ? dp[n] : -1;
    }
};

#ifdef LEETCODE
int main() {
    const auto jobDifficulty = vector({6, 5, 4, 3, 2, 1});
    Solution().minDifficulty(jobDifficulty, 2);
    return 0;
}
#endif
