#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 1073741824 ~ 2147483647
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = -1;
        while (left <= right && left > 0) {
            res &= left;
            left = static_cast<int>(1ll + left + (left & -left));
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
