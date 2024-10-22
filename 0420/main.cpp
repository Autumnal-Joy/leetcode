#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = static_cast<int>(password.size());

        int digitCnt = 0, lowerCnt = 0, upperCnt = 0;
        for (char c: password) {
            if (isdigit(c)) {
                ++digitCnt;
            } else if (islower(c)) {
                ++lowerCnt;
            } else if (isupper(c)) {
                ++upperCnt;
            }
        }
        int patch = (digitCnt == 0) + (lowerCnt == 0) + (upperCnt == 0);

        if (password.size() < 6) {
            return std::max(6 - static_cast<int>(password.size()), patch);
        }

        // 连续字符的长度大于 2 的子串入队列
        auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>>();
        for (int i = 0; i < password.size();) {
            int j = i;
            while (i < password.size() && password[i] == password[j]) {
                ++i;
            }
            if (i - j >= 3) {
                pq.emplace((i - j) % 3, i - j);
            }
        }

        int deleteCnt = std::max(n - 20, 0);
        while (n > 20 && !pq.empty()) {
            auto [remain, top] = pq.top();
            pq.pop();
            --n;
            if (top - 1 > 2) {
                pq.emplace((remain + 2) % 3, top - 1);
            }
        }

        int replaceCnt = 0;
        while (!pq.empty()) {
            auto [remain, top] = pq.top();
            pq.pop();
            ++replaceCnt;
            if (top - 3 > 2) {
                pq.emplace(remain, top - 3);
            }
        }

        return deleteCnt + std::max(replaceCnt, patch);
    }
};

int main() {
    auto s = Solution();
    cout << s.strongPasswordChecker("A234567890123aaaaaccc") << endl;
}
