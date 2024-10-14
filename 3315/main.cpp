#include <vector>

using namespace std;


//   0b100111
// = 0b100011
//  |0b100100
class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &nums) {

        auto res = vector<int>();

        for (auto p: nums) {
            if (p == 2) {
                res.push_back(-1);
            } else {
                int mask = (~p & -~p) >> 1;
                res.push_back(p ^ mask);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    auto v = vector<int>({2, 3, 5, 7});
    s.minBitwiseArray(v);
    return 0;
}
