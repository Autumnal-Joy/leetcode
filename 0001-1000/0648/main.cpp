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
    queue<TreeNode *> q;
    q.push(root);
    for (size_t i = 1; i < vec.size(); i += 2) {
        TreeNode *node = q.front();
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
#endif

class Trie {
    unordered_map<char, Trie *> children;
    bool isEndOfWord = false;

public:
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
    string search(const string_view &word) {
        auto res = string();
        auto pNode = this;
        for (const auto &ch: word) {
            if (pNode->isEndOfWord) {
                break;
            }
            if (!pNode->children.contains(ch)) {
                res = word;
                break;
            }
            pNode = pNode->children[ch];
            res.push_back(ch);
        }
        return res;
    }
};

vector<string_view> split(const string_view &str, const char delim) {
    auto res = vector<string_view>();
    auto start = size_t{0};
    auto end = str.find(delim);
    while (end != string::npos) {
        res.emplace_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delim, start);
    }
    res.emplace_back(str.substr(start));
    return res;
}

string join(const vector<string> &vec, const char delim) {
    auto res = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        res += delim;
        res += vec[i];
    }
    return res;
}

class Solution {
public:
    string replaceWords(const vector<string> &dictionary, const string& sentence) {
        auto trie = Trie();
        for (const auto &root: dictionary) {
            trie.insert(root);
        }
        const auto words = split(sentence, ' ');
        auto res = vector<string>();
        for (auto word: words) {
            res.push_back(trie.search(word));
        }
        return join(res, ' ');
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
