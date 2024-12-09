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

template<std::predicate<const int> Pred>
static int last(int left, int right, Pred pred) {
    while (left + 1 < right) {
        const int mid = left + (right - left) / 2;
        if (pred(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

class Solution {
    int res = 0x3f3f3f3f;

    int solve(const vector<int> &strength, const int K) {
        int res = 0;
        int X = 1;
        for (const auto &val: strength) {
            res += (val - 1) / X + 1;
            X += K;
        }
        return res;
    }


public:
    void dfs(int begin, vector<int> &strength, const int K) {
        if (begin == strength.size()) {
            res = std::min(res, solve(strength, K));
            return;
        }
        for (int i = begin; i < strength.size(); ++i) {
            swap(strength[begin], strength[i]);
            dfs(begin + 1, strength, K);
            swap(strength[begin], strength[i]);
        }
    }
    int findMinimumTime(vector<int> &strength, int K) {
        dfs(0, strength, K);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    // auto strength = vector<int>{3, 6, 7, 18, 22, 50};
    auto strength = vector<int>{3, 4, 1};
    Solution().findMinimumTime(strength, 1);
    return 0;
}
#endif
