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
    vector<int> findSubstring(const string &s, const vector<string> &words) {
        const auto n = static_cast<int>(words.size());
        const auto m = static_cast<int>(words[0].size());
        auto res = vector<int>();
        auto cnt1 = unordered_map<string_view, int>();
        for (const auto &word: words) {
            ++cnt1[word];
        }
        const auto cnt = static_cast<int>(cnt1.size());
        const auto str = string_view(s);
        for (int begin = 0; begin < m; ++begin) {
            auto cnt2 = unordered_map<string_view, int>();
            auto temp = 0;
            for (int left = begin, right = begin; right < s.size();) {
                auto word_add = str.substr(right, m);
                if (cnt2[word_add] == cnt1[word_add] - 1) {
                    ++temp;
                } else if (cnt2[word_add] == cnt1[word_add]) {
                    --temp;
                }
                ++cnt2[word_add];
                right += m;
                if (right - left == n * m) {
                    if (temp == cnt) res.push_back(left);
                    auto word_del = str.substr(left, m);
                    if (cnt2[word_del] == cnt1[word_del] + 1) {
                        ++temp;
                    } else if (cnt2[word_del] == cnt1[word_del]) {
                        --temp;
                    }
                    --cnt2[word_del];
                    left += m;
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    const auto s = string("barfoothefoobarman");
    const auto words = vector<string>({"foo", "bar"});
    Solution().findSubstring(s, words);
    return 0;
}
#endif
