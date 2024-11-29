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

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    explicit Node(const int x) : val(x), next(nullptr) {}
    Node(const int x, Node *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
    int maximumCostSubstring(const string &s, const string &chars, const vector<int> &vals) {
        auto value = unordered_map<char, int>();
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            value[ch] = ch - 'a' + 1;
        }
        for (int i = 0; i < chars.size(); ++i) {
            value[chars[i]] = vals[i];
        }
        auto dp = value[s[0]];
        auto res = std::max({dp, 0});
        for (int i = 1; i < s.size(); ++i) {
            dp = (dp > 0 ? dp : 0) + value[s[i]];
            res = std::max({res, dp});
        }
        return res;
    }
};


#ifdef LEETCODE
int main() {
}

#endif
