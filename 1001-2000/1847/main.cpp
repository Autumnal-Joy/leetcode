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

class SegmentTree {
    vector<int> tree;
    int n;

    void update(const int o, const int l, const int r, const int idx, const int val) {
        if (l == r) {
            tree[o] = val;
        } else {
            const auto mid = l + (r - l) / 2;
            if (idx <= mid) {
                update(o * 2, l, mid, idx, val);
            } else {
                update(o * 2 + 1, mid + 1, r, idx, val);
            }
            tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
        }
    }
    int query(const int o, const int l, const int r, const int L, const int R) {
        if (R < l || r < L) {
            return 0;
        }
        if (L <= l && r <= R) {
            return tree[o];
        }
        const auto mid = l + (r - l) / 2;
        return std::max(query(o * 2, l, mid, L, R),
                        query(o * 2 + 1, mid + 1, r, L, R));
    }

public:
    explicit SegmentTree(const int n) : tree(4 * n), n(n) {}
    void update(const int idx, const int val) {
        update(1, 0, n - 1, idx, val);
    }
    int query(const int L, const int R) {
        return query(1, 0, n - 1, L, R);
    }
};

template<typename Pred>
int first(int l, int r, Pred pred) {
    while (l + 1 < r) {
        const auto m = l + (r - l) / 2;
        if (pred(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}
template<typename Pred>
int last(int l, int r, Pred pred) {
    while (l + 1 < r) {
        const auto m = l + (r - l) / 2;
        if (pred(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

constexpr int LB = 0, RB = 1e7 + 1;

class Solution {

public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        ranges::sort(rooms, [&](const auto &l, const auto &r) {
            return l[1] < r[1];
        });
        const auto q = static_cast<int>(queries.size());
        auto id = vector<int>(q);
        std::iota(id.begin(), id.end(), 0);
        ranges::sort(id, [&](const auto &l, const auto &r) {
            return queries[l][1] > queries[r][1];
        });
        auto res = vector<int>(q);
        auto rooms_id = set<int>();
        for (int i = 0; i < q; ++i) {
            const auto sz = queries[id[i]][1];
            while (!rooms.empty() && rooms.back()[1] >= sz) {
                rooms_id.insert(rooms.back()[0]);
                rooms.pop_back();
            }
            const auto target = queries[id[i]][0];
            if (rooms_id.empty()) {
                res[id[i]] = -1;
            } else {
                const auto it1 = rooms_id.lower_bound(target);
                const auto it2 = rooms_id.upper_bound(target);
                if (it2 == rooms_id.begin()) {
                    res[id[i]] = *it1;
                } else if (it1 == rooms_id.end()) {
                    res[id[i]] = *std::prev(it2);
                } else {
                    if (target - *std::prev(it2) <= *it1 - target) {
                        res[id[i]] = *std::prev(it2);
                    } else {
                        res[id[i]] = *it1;
                    }
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto rooms = vector<vector<int>>({{15, 19}, {11, 10}, {12, 1}, {17, 6}, {1, 6}, {10, 21}, {13, 7}, {14, 25}, {19, 3}, {9, 11}});
    auto queries = vector<vector<int>>({{14, 14}, {20, 17}, {6, 8}, {1, 6}, {21, 4}, {4, 16}, {3, 22}, {2, 21}, {24, 6}, {6, 1}});
    Solution().closestRoom(rooms, queries);
    return 0;
}
#endif
