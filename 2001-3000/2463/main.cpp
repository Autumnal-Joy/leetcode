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
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        const auto m = static_cast<int>(robot.size());
        const auto n = static_cast<int>(factory.size());
        ranges::sort(robot);
        ranges::sort(factory, [](const auto &lhs, const auto &rhs) {
            return lhs[0] < rhs[0];
        });
        auto dp = vector(m + 1, vector(n + 1, 0x3f3f3f3f3f3f3f3fll));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                auto dist = 0ll;
                for (int k = i - 1, cap = factory[j - 1][1]; k >= 0 && cap > 0; --k, --cap) {
                    dist += std::abs(robot[k] - factory[j - 1][0]);
                    dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + dist);
                }
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

#ifdef LEETCODE
int main() {
    auto robot = vector({9, 11, 99});
    auto fact = vector<vector<int>>({{7, 1}, {10, 1}, {14, 1}, {96, 1}, {100, 1}});
    Solution().minimumTotalDistance(robot, fact);
    return 0;
}
#endif
