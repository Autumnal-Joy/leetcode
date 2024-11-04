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
    int ladderLength(const string &beginWord, const string &endWord, vector<string> &wordList) {
        auto step = 1;
        if (beginWord == endWord) return step;

        auto words = unordered_set(wordList.begin(), wordList.end());

        auto dq = deque<string>();
        dq.push_back(beginWord);

        auto visited = unordered_set<string>();

        while (!dq.empty()) {
            auto n = dq.size();
            ++step;
            while (n--) {
                const auto front = dq.front();
                dq.pop_front();
                auto temp = front;
                for (int i = 0; i < beginWord.size(); ++i) {
                    for (char j = 'a'; j <= 'z'; ++j) {
                        temp[i] = j;
                        if (!words.contains(temp) || visited.contains(temp)) continue;
                        if (temp == endWord) return step;
                        visited.insert(temp);
                        dq.push_back(temp);
                    }
                    temp[i] = front[i];
                }
            }
        }
        return 0;
    }
};

#ifdef LEETCODE
int main() {
    auto beginWord = string("hit");
    auto endWord = string("cog");
    auto wordList = vector<string>({"hot", "dot", "dog", "lot", "log", "cog"});
    Solution().ladderLength(beginWord, endWord, wordList);
    return 0;
}
#endif
