#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    string dict = "22233344455566677778889999";

    bool match(const string &num, const string &word) const {
        if (num.size() != word.size()) {
            return false;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != dict[word[i] - 'a']) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> getValidT9Words(const string &num, vector<string> &words) {
        auto res = vector<string>();

        for (auto &word: words) {
            if (match(num, word)) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
