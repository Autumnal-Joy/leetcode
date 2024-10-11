#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        auto count = vector<int>(26);
        int res = 0;

        while (true) {
            auto maxCnt = *std::max_element(count.begin(), count.end());

            if (right - left - maxCnt <= k) {
                res = std::max({res, right - left});
                if (right == s.size()) {
                    break;
                }
                ++count[s[right] - 'A'];
                ++right;
            } else {
                --count[s[left] - 'A'];
                ++left;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.characterReplacement("ABAAAAAAABBBABBBABBBABBB", 3) << endl;
    return 0;
}
