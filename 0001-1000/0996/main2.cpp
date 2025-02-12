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

template<typename T, size_t N>
auto Array() {
    return array<T, N>({});
}
template<typename T, size_t N1, size_t N2>
auto Array() {
    return array<array<T, N2>, N1>({});
}
template<typename T, size_t N1, size_t N2, size_t N3>
auto Array() {
    return array<array<array<T, N3>, N2>, N1>({});
}
#define MAX_I 0x3f3f3f3f
#define MIN_I (-MAX_I)
#define MAX_LL 0x3f3f3f3f3f3f3f3f
#define MIN_LL (-MAX_LL)

class Solution {
    bool isSquare(const int n) {
        const auto root = static_cast<int>(std::sqrt(n));
        return n == root * root;
    }

public:
    int res = 0;
    void back(vector<int> &nums, vector<int> &path, vector<bool> &vis) {
        if (path.size() == nums.size()) {
            res++;
            return;
        }
        auto us = unordered_set<int>();
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] || us.contains(nums[i])) continue;
            us.insert(nums[i]);
            if (!path.empty() && !isSquare(path.back() + nums[i])) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            back(nums, path, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
    int numSquarefulPerms(vector<int> &nums) {
        ranges::sort(nums);
        auto perm = vector<int>();
        auto vis = vector(nums.size(), false);
        back(nums, perm, vis);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector({2, 2, 2});
    cout << Solution().numSquarefulPerms(nums) << endl;
    return 0;
}
#endif
