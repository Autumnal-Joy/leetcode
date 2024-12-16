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
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        arr1.insert(arr1.begin(), -0x3f3f3f3f);
        arr1.push_back(0x3f3f3f3f);
        ranges::sort(arr2);
        arr2.erase(ranges::unique(arr2).begin(), arr2.end());
        arr2.push_back(0x3f3f3f3f);
        const auto n = static_cast<int>(arr1.size());

        auto dp = vector(n, -0x3f3f3f3f);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            const auto k = ranges::lower_bound(arr2, arr1[i]) - arr2.begin();
            for (int j = 0; j < i; ++j) {
                if (arr1[i] <= arr1[j]) continue;
                if (k - i + j + 1 < 0 || arr2[k - i + j + 1] <= arr1[j]) continue;
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1] > 0 ? n - dp[n - 1] : -1;
    }
};

#ifdef LEETCODE
int main() {
    auto arr1 = vector({1, 5, 3, 6, 7});
    auto arr2 = vector({1, 3, 2, 4});
    Solution().makeArrayIncreasing(arr1, arr2);
    return 0;
}
#endif
