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
#endif

class Solution {
    // 匹配 u，如果找到则返回 true
    bool dfs(const int u,
             unordered_map<int, unordered_set<int>> &adj,
             unordered_map<int, bool> &visited,
             unordered_map<int, int> &match) {
        for (int v: adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            if (!match.contains(v) ||
                dfs(match[v], adj, visited, match)) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int hungarian(const unordered_set<int> &s1,
                  unordered_map<int, unordered_set<int>> &adj) {
        int res = 0;
        auto match = unordered_map<int, int>();
        for (const int u: s1) {
            if (auto visited = unordered_map<int, bool>();
                dfs(u, adj, visited, match)) {
                ++res;
            }
        }
        return res;
    }

public:
    int domino(const int n, const int m, const vector<vector<int>> &broken) {
        auto loc = [&](const int x, const int y) {
            return x * m + y;
        };
        auto del = unordered_set<int>();
        for (const auto &coord: broken) {
            del.insert(loc(coord[0], coord[1]));
        }
        auto adj = unordered_map<int, unordered_set<int>>();
        auto s1 = unordered_set<int>(), s2 = unordered_set<int>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (del.contains(loc(i, j))) continue;
                if (i + j & 1) {
                    s1.insert(loc(i, j));
                } else {
                    s2.insert(loc(i, j));
                }
                if (i - 1 >= 0 && !del.contains(loc(i - 1, j))) {
                    adj[loc(i, j)].insert(loc(i - 1, j));
                }
                if (i + 1 < n && !del.contains(loc(i + 1, j))) {
                    adj[loc(i, j)].insert(loc(i + 1, j));
                }
                if (j - 1 >= 0 && !del.contains(loc(i, j - 1))) {
                    adj[loc(i, j)].insert(loc(i, j - 1));
                }
                if (j + 1 < m && !del.contains(loc(i, j + 1))) {
                    adj[loc(i, j)].insert(loc(i, j + 1));
                }
            }
        }
        return hungarian(s1, adj);
    }
};

#ifdef LEETCODE
int main() {
    const auto broken = vector<vector<int>>({
            {1, 1},
            {2, 2},
    });
    Solution().domino(4, 4, broken);
    return 0;
}
#endif
