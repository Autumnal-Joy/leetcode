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

class Solution {
public:
    int maxSumDivThree(const vector<int> &nums) {
        const auto n = static_cast<int>(nums.size());
        auto dp = vector(3, 0);
        dp = {0, -0x3f3f3f3f, -0x3f3f3f3f};
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 3 == 0) {
                dp[0] += nums[i];
                dp[1] += nums[i];
                dp[2] += nums[i];
            } else if (nums[i] % 3 == 1) {
                const auto temp = dp[2];
                dp[2] = std::max(dp[2], dp[1] + nums[i]);
                dp[1] = std::max(dp[1], dp[0] + nums[i]);
                dp[0] = std::max(dp[0], temp + nums[i]);
            } else {
                const auto temp = dp[0];
                dp[0] = std::max(dp[0], dp[1] + nums[i]);
                dp[1] = std::max(dp[1], dp[2] + nums[i]);
                dp[2] = std::max(dp[2], temp + nums[i]);
            }
        }
        return dp[0];
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({3, 6, 5, 1, 8});
    Solution().maxSumDivThree(nums);
    return 0;
}
#endif