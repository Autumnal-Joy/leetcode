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
#endif

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    explicit Node(const int key, const int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int, Node *> mp;

    static void remove(const Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    static void insertAfter(Node *node, Node *location) {
        node->next = location->next;
        node->prev = location;
        location->next->prev = node;
        location->next = node;
    }

public:
    explicit LRUCache(const int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(const int key) {
        if (mp.contains(key)) {
            const auto node = mp[key];
            remove(node);
            insertAfter(node, head);
            return node->val;
        }
        return -1;
    }

    void put(const int key, const int value) {
        if (mp.contains(key)) {
            const auto node = mp[key];
            node->val = value;
            remove(node);
            insertAfter(node, head);
        } else {
            if (mp.size() == capacity) {
                const auto node = tail->prev;
                remove(node);
                mp.erase(node->key);
                delete node;
            }
            auto *node = new Node(key, value);
            mp[key] = node;
            insertAfter(node, head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef LEETCODE
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
int main() {

    return 0;
}
#endif
