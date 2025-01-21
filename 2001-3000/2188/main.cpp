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

#define Array1(type, size1) array<type, size1>
#define Array2(type, size1, size2) array<array<type, size2>, size1>
#define Array3(type, size1, size2, size3) array<array<array<type, size3>, size2>, size1>

constexpr int N = 1e5 + 1;
constexpr int L = 1001;

class Solution {
public:
    int minimumFinishTime(const vector<vector<int>> &tires, const int changeTime, const int numLaps) {
        const auto n = static_cast<int>(tires.size());
        auto minSec = vector(18, 0x3f3f3f3f);
        for (int i = 0; i < n; ++i) {
            long long time = tires[i][0], sum = 0;
            for (int x = 1; time <= changeTime + tires[i][0]; ++x) {
                sum += time;
                minSec[x] = std::min(minSec[x], static_cast<int>(sum));
                time *= tires[i][1];
            }
        }

        auto dp = vector(numLaps + 1, 0x3f3f3f3f);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j <= std::min(i, 17); ++j) {
                dp[i] = std::min(dp[i], dp[i - j] + minSec[j]);
            }
            dp[i] += changeTime;
        }
        return dp[numLaps];
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
