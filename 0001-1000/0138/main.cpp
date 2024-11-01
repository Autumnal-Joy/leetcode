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

class Node {
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(const int val = 0) : val(val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        auto temp = head;
        auto mp = unordered_map<Node *, Node *>();
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

#ifdef LEETCODE
int main() {
    const auto v = vector<vector<int>>({
            {7, -1},
            {13, 0},
            {11, 4},
            {10, 2},
            {1, 0},
    });
    auto nodes = vector<Node>(v.size());
    for (int i = 0; i < v.size(); ++i) {
        nodes[i].val = v[i][0];
        if (i + 1 < v.size()) {
            nodes[i].next = &nodes[i + 1];
        }
        if (v[i][1] != -1) {
            nodes[i].random = &nodes[v[i][1]];
        }
    }
    auto res = Solution().copyRandomList(&nodes[0]);
    return 0;
}
#endif
