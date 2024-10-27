#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// 12345
// 1235+1240+1300+1346
// 32123
// 3213+3214+3200+3124+10000

class Solution {
public:
    int solve(string numStr, const int loc) {
        if (numStr[loc] < '2') {
            numStr.replace(loc, numStr.size() - loc, numStr.size() - loc - 1, '0');
            int num = 0;
            if (!numStr.empty()) {
                num = stoi(numStr);
            }
            return num;
        }
        if (numStr[loc] == '2') {
            numStr.erase(loc, 1);
            int num = 0;
            if (!numStr.empty()) {
                num = stoi(numStr);
            }
            return num + 1;
        }
        numStr.replace(loc, numStr.size() - loc, numStr.size() - loc - 1, '0');
        int num = 0;
        if (!numStr.empty()) {
            num = stoi(numStr);
        }
        return num + static_cast<int>(std::pow(10, numStr.size() - loc));
    }
    int numberOf2sInRange(int n) {
        const auto num = to_string(n);
        int res = 0;
        for (int i = 0; i < num.size(); ++i) {
            res += solve(num, i);
        }
        return res;
    }
};

int main() {
    cout << Solution().numberOf2sInRange(2) << endl;
    return 0;
}
