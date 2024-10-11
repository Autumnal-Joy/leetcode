#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// n=2, {a, b}, a>=b>=0，先手胜
//   a^b=0，先手胜
//   a>b=0，先手胜
//   a>b>0，先手胜
// n=3, {a, b, c}, a>=b>=c>=0
//   a^b^c=0，先手胜
//   否则后手胜
// n=4, {a, b, c, d}, a>=b>=c>=d>=0，先手胜
//   若任意3个数异或为0，则后手胜，即a=b=c=d=0，又先手胜，矛盾
//   存在3个数异或非0，先手胜
// n=5, {a, b, c, d, e}, a>=b>=c>=d>=e>=0
//   a^b^c^d^e=0，先手胜
//   否则后手胜

class Solution {
public:
    bool xorGame(const vector<int> &nums) {
        if ((nums.size() & 1) == 0) {
            return true;
        }
        auto xorVal = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor());
        return xorVal == 0;
    }
};

int main() {
    auto s = Solution();
    cout << s.xorGame({1, 1, 2}) << endl;
    return 0;
}
