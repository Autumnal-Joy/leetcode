#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// O(MN)
class Solution {
public:
    int respace(vector<string> &dictionary, const string &sentence) {
        if (sentence.empty()) {
            return 0;
        }

        const auto sentenceView = string_view(sentence);
        const auto n = static_cast<int>(sentenceView.size());

        // dp[i] 表示 sentence[0, i) 中未识别的字符数
        auto dp = vector(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (const auto &word: dictionary) {
                const auto m = static_cast<int>(word.size());
                if (i >= m && sentenceView.substr(i - m, m) == word) {
                    dp[i] = min(dp[i], dp[i - m]);
                }
            }
        }

        return dp[n];
    }
};

int main() {
    auto dictionary = vector<string>{"jxnonurhhuanyuqahjy", "phrxu", "hjunypnyhajaaqhxduu"};
    auto sentence = "qahurhoharrdjxnonurhhuanyuqahjyppnha";
    cout << Solution().respace(dictionary, sentence) << endl;
    return 0;
}
