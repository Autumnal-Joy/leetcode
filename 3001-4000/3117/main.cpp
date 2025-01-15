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
    int minimumValueSum(const vector<int> &nums, const vector<int> &andValues) {
        const auto n = static_cast<int>(nums.size());
        const auto m = static_cast<int>(andValues.size());

        auto memo = unordered_map<long long, int>();
        auto state = [](const int i, const int j, const int v) {
            return (static_cast<long long>(i) << 48) | (static_cast<long long>(j) << 32) | v;
        };
        function<int(int, int, int)> dfs = [&](const int i, const int j, int andVal) {
            if (i == n) return j == m ? 0 : 0x3f3f3f3f;
            if (j == m) return i == n ? 0 : 0x3f3f3f3f;
            andVal &= nums[i];
            const auto s1 = state(i, j, andVal);
            if (!memo.contains(s1)) {
                auto res = dfs(i + 1, j, andVal);
                if (andVal == andValues[j]) {
                    res = std::min(res, dfs(i + 1, j + 1, -1) + nums[i]);
                }
                memo[s1] = res;
            }
            return memo[s1];
        };

        const auto res = dfs(0, 0, -1);
        return res < 0x3f3f3f3f ? res : -1;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({1, 3, 2, 4, 7, 5, 3});
    auto andValues = vector({0, 5, 3});
    Solution().minimumValueSum(nums, andValues);
    return 0;
}
#endif
