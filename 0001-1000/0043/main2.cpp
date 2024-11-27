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
    static vector<uint8_t> decode(const string &num) {
        const auto n = static_cast<int>(num.size());
        auto res = vector<uint8_t>(n);
        for (int i = 0; i < n; ++i) {
            res[i] = num[n - i - 1] - '0';
        }
        return res;
    }
    static string encode(const vector<uint8_t> &num) {
        const auto n = static_cast<int>(num.size());
        auto res = string(n, '\0');
        for (int i = 0; i < n; ++i) {
            res[i] = num[n - i - 1] + '0';
        }
        return res;
    }
    void add(vector<uint8_t> &num1, const vector<uint8_t> &num2, const int offset2) {
        const auto m = static_cast<int>(num1.size());
        const auto n = static_cast<int>(num2.size());
        auto res = vector<uint8_t>();
        res.reserve(1 + std::max({m, n + offset2}));
        auto carry = 0;
        for (int i = 0, j = -offset2; i < m || j < n || carry; ++i, ++j) {
            if (0 <= i && i < m) carry += num1[i];
            if (0 <= j && j < n) carry += num2[j];
            res.push_back(carry % 10);
            carry /= 10;
        }
        num1 = std::move(res);
    }
    vector<uint8_t> multiply(const vector<uint8_t> &num1, const int k) {
        const auto m = static_cast<int>(num1.size());
        auto res = vector<uint8_t>();
        res.reserve(1 + m);
        auto carry = 0;
        for (int i = 0; i < m || carry; ++i) {
            if (i < m) carry += num1[i] * k;
            res.push_back(carry % 10);
            carry /= 10;
        }
        return res;
    }

public:
    string multiply(const string &num1, const string &num2) {
        if (num1 == "0" || num2 == "0") return "0";
        const auto n1 = decode(num1);
        const auto n2 = decode(num2);
        auto res = vector<uint8_t>();
        for (int i = 0; i < num1.size(); ++i) {
            const auto product = multiply(n2, n1[i]);
            add(res, product, i);
        }
        return encode(res);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
