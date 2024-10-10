#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int maxVal = 0;
        auto nums1Map = unordered_map<int, int>();
        for (auto n: nums1) {
            if (n % k == 0) {
                maxVal = std::max({maxVal, n / k});
                ++nums1Map[n / k];
            }
        }

        auto nums2Map = unordered_map<int, int>();
        for (auto n: nums2) {
            ++nums2Map[n];
        }

        long long ret = 0;
        for (auto [factor, cnt]: nums2Map) {
            for (int i = 0; i * factor <= maxVal; ++i) {
                ret += 1ll * nums1Map[i * factor] * cnt;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    return 0;
}
