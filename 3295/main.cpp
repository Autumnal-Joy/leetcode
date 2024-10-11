#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool reportSpam(const vector<string> &message,
                    const vector<string> &bannedWords) {
        auto blacklist =
                unordered_set<string>(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (const auto &word: message) {
            if (blacklist.count(word)) {
                cnt++;
            }
            if (cnt > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto s = Solution();
    cout << s.reportSpam({"hello", "world", "leetcode"}, {"world", "hello"})
         << endl;
    return 0;
}
