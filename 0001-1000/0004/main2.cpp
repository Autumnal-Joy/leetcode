#ifdef LEETCODE
#define DEBUG
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
    while (left + 1 < right) {
        auto mid = left + (right - left) / 2;
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
    while (left + 1 < right) {
        auto mid = left + (right - left) / 2;
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) std::swap(nums1, nums2);
        nums1.insert(nums1.begin(), -1e6);
        nums1.insert(nums1.end(), 1e6);
        nums2.insert(nums2.begin(), -1e6);
        nums2.insert(nums2.end(), 1e6);
        const auto n1 = static_cast<int>(nums1.size());
        const auto n2 = static_cast<int>(nums2.size());
        const auto n = n1 + n2;
        int i = 1, j = (n - 1) / 2;
        while (true) {
            const auto max1 = std::max({nums1[i - 1], nums2[j - 1]});
            const auto min2 = std::min({nums1[i], nums2[j]});
            if (max1 <= min2) {
                return n & 1 ? max1 : (max1 + min2) / 2.0;
            }
            ++i, --j;
        }
    }
};

#ifdef LEETCODE
int main() {
    auto nums1 = vector{1, 2, 8, 9, 10, 11, 12, 13, 14, 15};
    auto nums2 = vector{3, 4, 5, 6, 7};
    Solution().findMedianSortedArrays(nums1, nums2);
    return 0;
}
#endif
