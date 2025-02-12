#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

template<typename T, size_t N>
auto Array() {
    return array<T, N>({});
}
template<typename T, size_t N1, size_t N2>
auto Array() {
    return array<array<T, N2>, N1>({});
}
template<typename T, size_t N1, size_t N2, size_t N3>
auto Array() {
    return array<array<array<T, N3>, N2>, N1>({});
}
#define MAX_I 0x3f3f3f3f
#define MIN_I (-MAX_I)
#define MAX_LL 0x3f3f3f3f3f3f3f3f
#define MIN_LL (-MAX_LL)


int dijkstra(const int n, const vector<vector<pair<int, int>>> &graph) {
    auto dist = vector(n, MAX_I);
    dist[0] = 0;
    auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
    pq.emplace(0, 0);
    while (!pq.empty()) {
        const auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto &[v, w]: graph[u]) {
            const auto new_d = std::max(dist[u], w);
            if (dist[v] > new_d) {
                dist[v] = new_d;
                pq.emplace(new_d, v);
            }
        }
    }
    return ranges::max(dist);
}

class Solution {
public:
    int minMaxWeight(const int n, const vector<vector<int>> &edges, int threshold) {
        auto graph = vector(n, vector<pair<int, int>>());
        for (const auto &edge: edges) {
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        const auto res = dijkstra(n, graph);
        return res == MAX_I ? -1 : res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
