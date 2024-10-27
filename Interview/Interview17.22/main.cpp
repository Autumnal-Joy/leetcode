#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    static bool near(const string &s1, const string &s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt > 1) return false;
            }
        }
        return cnt == 1;
    }
    static vector<string> findLadders(const string &beginWord, const string &endWord, vector<string> &wordList) {
        auto n = static_cast<int>(wordList.size());
        int begin = -1, end = -1;
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == beginWord) {
                begin = i;
            }
            if (wordList[i] == endWord) {
                end = i;
            }
        }
        if (begin == -1) {
            wordList.push_back(beginWord);
            begin = n;
            ++n;
        }
        if (end == -1) {
            return {};
        }
        if (begin == end) {
            return {beginWord};
        }

        auto adj = vector<unordered_set<int>>(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (near(wordList[i], wordList[j])) {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }
        }
        auto path = vector<string>();
        auto visited = vector<bool>(n, false);
        function<bool(int)> dfs = [&](const int node) {
            visited[node] = true;
            path.push_back(wordList[node]);
            if (node == end) {
                return true;
            }
            for (auto next: adj[node]) {
                if (!visited[next] && dfs(next)) {
                    return true;
                }
            }
            path.pop_back();
            return false;
        };
        if (dfs(begin)) {
            return path;
        }
        return {};
    }
};


int main() {
    const auto beginWord = "hit";
    const auto endWord = "cog";
    auto wordList = vector<string>{"hot", "dot", "dog", "lot", "log", "cog"};
    auto s = Solution();
    s.findLadders(beginWord, endWord, wordList);
    return 0;
}
