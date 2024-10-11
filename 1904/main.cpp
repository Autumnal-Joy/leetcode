#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static int count(int start, int end) {
        // [15t, 15t+15]
        int t = 0, cnt = 0;
        while (t * 15 + 15 <= end) {
            if (start <= t * 15 && end >= t * 15 + 15) {
                ++cnt;
            }
            ++t;
        }
        return cnt;
    }

    static bool early(int loginHour, int loginMinute, int logoutHour,
                      int logoutMinute) {
        return loginHour < logoutHour ||
               (loginHour == logoutHour && loginMinute < logoutMinute);
    }

public:
    int numberOfRounds(const string &loginTime, const string &logoutTime) {
        int loginHour = stoi(loginTime.substr(0, 2));
        int loginMinute = stoi(loginTime.substr(3, 2));
        int logoutHour = stoi(logoutTime.substr(0, 2));
        int logoutMinute = stoi(logoutTime.substr(3, 2));
        if (!early(loginHour, loginMinute, logoutHour, logoutMinute)) {
            logoutHour += 24;
        }
        if (logoutHour == loginHour) {
            return count(loginMinute, logoutMinute);
        } else {
            return count(loginMinute, 60) + count(0, logoutMinute) +
                   4 * (logoutHour - loginHour - 1);
        }
    }
};

int main() {
    auto s = Solution();
    cout << s.numberOfRounds("12:01", "12:44") << endl;
    return 0;
}
