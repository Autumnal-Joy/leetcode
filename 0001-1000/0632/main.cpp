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
public:
    vector<int> smallestRange(const vector<vector<int>> &nums) {
        const auto n = static_cast<int>(nums.size());
        // (val, idx)
        auto list = vector<pair<int, int>>();
        auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i][0], i);
        }
        auto index = vector(n, 1);
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            list.emplace_back(val, idx);
            if (index[idx] < nums[idx].size()) {
                pq.emplace(nums[idx][index[idx]++], idx);
            }
        }
        auto res = vector({-100000, 100000});
        auto counter = vector(n, 0);
        auto cnt = 0;
        auto left = 0, right = 0;
        while (right < list.size()) {
            const auto [max, idx] = list[right];
            if (++counter[idx] == 1) {
                ++cnt;
            }
            ++right;
            while (cnt == n) {
                const auto [min, idx] = list[left];
                if (max - min < res[1] - res[0]) {
                    res[0] = min;
                    res[1] = max;
                }
                if (--counter[idx] == 0) {
                    --cnt;
                }
                ++left;
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto nums = vector<vector<int>>({
            {4, 10, 15, 24, 26},
            {0, 9, 12, 20},
            {5, 18, 22, 30},
    });
    Solution().smallestRange(nums);
    return 0;
}
#endif