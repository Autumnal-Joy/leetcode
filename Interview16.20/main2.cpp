#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    vector<unordered_set<char>> dict = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}};

public:
    vector<string> getValidT9Words(const string &num, vector<string> &words) {
        auto q = queue<string>();
        for (auto &word: words) {
            if (word.size() == num.size()) {
                q.push(std::move(word));
            }
        }

        for (int i = 0; i < num.size(); ++i) {
            auto n = q.size();
            while (n--) {
                const auto word = q.front();
                q.pop();
                if (dict[num[i] - '0'].contains(word[i])) {
                    q.push(word);
                }
            }
        }

        auto res = vector<string>();
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main() {

    return 0;
}
