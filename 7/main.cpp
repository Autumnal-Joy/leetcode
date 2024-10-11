#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 1463847412
// 2147483641

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        int neg = x < 0 ? -1 : 1;
        x = abs(x);

        int res = 0;
        while (x > 0) {
            if (res > INT_MAX / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        return neg * res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
