#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WordsFrequency {
    unordered_map<string, int> mp;

public:
    explicit WordsFrequency(vector<string> &book) {
        for (const auto &word: book) {
            ++mp[word];
        }
    }

    int get(const string& word) {
        return mp[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */

int main() {

    return 0;
}
