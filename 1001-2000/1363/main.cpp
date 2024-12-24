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
    static char toChar(const int digit) {
        return static_cast<char>('0' + digit);
    }
    static bool less(const string &a, const string &b) {
        if (a[0] == '-') return true;
        if (b[0] == '-') return false;
        return a.size() == b.size() ? a < b : a.size() < b.size();
    }
    static string trim(const string &s) {
        if (s.empty()) return s;
        auto i = 0;
        while (i < s.size() && s[i] == '0') {
            ++i;
        }
        return i == s.size() ? "0" : s.substr(i);
    }

public:
    string largestMultipleOfThree(const vector<int> &digits) {
        auto count = array<int, 10>({});
        auto module = array<int, 3>({});
        auto sum = 0;
        for (const auto &digit: digits) {
            ++count[digit];
            ++module[digit % 3];
            sum += digit;
        }
        auto res = string();
        const auto rem = sum % 3;
        if (rem) {
            if (module[rem] >= 1) {
                for (int i = rem, step = 1; i <= 9 && step; i += 3) {
                    while (count[i] && step) {
                        --count[i];
                        --step;
                    }
                }
            } else if (module[3 - rem] >= 2) {
                for (int i = 3 - rem, step = 2; i <= 9 && step; i += 3) {
                    while (count[i] && step) {
                        --count[i];
                        --step;
                    }
                }
            }
        }
        if (ranges::all_of(count, [](const int val) { return val == 0; })) {
            return "";
        }
        for (int i = 9; i >= 1; --i) {
            res += string(count[i], toChar(i));
        }
        if (res.empty()) return "0";
        return res + string(count[0], toChar(0));
    }
};

#ifdef LEETCODE
int main() {
    auto digit = vector({8, 7, 6, 1, 0});
    Solution().largestMultipleOfThree(digit);
    return 0;
}
#endif
