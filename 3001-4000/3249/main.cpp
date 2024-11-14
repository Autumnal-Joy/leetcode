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
#endif

class Solution {
    int res{};
    int dfs(vector<vector<int>> &graph, const int node, const int from) {
        const auto &children = graph[node];
        auto child_cnt = vector<int>();
        for (auto &child: children) {
            if (child == from) continue;
            child_cnt.push_back(dfs(graph, child, node));
        }
        if (child_cnt.size() < 2 || ranges::all_of(child_cnt, [&](const int cnt) {
                return cnt == child_cnt[0];
            })) {
            ++res;
        }
        return std::reduce(child_cnt.begin(), child_cnt.end(), 0) + 1;
    }

public:
    int countGoodNodes(const vector<vector<int>> &edges) {
        const auto n = static_cast<int>(edges.size());
        auto graph = vector<vector<int>>(n + 1);
        for (const auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(graph, 0, -1);
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
