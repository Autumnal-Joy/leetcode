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

class MyCalendar {
    list<pair<int, int>> events;

public:
    MyCalendar() = default;
    bool book(const int startTime, const int endTime) {
        auto it = events.begin();
        while (it != events.end() && startTime >= it->second) {
            it = std::next(it);
        }
        if (it != events.end() && endTime > it->first) return false;
        events.insert(it, {startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */

#ifdef LEETCODE
int main() {
    const auto data = vector<vector<int>>({
            {},
            {47, 50},
            {33, 41},
            {39, 45},
            {33, 42},
            {25, 32},
            {26, 35},
            {19, 25},
            {3, 8},
            {8, 13},
            {18, 27},
    });
    auto *obj = new MyCalendar();
    for (int i = 1; i < data.size(); ++i) {
        obj->book(data[i][0], data[i][1]);
    }
    delete obj;
    return 0;
}
#endif
