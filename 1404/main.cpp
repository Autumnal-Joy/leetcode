#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        auto cnt = vector<int>(2);
        bool startCnt = false;

        // 最后一个 1 的左边有 cnt[0] 个 0
        for (auto b = s.rbegin(); b != s.rend(); b++) {
            if (startCnt) {
                cnt[*b - '0']++;
            }
            if (!startCnt && *b == '1') {
                startCnt = true;
            }
        }

        if (cnt[0] == 0 && cnt[1] == 0) {
            // 1
            // 10..0
            return static_cast<int>(s.size()) - 1;
        } else if (cnt[0] == 0 && cnt[1] > 0) {
            // 1..1
            // 1..10..0
            return static_cast<int>(s.size()) + 1;
        } else {
            // 1xx1
            // 1xx10..0
            return cnt[0] + 1 + static_cast<int>(s.size());
        }
    }
};

int main() {
    auto s = Solution();
    cout << s.numSteps("10") << endl;
    return 0;
}
