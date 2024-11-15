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

template<typename... Args>
class HashTuple {
public:
    size_t operator()(const std::tuple<Args...> &tpl) const {
        return std::apply([](const auto &...args) {
            auto hasher = []<typename T>(const T &value) {
                return hash<decay_t<T>>()(value);
            };
            size_t seed = 0;
            return (..., (seed ^= hasher(args) + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
        },
                          tpl);
    }
};

class Solution {
public:
    bool robot(const string &command, vector<vector<int>> &obstacles, int x, int y) {
        auto path = unordered_set<tuple<int, int>, HashTuple<int, int>>();
        auto circle = make_tuple(0, 0);
        for (const auto &ch: command) {
            path.insert(circle);
            if (ch == 'U') {
                ++std::get<1>(circle);
            } else {
                ++std::get<0>(circle);
            }
        }
        for (const auto &obstacle: obstacles) {
            if (obstacle[0] > x || obstacle[1] > y) {
                continue;
            }
            const auto k = std::min({obstacle[0] / std::get<0>(circle), obstacle[1] / std::get<1>(circle)});
            if (const auto p = make_tuple(obstacle[0] - k * std::get<0>(circle), obstacle[1] - k * std::get<1>(circle));
                path.contains(p)) {
                return false;
            }
        }
        const auto k = std::min({x / std::get<0>(circle), y / std::get<1>(circle)});
        if (const auto p = make_tuple(x - k * std::get<0>(circle), y - k * std::get<1>(circle));
            path.contains(p)) {
            return true;
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
