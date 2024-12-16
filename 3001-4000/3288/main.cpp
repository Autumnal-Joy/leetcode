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
    static bool lower(const vector<int> &c1, const vector<int> &c2) {
        return c1[0] < c2[0] && c1[1] < c2[1];
    }
    template<typename Comp>
    int LIS(vector<vector<int>> &coordinates, Comp comp) {
        const auto n = static_cast<int>(coordinates.size());
        auto dp = vector<int>();
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), coordinates[i][1], comp);
            if (it == dp.end()) {
                dp.push_back(coordinates[i][1]);
            } else {
                *it = coordinates[i][1];
            }
        }
        return static_cast<int>(dp.size());
    }

public:
    int maxPathLength(const vector<vector<int>> &coordinates, const int k) {
        auto arr1 = vector<vector<int>>(), arr2 = vector<vector<int>>();
        for (int i = 0; i < coordinates.size(); ++i) {
            if (i == k) continue;
            if (lower(coordinates[i], coordinates[k])) {
                arr1.push_back(coordinates[i]);
            } else if (lower(coordinates[k], coordinates[i])) {
                arr2.push_back(coordinates[i]);
            }
        }
        arr1.push_back(coordinates[k]);
        arr2.push_back(coordinates[k]);
        ranges::sort(arr1, [&](const auto &l, const auto &r) {
            if (l[0] == r[0]) return l[1] > r[1];
            return l[0] < r[0];
        });
        ranges::sort(arr2, [&](const auto &l, const auto &r) {
            if (l[0] == r[0]) return l[1] < r[1];
            return l[0] > r[0];
        });
        return LIS(arr1, [&](const auto &l, const auto &r) { return l < r; }) +
               LIS(arr2, [&](const auto &l, const auto &r) { return l > r; }) - 1;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
