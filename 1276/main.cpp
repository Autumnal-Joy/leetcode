#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        auto remains = tomatoSlices - 2 * cheeseSlices;
        int cnt1 = -1, cnt2 = -1;
        if (remains % 2 == 0) {
            cnt1 = remains / 2;
            cnt2 = cheeseSlices - cnt1;
        }
        if (cnt1 >= 0 && cnt2 >= 0) {
            return {cnt1, cnt2};
        } else {
            return {};
        }
    }
};

int main() {
    auto s = Solution();
    return 0;
}
