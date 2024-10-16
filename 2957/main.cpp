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
    bool apprEqual(char a, char b) { return std::abs(a - b) <= 1; }
    int removeAlmostEqualCharacters(string word) {
        int cnt = 0;
        for (int i = 1; i < word.size(); ++i) {
            if (apprEqual(word[i - 1], word[i])) {
                ++cnt;
                word[i] = '_';
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}
