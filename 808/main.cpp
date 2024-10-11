#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int A, int B, map<pair<int, int>, double> &memo) {
        if (A <= 0 && B <= 0) {
            return 0.5;
        }
        if (A <= 0) {
            return 1;
        }
        if (B <= 0) {
            return 0;
        }
        if (memo[{A, B}] > 0) {
            return memo[{A, B}];
        }
        memo[{A, B}] = 0.25 * (soupServings(A - 100, B, memo) +
                               soupServings(A - 75, B - 25, memo) +
                               soupServings(A - 50, B - 50, memo) +
                               soupServings(A - 25, B - 75, memo));
        return memo[{A, B}];
    }

    double soupServings(int n) {
        map<pair<int, int>, double> memo;
        if (n > 5000) {
            return 1;
        }
        return soupServings(n, n, memo);
    }
};

int main() {
    auto s = Solution();
    cout << s.soupServings(660295675) << endl;

    return 0;
}
