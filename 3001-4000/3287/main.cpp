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

#define N 400
#define K 200
#define U 127

class Solution {
public:
    int maxValue(vector<int> &nums, const int k) {
        const auto n = static_cast<int>(nums.size());
        // dp1[i][j][k] 表示前 i 个数中选择 j 个数，or 值为 k 是否可行
        auto dp1 = array<array<bool, U + 1>, K + 1>();
        auto prefix = array<array<bool, U + 1>, N + 1>();
        dp1[0][0] = true;
        for (int i = 0; i < n - k; ++i) {
            for (int j = std::min(i, k); j >= 0; --j) {
                for (int x = 0; x <= U; ++x) {
                    if (dp1[j][x]) {
                        dp1[j + 1][x | nums[i]] = true;
                    }
                }
                if (i + 1 >= k) {
                    prefix[i + 1] = dp1[k];
                }
            }
        }
        ranges::reverse(nums);
        // dp2[i][j][k] 后 i 个数中选择 j 个数，or 值为 k 是否可行
        auto dp2 = array<array<bool, U + 1>, K + 1>();
        auto suffix = array<array<bool, U + 1>, N + 1>();
        dp2[0][0] = true;
        for (int i = 0; i < n - k; ++i) {
            for (int j = std::min(i, k); j >= 0; --j) {
                for (int x = 0; x <= U; ++x) {
                    if (dp2[j][x]) {
                        dp2[j + 1][x | nums[i]] = true;
                    }
                }
                if (i + 1 >= k) {
                    suffix[i + 1] = dp2[k];
                }
            }
        }

        auto res = 0;
        for (int split = k; split <= n - k; ++split) {
            const auto &pre = prefix[split];
            const auto &suf = suffix[n - split];
            for (int i = 0; i <= U; ++i) {
                if (!pre[i]) continue;
                for (int j = 0; j <= U; ++j) {
                    if (!suf[j]) continue;
                    res = std::max(res, i ^ j);
                    if (res == U) return U;
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({2, 6,7});
    Solution().maxValue(nums, 1);
    return 0;
}
#endif
