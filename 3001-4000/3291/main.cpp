#include <bits/stdc++.h>

using namespace std;

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

class Trie {
public:
    unordered_map<char, Trie *> children;
    bool isEndOfWord = false;
    bool insert(const string_view &word) {
        auto node = this;
        for (char ch: word) {
            if (!node->children.contains(ch)) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        const auto res = !node->isEndOfWord;
        node->isEndOfWord = true;
        return res;
    }
};

class Solution {
public:
    int minValidStrings(const vector<string> &words, const string &target) {
        auto trie = Trie();
        for (const auto &word: words) {
            trie.insert(word);
        }
        const auto str = string_view(target);
        const auto n = static_cast<int>(str.size());
        auto dp = vector(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            auto *node = &trie.children;
            for (int j = 0; i + j < n; ++j) {
                const auto &next = node->find(target[i + j]);
                if (next == node->end()) break;
                node = &next->second->children;
                dp[i + j + 1] = std::min(dp[i + j + 1], dp[i] + 1);
            }
        }
        return dp[n] == 0x3f3f3f3f ? -1 : dp[n];
    }
};

#ifdef LEETCODE
int main() {
    auto words = vector<string>({"abcdef"});
    auto target = string("xyz");
    Solution().minValidStrings(words, target);
    return 0;
}
#endif
