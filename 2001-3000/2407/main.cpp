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

class SegmentTree {
    vector<int> tree;
    int n;

    void update(const int o, const int l, const int r, const int idx, const int val) {
        if (l == r) {
            tree[o] = val;
        } else {
            const auto mid = l + (r - l) / 2;
            if (idx <= mid) {
                update(o * 2, l, mid, idx, val);
            } else {
                update(o * 2 + 1, mid + 1, r, idx, val);
            }
            tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
        }
    }

    int query(const int o, const int l, const int r, const int L, const int R) {
        if (L <= l && r <= R) return tree[o];
        const auto mid = l + (r - l) / 2;
        if (R <= mid) {
            return query(o * 2, l, mid, L, R);
        }
        if (L > mid) {
            return query(o * 2 + 1, mid + 1, r, L, R);
        }
        return std::max(query(o * 2, l, mid, L, R), query(o * 2 + 1, mid + 1, r, L, R));
    }

public:
    explicit SegmentTree(const int size) : tree(4 * size), n(size) {}
    void update(const int idx, const int val) {
        update(1, 0, n - 1, idx, val);
    }
    int query(const int L, const int R) {
        return query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums, int k) {
        const int n = static_cast<int>(nums.size());
        constexpr int N = 1e5 + 1;
        auto dp = vector<int>(N);
        auto st = SegmentTree(N);
        for (const auto &num: nums) {
            dp[num] = st.query(std::max(0, num - k), num - 1) + 1;
            st.update(num, dp[num]);
        }
        return st.query(0, N - 1);
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({4, 2, 1, 4, 3, 4, 5, 8, 15});
    Solution().lengthOfLIS(nums, 3);
    return 0;
}
#endif
