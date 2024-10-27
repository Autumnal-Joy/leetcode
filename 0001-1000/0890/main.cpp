#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    static bool match(const string &word, const string &pattern) {
        if (word.size() != pattern.size()) {
            return false;
        }
        auto w2p = vector<int>(26, -1);
        auto p2w = vector<int>(26, -1);
        for (int i = 0; i < word.size(); i++) {
            // 检查 word[i] 是否一一映射到 pattern[i]
            int w = word[i] - 'a', p = pattern[i] - 'a';
            if (w2p[w] == -1 && p2w[p] == -1) {
                w2p[w] = p;
                p2w[p] = w;
            } else if (w2p[w] != p || p2w[p] != w) {
                return false;
            }
        }
        return true;
    }

public:
    static vector<string> findAndReplacePattern(const vector<string> &words,
                                                const string &pattern) {
        auto res = vector<string>();
        for (auto &word: words) {
            if (match(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    auto res = s.findAndReplacePattern({"abc", "deq", "mee", "aqq", "dkd", "ccc"},
                                       "abb");
    std::copy(res.begin(), res.end(), ostream_iterator<string>(cout, ", "));
    return 0;
}
