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

const auto DIRS = vector<pair<int, int>>({
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
});

enum {
    Cat = 0,
    Mouse = 1,
    Unknown = 2,
};

class Solution {

public:
    bool canMouseWin(const vector<string> &grid, int catJump, int mouseJump) {
        const auto m = static_cast<int>(grid.size());
        const auto n = static_cast<int>(grid[0].size());
        const auto N = m * n;

        int cat_s = 0, mouse_s = 0, food = 0;
        vector<vector<int>> g_mouse(N), g_cat(N);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '#') continue;
                const int v = i * n + j;
                if (grid[i][j] == 'C') {
                    cat_s = v;
                } else if (grid[i][j] == 'M') {
                    mouse_s = v;
                } else if (grid[i][j] == 'F') {
                    food = v;
                }
                g_cat[v].push_back(v);
                g_mouse[v].push_back(v);
                for (const auto &[dx, dy]: DIRS) {
                    for (int k = 1; k <= catJump; ++k) {
                        const int nx = i + dx * k, ny = j + dy * k;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') {
                            break;
                        }
                        g_cat[v].push_back(nx * n + ny);
                    }
                    for (int k = 1; k <= mouseJump; ++k) {
                        const int nx = i + dx * k, ny = j + dy * k;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') {
                            break;
                        }
                        g_mouse[v].push_back(nx * n + ny);
                    }
                }
            }
        }

        auto winner = vector(N, vector(N, vector(2, 2)));
        auto q = deque<tuple<int, int, int>>();
        for (int i = 0; i < N; ++i) {
            winner[i][food][Cat] = Mouse;
            winner[i][i][Cat] = winner[i][i][Mouse] = Cat;
            q.emplace_back(i, food, Cat);
            q.emplace_back(i, i, Cat);
            q.emplace_back(i, i, Mouse);
        }

        auto get_pre_states = [&](const int cat, const int mouse, const int turn) {
            auto res = vector<pair<int, int>>();

            if (turn == Cat) {
                for (const auto &pre_mouse: g_mouse[mouse]) {
                    if (winner[cat][pre_mouse][Mouse] == Unknown) {
                        res.emplace_back(cat, pre_mouse);
                    }
                }
            } else {
                for (const auto &pre_cat: g_cat[cat]) {
                    if (winner[pre_cat][mouse][Cat] == Unknown) {
                        res.emplace_back(pre_cat, mouse);
                    }
                }
            }

            return res;
        };

        auto degree = vector(N, vector(N, vector(2, 0)));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                degree[i][j][0] = static_cast<int>(g_cat[i].size());
                degree[i][j][1] = static_cast<int>(g_mouse[j].size());
            }
        }

        while (!q.empty()) {
            const auto [cat, mouse, turn] = q.front();
            q.pop_front();
            const auto pre_turn = turn ^ 1;
            const auto win = winner[cat][mouse][turn];
            for (auto [pre_cat, pre_mouse]: get_pre_states(cat, mouse, turn)) {
                if (pre_turn == win || --degree[pre_cat][pre_mouse][pre_turn] == 0) {
                    winner[pre_cat][pre_mouse][pre_turn] = win;
                    q.emplace_back(pre_cat, pre_mouse, pre_turn);
                }
            }
        }

        return winner[cat_s][mouse_s][Mouse] == Mouse;
    }
};

#ifdef LEETCODE
int main() {
    const auto grid1 = vector<string>({
            "####F",
            "#C...",
            "M....",
    });
    Solution().canMouseWin(grid1, 1, 3);
    return 0;
}
#endif
