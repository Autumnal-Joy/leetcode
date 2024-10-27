#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// O(N^3)
class Solution {
public:
    int respace(vector<string> &dictionary, const string &sentence) {
        if (sentence.empty()) {
            return 0;
        }

        auto trie = unordered_set<string_view>();
        for (const auto &word: dictionary) {
            trie.insert(word);
        }

        const auto n = static_cast<int>(sentence.size());
        const auto sentenceView = string_view(sentence);

        auto dp = vector(n, vector(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = trie.contains(sentenceView.substr(i, 1)) ? 0 : 1;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                if (trie.contains(sentenceView.substr(i, len))) {
                    dp[i][i + len - 1] = 0;
                } else {
                    int minVal = len;
                    for (int split = 1; split < len; ++split) {
                        minVal = min(minVal, dp[i][i + split - 1] + dp[i + split][i + len - 1]);
                    }
                    dp[i][i + len - 1] = minVal;
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    auto dictionary = vector<string>{"jxnonurhhuanyuqahjy", "phrxu", "hjunypnyhajaaqhxduu"};
    auto sentence = "qahurhoharrdjxnonurhhuanyuqahjyppnha";
    cout << Solution().respace(dictionary, sentence) << endl;
    return 0;
}
