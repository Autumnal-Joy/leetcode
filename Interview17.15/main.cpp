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

    const Trie *search(const string_view &word) const {
        auto node = this;
        for (char ch: word) {
            if (!node->children.contains(ch)) {
                return nullptr;
            }
            node = node->children.find(ch)->second;
        }
        return node;
    }

    bool remove(Trie *node, const string_view &word, const int depth) {
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
    void insert(const string_view &word) {
        auto node = this;
        for (char ch: word) {
            if (!node->children.contains(ch)) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool contains(const string_view &word) const {
        if (const auto node = search(word)) {
            return node->isEndOfWord;
        }
        return false;
    }

    bool startsWith(const string_view &prefix) const {
        if (const auto node = search(prefix)) {
            return true;
        }
        return false;
    }

    void erase(const string_view &word) {
        remove(this, word, 0);
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        Trie trie;
        for (const string &word: words) {
            trie.insert(word);
        }


        auto blacklist = unordered_set<string_view>();
        function<bool(const string_view &, int)> dfs = [&](const string_view &word, int cnt) {
            if (cnt && trie.contains(word)) {
                return true;
            }
            if (word.size() < 2) {
                return false;
            }

            for (int i = static_cast<int>(word.size()) - 1; i > 0; --i) {
                const auto prefix = word.substr(0, i);
                const auto suffix = word.substr(i);
                if (!blacklist.contains(suffix) && trie.contains(prefix)) {
                    if (dfs(suffix, cnt + 1)) {
                        return true;
                    }
                    blacklist.insert(suffix);
                }
            }
            return false;
        };

        ranges::sort(words, [](const string &lhs, const string &rhs) {
            if (lhs.size() == rhs.size()) {
                return lhs < rhs;
            }
            return lhs.size() > rhs.size();
        });

        for (const auto &word: words) {
            if (dfs(word, 0)) {
                return word;
            }
        }
        return "";
    }
};

int main() {
    auto words = vector<string>({"cat", "banana", "dog", "nana", "walk", "walker", "dogwalker"});
    cout << Solution().longestWord(words) << endl;
    return 0;
}
