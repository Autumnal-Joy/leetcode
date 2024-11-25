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

class Solution {
public:
    int networkDelayTime(const vector<vector<int>> &times, const int n, const int k) {
        auto weights = unordered_map<int, unordered_map<int, int>>();
        for (const auto &time: times) {
            weights[time[0] - 1][time[1] - 1] = time[2];
        }
        auto dist = vector(n, -1);
        dist[k - 1] = 0;
        auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
        pq.emplace(0, k - 1);
        auto visited = vector(n, false);
        while (!pq.empty()) {
            auto [d1, u] = pq.top();
            pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            for (const auto &[v, d2]: weights[u]) {
                if (dist[v] == -1 || d1 + d2 < dist[v]) {
                    dist[v] = d1 + d2;
                    pq.emplace(dist[v], v);
                }
            }
        }
        auto res = 0;
        for (int i = 0; i < n; ++i) {
            if (i == k - 1) continue;
            if (dist[i] == -1) return -1;
            res = std::max({res, dist[i]});
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto times = vector<vector<int>>({{2, 1, 1}, {2, 3, 1}, {3, 4, 1}});
    Solution().networkDelayTime(times, 4, 2);
    return 0;
}
#endif
