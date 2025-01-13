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

class Solution {
    const long long MOD = 1e9 + 7;

public:
    int beautifulPartitions(const string &s, int k, int minLength) {
        const auto n = static_cast<int>(s.size());
        const auto isPrime = [](const char ch) {
            return ch == '2' || ch == '3' || ch == '5' || ch == '7';
        };
        const auto isSplit = [&](const int i) {
            return i == 0 || i == n || !isPrime(s[i - 1]) && isPrime(s[i]);
        };
        if (!isPrime(s[0]) || isPrime(s[n - 1])) return 0;

        auto dp = vector(k + 1, vector(n + 1, 0ll));
        dp[0][0] = 1;
        for (int i = 1; i <= k; ++i) {
            auto sum = 0ll;
            for (int j = i * minLength; j <= n - (k - i) * minLength; ++j) {
                if (isSplit(j - minLength)) {
                    sum += dp[i - 1][j - minLength];
                }
                if (isSplit(j)) {
                    dp[i][j] = sum % MOD;
                }
            }
        }
        return static_cast<int>(dp[k][n]);
    }
};

#ifdef LEETCODE
int main() {
    const auto s = string("23542185133");
    Solution().beautifulPartitions(s, 1, 1);
    return 0;
}
#endif
