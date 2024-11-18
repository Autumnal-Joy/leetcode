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
    vector<int> shortestDistanceAfterQueries(const int n, const vector<vector<int>> &queries) {
        auto bridge = vector<unordered_set<int>>(n);
        auto bfs = [&]() {
            auto dq = deque({0});
            auto visited = vector(n, false);
            int step = 0;
            while (true) {
                auto cnt = dq.size();
                while (cnt--) {
                    const auto front = dq.front();
                    dq.pop_front();
                    if (front == n - 1) return step;
                    for (auto next: bridge[front]) {
                        if (!visited[next]) {
                            dq.push_back(next);
                            visited[next] = true;
                        }
                    }
                    if (!visited[front + 1]) {
                        dq.push_back(front + 1);
                        visited[front + 1] = true;
                    }
                }
                ++step;
            }
        };

        auto res = vector<int>(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            bridge[queries[i][0]].insert(queries[i][1]);
            res[i] = bfs();
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
