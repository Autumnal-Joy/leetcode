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

template<typename Pred>
int first(int left, int right, Pred pred) {
    while (left + 1 != right) {
        const auto mid = left + (right - left) / 2;
        if (pred(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}
template<typename Pred>
int last(int left, int right, Pred pred) {
    while (left + 1 != right) {
        const auto mid = left + (right - left) / 2;
        if (pred(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        ranges::sort(nums);
        auto n = 0;
        auto cnt = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[n]) {
                nums[++n] = nums[i];
            }
            ++cnt[n];
        }
        nums.resize(n + 1);
        cnt.resize(n + 1);
        auto dp = vector(n + 1, vector(2, 0));
        dp[0][1] = nums[0] * cnt[0];
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = std::max({dp[i - 1][0], dp[i - 1][1]});
            if (nums[i] == nums[i - 1] + 1) {
                dp[i][1] = dp[i - 1][0] + nums[i] * cnt[i];
            } else {
                dp[i][1] = dp[i][0] + nums[i] * cnt[i];
            }
        }
        return std::max({dp[n][0], dp[n][1]});
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({3, 1});
    Solution().deleteAndEarn(nums);
    return 0;
}
#endif
