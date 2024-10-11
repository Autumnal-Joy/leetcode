#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int> &nums) {
        auto n = static_cast<long long>(nums.size()) + 2;
        auto a = (1 + n) * n / 2 - accumulate(nums.cbegin(), nums.cend(), 0ll);
        auto b = (1 + n) * n / 2 * (2 * n + 1) / 3 -
                 inner_product(nums.cbegin(), nums.cend(), nums.cbegin(), 0ll);
        auto diff = static_cast<long long>(sqrt(2 * b - a * a));
        return {static_cast<int>((a + diff) / 2), static_cast<int>((a - diff) / 2)};
    }
};

int main() {
    auto s = Solution();
    auto v = vector<int>({5, 6, 7, 8, 9, 1, 3, 4});
    s.missingTwo(v);
    return 0;
}
