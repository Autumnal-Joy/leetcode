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
    int res = 0;
    int n = 8;

    bool block(const vector<int> &from1, const vector<int> &to1, const vector<int> &from2, const vector<int> &to2) {
        auto dx1 = to1[0] - from1[0], dy1 = to1[1] - from1[1],
             dx2 = to2[0] - from2[0], dy2 = to2[1] - from2[1];
        dx1 = dx1 == 0 ? 0 : dx1 / abs(dx1), dy1 = dy1 == 0 ? 0 : dy1 / abs(dy1);
        dx2 = dx2 == 0 ? 0 : dx2 / abs(dx2), dy2 = dy2 == 0 ? 0 : dy2 / abs(dy2);
        auto x1 = from1[0], y1 = from1[1],
             x2 = from2[0], y2 = from2[1];
        const auto x1_e = to1[0], y1_e = to1[1],
                   x2_e = to2[0], y2_e = to2[1];
        while (x1 != x1_e || y1 != y1_e || x2 != x2_e || y2 != y2_e) {
            if (x1 != x1_e || y1 != y1_e) {
                x1 += dx1, y1 += dy1;
            }
            if (x2 != x2_e || y2 != y2_e) {
                x2 += dx2, y2 += dy2;
            }
            if (x1 == x2 && y1 == y2) {
                return true;
            }
        }
        return false;
    }

    bool check(const vector<string> &pieces, const vector<vector<int>> &positions, const int depth, const vector<vector<int>> &locations) {
        for (int i = 0; i < depth; ++i) {
            if (block(positions[i], locations[i], positions[depth], locations[depth])) {
                return false;
            }
        }
        return true;
    }

    void dfs(const vector<string> &pieces, const vector<vector<int>> &positions, const int depth, vector<vector<int>> &locations) {
        if (depth == pieces.size()) {
            ++res;
            return;
        }
        const auto &pos = positions[depth];
        auto &loc = locations[depth];
        if (pieces[depth] == "rook") {
            for (int x = 1, y = pos[1]; x <= 8; ++x) {
                loc[0] = x, loc[1] = y;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
            for (int x = pos[0], y = 1; y <= 8; ++y) {
                if (y == pos[1]) continue;
                loc[0] = x, loc[1] = y;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
        } else if (pieces[depth] == "queen") {
            for (int x = 1, y = pos[1]; x <= 8; ++x) {
                loc[0] = x, loc[1] = y;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
            for (int x = pos[0], y = 1; y <= 8; ++y) {
                if (y == pos[1]) continue;
                loc[0] = x, loc[1] = y;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
            for (int dx = -7, dy = -7; dx <= 7; ++dx, ++dy) {
                loc[0] = pos[0] + dx, loc[1] = pos[1] + dy;
                if (dx == 0 || loc[0] < 1 || loc[0] > 8 || loc[1] < 1 || loc[1] > 8) continue;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
            for (int dx = -7, dy = 7; dx <= 7; ++dx, --dy) {
                loc[0] = pos[0] + dx, loc[1] = pos[1] + dy;
                if (dx == 0 || loc[0] < 1 || loc[0] > 8 || loc[1] < 1 || loc[1] > 8) continue;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
        } else {
            for (int dx = -7, dy = -7; dx <= 7; ++dx, ++dy) {
                loc[0] = pos[0] + dx, loc[1] = pos[1] + dy;
                if (loc[0] < 1 || loc[0] > 8 || loc[1] < 1 || loc[1] > 8) continue;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
            for (int dx = -7, dy = 7; dx <= 7; ++dx, --dy) {
                loc[0] = pos[0] + dx, loc[1] = pos[1] + dy;
                if (dx == 0 || loc[0] < 1 || loc[0] > 8 || loc[1] < 1 || loc[1] > 8) continue;
                if (check(pieces, positions, depth, locations)) {
                    dfs(pieces, positions, depth + 1, locations);
                }
            }
        }
    }

public:
    int countCombinations(const vector<string> &pieces, const vector<vector<int>> &positions) {
        auto locations = vector(pieces.size(), vector(2, 0));
        dfs(pieces, positions, 0, locations);
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto pieces = vector<string>({"rook", "rook"});
    const auto positions = vector<vector<int>>({
            {1, 1},
            {8, 8},
    });
    Solution().countCombinations(pieces, positions);
    return 0;
}
#endif
