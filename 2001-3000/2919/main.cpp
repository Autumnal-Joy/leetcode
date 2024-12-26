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
    long long minIncrementOperations(const vector<int> &nums, const int k) {
        const auto n = static_cast<int>(nums.size());
        auto dp = vector(4, vector(3, 0x3f3f3f3f3f3f3f3fll));
        for (int i = 0; i < 3; ++i) {
            dp[i][0] = std::max(0, k - nums[i]);
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - j][0];
            }
        }
        for (int i = 3; i < n; ++i) {
            const auto mi = i % 4, mi3 = (i + 3) % 4, mi2 = (i + 2) % 4, mi1 = (i + 1) % 4;
            dp[mi][0] = std::min(dp[mi3][0], std::min(dp[mi3][1], std::min(dp[mi3][2], std::min(dp[mi2][0], std::min(dp[mi2][1], dp[mi1][0]))))) + std::max(0, k - nums[i]);
            dp[mi][1] = dp[mi3][0];
            dp[mi][2] = dp[mi3][1];
        }
        return ranges::min(dp[(n - 1) % 4]);
    }
};

#ifdef LEETCODE
int main() {
    const auto nums = vector({2, 3, 0, 0, 2});
    cout << Solution().minIncrementOperations(nums, 4) << endl;
    return 0;
}
#endif
