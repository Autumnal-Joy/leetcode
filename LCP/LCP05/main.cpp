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
    ofs << '[';
    ranges::copy(data, ostream_iterator<int>(ofs, ","));
    ofs << ']';
}
void write(const vector<vector<int>> &data, const string &filename) {
    auto ofs = ofstream(filename);
    ofs << '[';
    for (const auto &line: data) {
        ofs << '[';
        ranges::copy(line, ostream_iterator<int>(ofs, ","));
        ofs << ']';
    }
    ofs << ']';
}
#endif

long long M = 1e9 + 7;

namespace Structure {
    class RangeBit {
        int n;
        vector<long long> tree1;
        vector<long long> tree2;

        static int lowbit(const int x) { return x & -x; }

    public:
        explicit RangeBit(const int n) : n(n), tree1(n + 1), tree2(n + 1) {}
        void add(const int i, const int j, const int delta) {
            for (auto k = i; k <= n; k += lowbit(k)) {
                tree1[k] += delta;
                tree1[k] %= M;
                tree2[k] += i * delta;
                tree2[k] %= M;
            }
            for (auto k = j + 1; k <= n; k += lowbit(k)) {
                tree1[k] -= delta;
                tree1[k] %= M;
                tree2[k] -= (j + 1) * delta;
                tree2[k] %= M;
            }
        }
        void add(const int k, const int delta) {
            add(k, k, delta);
        }
        [[nodiscard]] long long sum(const int j) const {
            long long sum1 = 0, sum2 = 0;
            for (auto i = j; i; i -= lowbit(i)) {
                sum1 += tree1[i];
                sum1 %= M;
            }
            for (auto i = j; i; i -= lowbit(i)) {
                sum2 += tree2[i];
                sum2 %= M;
            }
            return ((j + 1) * sum1 % M + M - sum2) % M;
        }
        [[nodiscard]] long long sum(const int i, const int j) const {
            return (sum(j) - sum(i - 1) + M) % M;
        }
    };
}// namespace Structure

class Solution {
public:
    vector<int> bonus(const int n, const vector<vector<int>> &leadership, const vector<vector<int>> &operations) {
        auto children = vector<vector<int>>(n + 1);
        for (const auto &ls: leadership) {
            children[ls[0]].push_back(ls[1]);
        }
        auto begin = vector<int>(n + 1), end = vector<int>(n + 1);
        auto idx = 1;
        function<void(int)> dfs = [&](const int i) {
            begin[i] = idx++;
            for (const auto child: children[i]) {
                dfs(child);
            }
            end[i] = idx;
        };
        dfs(1);
        auto res = vector<int>();
        auto bit = Structure::RangeBit(n);
        for (const auto &op: operations) {
            if (op[0] == 1) {
                bit.add(begin[op[1]], op[2]);
            } else if (op[0] == 2) {
                bit.add(begin[op[1]], end[op[1]] - 1, op[2]);
            } else {
                res.push_back(bit.sum(begin[op[1]], end[op[1]] - 1));
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    // constexpr auto n = 41039;
    // const auto leadership = read("../LCP/LCP05/leadership.txt");
    // const auto operations = read("../LCP/LCP05/operations.txt");
    constexpr auto n = 41039;
    const auto leadership = read("../LCP/LCP05/leadership.txt");
    const auto operations = read("../LCP/LCP05/operations.txt");
    const auto res = Solution().bonus(n, leadership, operations);
    write(res, "../LCP/LCP05/output.txt");
    return 0;
}
#endif
