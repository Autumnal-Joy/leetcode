#include <iostream>

using namespace std;

namespace test {
    void copy() {}
}// namespace test

class Solution {
public:
    int twoEggDrop(int n) {
        int i = 0, cnt = 0;
        while (n > 0) {
            n -= i;
            ++i;
            ++cnt;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    return 0;
}
