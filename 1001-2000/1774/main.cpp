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
        auto n = static_cast<int>(toppingCosts.size());
        auto nums = vector(n * 2, 0);
        for (int i = 0; i < n; ++i) {
            nums[i] = toppingCosts[i];
            nums[i + n] = toppingCosts[i];
        }
        n <<= 1;
        auto dp = vector(target * 2 + 1, false);
        for (const auto &baseCost: baseCosts) {
            if (baseCost <= target * 2) {
                dp[baseCost] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = target * 2; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        for (int diff = 0; diff <= target; ++diff) {
            if (dp[target - diff]) return target - diff;
            if (dp[target + diff]) return target + diff;
        }
        return ranges::min(baseCosts);
    }
};

#ifdef LEETCODE
int main() {
    auto baseCost = vector({1, 7});
    auto toppingCost = vector({3, 4});
    Solution().closestCost(baseCost, toppingCost, 10);
    return 0;
}
#endif
