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
    vector<int> rank;

public:
    explicit UnionFind(const int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(const int val) {
        if (val != parent[val]) {
            parent[val] = find(parent[val]);
        }
        return parent[val];
    }
    void unite(const int x, const int y) {
        const auto p1 = find(x);
        const auto p2 = find(y);
        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
            ++rank[p2];
        }
    }
    void separate(int x) {
        parent[x] = x;
    }
};

class Solution {
    static bool intersect(const double xCorner, const double yCorner,
                          const double x1, const double y1, const double r1,
                          const double x2, const double y2, const double r2) {
        const double x = (x1 * r2 + x2 * r1) / (r1 + r2);
        const double y = (y1 * r2 + y2 * r1) / (r1 + r2);
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2) &&
               x > 0 && x < xCorner && y > 0 && y < yCorner;
    }
    static bool inCircle(const long long x1, const long long y1, const long long r1,
                         const long long x2, const long long y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1 * r1;
    }

public:
    bool canReachCorner(const int xCorner, const int yCorner, const vector<vector<int>> &circles) {
        const auto n = static_cast<int>(circles.size());
        auto uf = UnionFind(n + 2);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (intersect(xCorner, yCorner,
                              circles[i][0], circles[i][1], circles[i][2],
                              circles[j][0], circles[j][1], circles[j][2])) {
                    uf.unite(i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            const long long x = circles[i][0];
            const long long y = circles[i][1];
            const long long r = circles[i][2];
            if (std::abs(x) <= r && y >= 0 && y <= yCorner) uf.unite(i, n);
            if (std::abs(y - yCorner) <= r && x >= 0 && x <= xCorner) uf.unite(i, n);
            if (inCircle(x, y, r, 0, 0)) uf.unite(i, n);
            if (inCircle(x, y, r, 0, yCorner)) uf.unite(i, n);
            if (inCircle(x, y, r, xCorner, yCorner)) uf.unite(i, n);
            if (std::abs(y) <= r && x >= 0 && x <= xCorner) uf.unite(i, n + 1);
            if (std::abs(x - xCorner) <= r && y >= 0 && y <= yCorner) uf.unite(i, n + 1);
            if (inCircle(x, y, r, 0, 0)) uf.unite(i, n + 1);
            if (inCircle(x, y, r, xCorner, 0)) uf.unite(i, n + 1);
            if (inCircle(x, y, r, xCorner, yCorner)) uf.unite(i, n + 1);
        }
        return uf.find(n) != uf.find(n + 1);
    }
};

#ifdef LEETCODE
int main() {
    auto xCorner = 8;
    auto yCorner = 8;
    auto circles = vector<vector<int>>({
            {1, 4, 1},
            {3, 4, 1},
            {5, 4, 1},
            {7, 4, 1},
    });
    cout << Solution().canReachCorner(xCorner, yCorner, circles) << endl;
    return 0;
}
#endif
