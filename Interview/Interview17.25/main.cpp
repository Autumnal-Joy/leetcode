#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Trie {
    unordered_map<char, Trie *> children;
    bool isEndOfWord = false;

    const Trie *search(const string &word) const {
        auto node = this;
        for (char ch: word) {
            if (!node->children.contains(ch)) {
                return nullptr;
            }
            node = node->children.find(ch)->second;
        }
        return node;
    }

    bool remove(Trie *node, const string &word, const int depth) {
        if (!node) {
            return false;
        }

        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;
                return node->children.empty();
            }
            return false;
        }

        if (const char ch = word[depth]; remove(node->children[ch], word, depth + 1)) {
            delete node->children[ch];
            node->children.erase(ch);
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }

public:
    void insert(const string &word) {
        auto node = this;
        for (char ch: word) {
            if (!node->children.contains(ch)) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool contains(const string &word) const {
        if (const auto node = search(word)) {
            return node->isEndOfWord;
        }
        return false;
    }

    bool startsWith(const string &prefix) const {
        if (const auto node = search(prefix)) {
            return true;
        }
        return false;
    }

    void remove(const string &word) {
        remove(this, word, 0);
    }
};


class Solution {
public:
    static bool isPrefix(const vector<string> &matrix, const Trie &trie) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            auto temp = string();
            for (const auto &word: matrix) {
                temp.push_back(word[j]);
            }
            if (!trie.startsWith(temp)) {
                return false;
            }
        }
        return true;
    }

    static bool isLarger(const vector<string> &matrix, const vector<string> &res) {
        if (matrix.empty()) {
            return false;
        }
        if (res.empty()) {
            return true;
        }
        const auto area1 = matrix.size() * matrix[0].size();
        const auto area2 = res.size() * res[0].size();
        if (area1 > area2) {
            return true;
        }
        return false;
    }

    bool dfs(size_t depth, const unordered_set<string> &eqLenWords, const Trie &trie,
             vector<string> &matrix, vector<string> &res) {
        if (!matrix.empty() && !isPrefix(matrix, trie)) {
            return false;
        }
        if (depth == 0 && isLarger(matrix, res)) {
            res = matrix;
            return true;
        }
        for (const auto &word: eqLenWords) {
            matrix.push_back(word);
            if (dfs(depth - 1, eqLenWords, trie, matrix, res)) {
                return true;
            }
            matrix.pop_back();
        }
        return false;
    }

    vector<string> maxRectangle(vector<string> &words) {
        auto len2words = unordered_map<size_t, unordered_set<string>>();
        auto tries = unordered_map<size_t, Trie>();
        auto lens = set<size_t>();

        for (const auto &word: words) {
            len2words[word.size()].insert(word);
            tries[word.size()].insert(word);
            lens.insert(word.size());
        }

        auto pairs = vector<pair<size_t, size_t>>();
        for (auto len1: lens) {
            for (auto len2: lens) {
                pairs.emplace_back(len1, len2);
            }
        }
        ranges::sort(pairs, [](const pair<size_t, size_t> &a, const pair<size_t, size_t> &b) {
            return a.first * a.second > b.first * b.second;
        });

        auto res = vector<string>();
        auto matrix = vector<string>();

        for (auto [len1, len2]: pairs) {
            if (dfs(len2, len2words[len1], tries[len2], matrix, res)) {
                break;
            }
        }
        return res;
    }
};

int main() {
    auto words = vector<string>({"j",
                                 "ebe", "rpj", "zdk",
                                 "dvca",
                                 "lcauj", "bojvf", "dasrc", "lruvq", "mdlby", "myulp", "pcjfn", "ukmkb", "usajk", "wsaep", "yacov", "yvkqn",
                                 "afqbhs",
                                 "nlrehaq", "wziqrdd"});
    auto s = Solution();
    auto res = s.maxRectangle(words);
    return 0;
}
