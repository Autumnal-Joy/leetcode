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
    const long long MOD = 1e9 + 7;

public:
    int maxSum(const vector<int> &nums1, const vector<int> &nums2) {
        const auto m = static_cast<int>(nums1.size());
        const auto n = static_cast<int>(nums2.size());
        auto dp1 = vector(m + 1, -0x3f3f3f3f3f3f3f3fll);
        auto dp2 = vector(n + 1, -0x3f3f3f3f3f3f3f3fll);
        dp1[0] = dp2[0] = 0;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && (j == n || nums1[i] < nums2[j])) {
                dp1[i + 1] = dp1[i] + nums1[i];
                ++i;
            } else if (j < n && (i == m || nums1[i] > nums2[j])) {
                dp2[j + 1] = dp2[j] + nums2[j];
                ++j;
            } else {
                dp1[i + 1] = dp2[j + 1] = std::max(dp1[i], dp2[j]) + nums1[i];
                ++i, ++j;
            }
        }
        return static_cast<int>(std::max(dp1[m], dp2[n]) % MOD);
    }
};

#ifdef LEETCODE
int main() {
    auto nums1 = vector({2, 4, 5, 8, 10});
    auto nums2 = vector({4, 6, 8, 9});
    Solution().maxSum(nums1, nums2);
    return 0;
}
#endif
