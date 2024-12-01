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
    queue<TreeNode *> q;
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        TreeNode *node = q.front();
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
#endif

char nextCh(char ch) {
    if (ch == 'z') return 'a';
    return ch + 1;
}

char prevCh(char ch) {
    if (ch == 'a') return 'z';
    return ch - 1;
}

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int> &nextCost, vector<int> &previousCost) {
        auto preCostSum = vector(26, 0ll);
        auto nextCostSum = vector(26, 0ll);
        for (int i = 0; i < 26; ++i) {
            preCostSum[i] = previousCost[i] + (i - 1 >= 0 ? preCostSum[i - 1] : 0ll);
        }
        for (int i = 0; i < 26; ++i) {
            nextCostSum[i] = nextCost[i] + (i - 1 >= 0 ? nextCostSum[i - 1] : 0ll);
        }
        long long res = 0ll;
        for (int i = 0; i < t.size(); ++i) {
            if (s[i] == t[i]) {
                continue;
            }
            long long costPre, costNext;
            if (s[i] < t[i]) {
                costPre = preCostSum[s[i] - 'a'] + (preCostSum['z' - 'a'] - preCostSum[t[i] - 'a']);
                costNext = nextCostSum[t[i] - 1 - 'a'] - (s[i] - 'a' - 1 >= 0 ? nextCostSum[s[i] - 'a' - 1] : 0);
            } else {
                costPre = preCostSum[s[i] - 'a'] - preCostSum[t[i] - 'a'];
                costNext = nextCostSum['z' - 'a'] - nextCostSum[s[i] - 'a' - 1] + (t[i] - 1 - 'a' >= 0 ? nextCostSum[t[i] - 1 - 'a'] : 0);
            }
            res += min(costPre, costNext);
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
