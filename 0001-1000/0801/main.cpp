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
    int minSwap(const vector<int> &nums1, const vector<int> &nums2) {
        const auto n = static_cast<int>(nums1.size());
        auto dp = vector(2, 0x3f3f3f3f);
        dp = {0, 1};
        for (int i = 1; i < n; ++i) {
            const auto cond1 = nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1];
            const auto cond2 = nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1];
            if (cond1 && cond2) {
                dp[0] = std::min(dp[0], dp[1]);
                dp[1] = dp[0] + 1;
            } else if (cond1) {
                ++dp[1];
            } else if (cond2) {
                swap(dp[0], dp[1]);
                ++dp[1];
            }
        }
        return std::min(dp[0], dp[1]);
    }
};

#ifdef LEETCODE
int main() {
    auto nums1 = vector({3, 3, 8, 9, 10});
    auto nums2 = vector({1, 7, 4, 6, 8});
    Solution().minSwap(nums1, nums2);
    return 0;
}
#endif
