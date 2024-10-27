#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 3241

class Solution {
public:
    bool solve(string &n) {
        if (n.size() < 2) {
            return false;
        }

        if (n.size() == 2) {
            if (n[0] < n[1]) {
                std::swap(n[0], n[1]);
                return true;
            } else {
                return false;
            }
        }

        auto subNum = n.substr(1);
        if (solve(subNum)) {
            n = n[0] + subNum;
            return true;
        }

        int idx = -1;
        char minDigit = '9' + 1;
        for (int i = 1; i < n.size(); i++) {
            if (n[i] > n[0] && n[i] < minDigit) {
                idx = i;
                minDigit = n[i];
            }
        }
        if (idx == -1) {
            return false;
        }
        std::swap(n[0], n[idx]);
        std::sort(n.begin() + 1, n.end());
        return true;
    }

    int nextGreaterElement(int n) {
        string s = std::to_string(n);
        if (!solve(s)) {
            return -1;
        }
        long long res = std::stoll(s);
        return res > INT_MAX ? -1 : static_cast<int>(res);
    }
};

int main() {
    auto s = Solution();
    cout << s.nextGreaterElement(321) << endl;
    return 0;
}
