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
#endif

class Solution {
public:
    string alienOrder(const vector<string> &words) {
        auto alphabet = unordered_set<int>();
        for (const auto &word: words) {
            for (const auto ch: word) {
                alphabet.insert(ch - 'a');
            }
        }
        auto in = vector<int>(26);
        auto out = vector<unordered_set<int>>(26);
        for (int i = 1; i < words.size(); ++i) {
            const auto &prev = words[i - 1];
            const auto &next = words[i];
            int j = 0;
            while (j < prev.size() && j < next.size() &&
                   prev[j] == next[j]) {
                ++j;
            }
            if (j != prev.size() && j == next.size()) return "";
            if (j < prev.size() && j < next.size()) {
                if (!out[prev[j] - 'a'].contains(next[j] - 'a')) {
                    out[prev[j] - 'a'].insert(next[j] - 'a');
                    in[next[j] - 'a']++;
                }
            }
        }
        auto start = deque<int>();
        for (const auto ch: alphabet) {
            if (in[ch] == 0) {
                start.push_back(ch);
            }
        }
        auto res = string();
        for (int i = 0; i < alphabet.size(); ++i) {
            if (start.empty()) {
                return "";
            }
            const auto num = start.back();
            start.pop_back();
            res.push_back('a' + num);
            for (const auto &next: out[num]) {
                --in[next];
                if (in[next] == 0) {
                    start.push_back(next);
                }
            }
        }
        return res;
    }
};

#ifdef LEETCODE
int main() {
    auto words = vector<string>({"abc", "ab"});
    cout << Solution().alienOrder(words) << endl;
    return 0;
}
#endif
