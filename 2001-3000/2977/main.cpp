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

class Solution {
public:
    long long minimumCost(const string &source, const string &target, const vector<string> &original, const vector<string> &changed, const vector<int> &cost) {
        const auto source_view = string_view(source);
        const auto target_view = string_view(target);
        const auto n = static_cast<int>(source_view.size());
        const auto m = static_cast<int>(original.size());
        auto s2id = unordered_map<string_view, int>();
        auto id = 0;
        for (int i = 0; i < m; ++i) {
            if (!s2id.contains(original[i])) {
                s2id[original[i]] = id++;
            }
            if (!s2id.contains(changed[i])) {
                s2id[changed[i]] = id++;
            }
        }
        auto dist = vector(id, vector(id, 0x3f3f3f3f3f3f3f3fll));
        for (int i = 0; i < id; ++i) {
            dist[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            dist[s2id[original[i]]][s2id[changed[i]]] = std::min(dist[s2id[original[i]]][s2id[changed[i]]], 0ll + cost[i]);
        }
        for (int k = 0; k < id; ++k) {
            for (int i = 0; i < id; ++i) {
                for (int j = 0; j < id; ++j) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        auto lens = unordered_set<int>();
        for (int i = 0; i < m; ++i) {
            lens.insert(static_cast<int>(original[i].size()));
        }
        auto dp = vector(n + 1, 0x3f3f3f3f3f3f3f3fll);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (source[j] != target[j]) break;
                dp[i] = std::min(dp[i], dp[j]);
            }
            for (const auto &len: lens) {
                if (i - len >= 0) {
                    const auto from = source_view.substr(i - len, len);
                    const auto to = target_view.substr(i - len, len);
                    const auto it1 = s2id.find(from);
                    const auto it2 = s2id.find(to);
                    auto d = 0x3f3f3f3f3f3f3f3fll;
                    if (it1 != s2id.end() && it2 != s2id.end()) {
                        d = dist[it1->second][it2->second];
                    }
                    dp[i] = std::min(dp[i], dp[i - len] + d);
                }
            }
        }
        return dp[n] < 0x3f3f3f3f3f3f3f3fll ? dp[n] : -1;
    }
};

#ifdef LEETCODE
int main() {
    const auto source = string("abcdefgh");
    const auto target = string("acdeeghh");
    const auto original = vector<string>({"bcd", "fgh", "thh"});
    const auto changed = vector<string>({"cde", "thh", "ghh"});
    const auto cost = vector({1, 3, 5});
    Solution().minimumCost(source, target, original, changed, cost);
    return 0;
}
#endif
