#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int> &nums) {
        int n = static_cast<int>(nums.size()) + 2;

        int sum = n * (n + 1) / 2;
        for (auto num: nums) {
            sum -= num;
        }

        double product = 0;
        for (int i = 0; i < n; ++i) {
            product += std::log(i + 1);
        }
        for (auto num: nums) {
            product -= std::log(num);
        }
        product = std::exp(product);
        double delta = sqrt(sum * sum - 4 * product);
        double a = (sum + delta) / 2;
        double b = sum - a;

        return {static_cast<int>(std::round(a)), static_cast<int>(std::round(b))};
    }
};

int main() {
    auto s = Solution();
    auto v = vector<int>({5, 6, 7, 8, 9, 1, 3, 4});
    s.missingTwo(v);
    return 0;
}
