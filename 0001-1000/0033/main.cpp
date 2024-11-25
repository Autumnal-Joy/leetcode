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

class Solution {
    static int binarySearch(const vector<int> &nums, const int target, const int left, const int right) {
        auto it = std::lower_bound(nums.begin() + left,
                                   nums.begin() + right + 1,
                                   target);
        if (it == nums.end() || *it != target) return -1;
        return static_cast<int>(std::distance(nums.begin(), it));
    }
    int search(const vector<int> &nums, const int target, const int left, const int right) {
        if (left == right) {
            return nums[left] == target ? left : -1;
        }
        int loc;
        if (nums[left] < nums[right]) {
            loc = binarySearch(nums, target, left, right);
        } else {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                loc = mid;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    loc = binarySearch(nums, target, left, mid - 1);
                } else {
                    loc = search(nums, target, mid + 1, right);
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    loc = binarySearch(nums, target, mid + 1, right);
                } else {
                    loc = search(nums, target, left, mid - 1);
                }
            }
        }
        return loc;
    }

public:
    int search(const vector<int> &nums, const int target) {
        const auto n = static_cast<int>(nums.size());
        return search(nums, target, 0, n - 1);
    }
};

#ifdef LEETCODE
int main() {
    const auto nums = vector({4, 5, 6, 7, 0, 1, 2});
    Solution().search(nums, 0);
    return 0;
}
#endif
