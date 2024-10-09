#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    vector<int> manacher(const string &s) {
        auto d1 = vector<int>(s.size());
        int l = 0, r = -1;
        for (int i = 0; i < s.size(); ++i) {
            int k = i > r ? 1 : std::min({d1[l + r - i], r - i + 1});
            while (i - k >= 0 && i + k < s.size() && s[i - k] == s[i + k]) {
                ++k;
            }
            d1[i] = k;
            if (i + k - 1 > r) {
                r = i + k - 1;
                l = i - (k - 1);
            }
        }
        return d1;
    }

public:
    long long maxProduct(string s) {
        auto d1 = manacher(s);

        // prefix[i] 为 [0, i] 的最长回文子串长度
        auto prefix = vector<int>(s.size());
        // suffix[i] 为 [i, n-1] 的最长回文子串长度
        auto suffix = vector<int>(s.size());

        for (int i = 0; i < d1.size(); ++i) {
            auto left = i - (d1[i] - 1);
            auto right = i + (d1[i] - 1);
            prefix[right] = std::max({prefix[right], 2 * d1[i] - 1});
            suffix[left] = std::max({suffix[left], 2 * d1[i] - 1});
        }
        for (int i = 0; i + 1 < d1.size(); ++i) {
            prefix[i + 1] = std::max({prefix[i + 1], prefix[i]});
        }
        for (int i = d1.size() - 1; i - 1 >= 0; --i) {
            prefix[i - 1] = std::max({prefix[i - 1], prefix[i] - 2});
        }
        for (int i = d1.size() - 1; i - 1 >= 0; --i) {
            suffix[i - 1] = std::max({suffix[i - 1], suffix[i]});
        }
        for (int i = 0; i + 1 < d1.size(); ++i) {
            suffix[i + 1] = std::max({suffix[i + 1], suffix[i] - 2});
        }

        long long product = 0;
        for (int i = 0; i <= d1.size() - 2; ++i) {
            product = std::max({product, 1ll * prefix[i] * suffix[i + 1]});
        }

        return product;
    }
};

int main() {
    auto s = Solution();
    cout << s.maxProduct("ab") << endl;
    return 0;
}
