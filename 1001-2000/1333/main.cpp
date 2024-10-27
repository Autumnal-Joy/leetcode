#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                  int veganFriendly, int maxPrice,
                                  int maxDistance) {
        auto filtered = vector<vector<int>>();
        auto res = vector<int>();
        std::copy_if(restaurants.begin(), restaurants.end(),
                     std::back_inserter(filtered), [&](const auto &rest) {
                         return (veganFriendly == 0 || rest[2] == veganFriendly) &&
                                rest[3] <= maxPrice && rest[4] <= maxDistance;
                     });
        std::sort(filtered.begin(), filtered.end(),
                  [](const auto &a, const auto &b) {
                      return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
                  });
        std::transform(filtered.begin(), filtered.end(), std::back_inserter(res),
                       [](const auto &rest) { return rest[0]; });
        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
