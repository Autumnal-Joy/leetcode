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
    int closestCost(const vector<int> &baseCosts, vector<int> &toppingCosts, const int target) {
        for (int i = static_cast<int>(toppingCosts.size()) - 1; i >= 0; --i) {
            toppingCosts.push_back(toppingCosts[i]);
        }
        const auto n = static_cast<int>(baseCosts.size());
        const auto m = static_cast<int>(toppingCosts.size());
        auto res = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            const auto newTarget = target - baseCosts[i];
            if (newTarget <= 0) {
                if (std::abs(target - baseCosts[i]) < std::abs(target - res)) {
                    res = baseCosts[i];
                }
                continue;
            }
            auto dp = vector(2 * newTarget + 1, false);
            dp[0] = true;
            for (int j = 0, sum = 0; j < m; ++j) {
                sum = std::min(2 * newTarget, sum + toppingCosts[j]);
                for (int k = sum; k >= toppingCosts[j]; --k) {
                    dp[k] = dp[k] || dp[k - toppingCosts[j]];
                }
            }
            for (int diff = 0; diff <= newTarget; ++diff) {
                if (dp[newTarget - diff]) {
                    if (diff <= std::abs(res - target)) {
                        res = target - diff;
                    }
                    break;
                }
                if (dp[newTarget + diff]) {
                    if (diff < std::abs(res - target)) {
                        res = target + diff;
                    }
                    break;
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto baseCost = vector({8, 4, 4, 5, 8});
    auto toppingCost = vector({3, 10, 9, 10, 8, 10, 10, 9, 3});
    Solution().closestCost(baseCost, toppingCost, 6);
    return 0;
}
#endif
