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

class UnionFind {
    vector<int> parent;

public:
    explicit UnionFind(const int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(const int val) {
        if (val != parent[val]) {
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }
    bool unite(const int x, const int y) {
        const auto p1 = find(x);
        const auto p2 = find(y);
        if (p1 != p2) {
            parent[p2] = p1;
            return true;
        }
        return false;
    }
    void separate(int x) {
        parent[x] = x;
    }
};

class Solution {
    static bool check(const string &a, const string &b) {
        return a.size() >= b.size() && string_view(a).substr(a.size() - b.size()) == b;
    }

public:
    int minimumLengthEncoding(vector<string> &words) {
        const auto n = static_cast<int>(words.size());
        auto uf = UnionFind(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || words[i].size() > words[j].size()) continue;
                if (uf.find(i) != uf.find(j) && check(words[j], words[i])) {
                    uf.unite(j, i);
                    break;
                }
            }
        }
        auto res = 0;
        for (int i = 0; i < n; ++i) {
            if (uf.find(i) == i) {
                res += static_cast<int>(words[i].size()) + 1;
            }
        }

        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto words = vector<string>({
            "time",
            "atime",
            "btime",
    });
    cout << Solution().minimumLengthEncoding(words) << endl;
    return 0;
}
#endif
