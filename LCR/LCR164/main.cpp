#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string crackPassword(vector<int> &password) {
        auto temp = vector<string>();
        ranges::transform(password, std::back_inserter(temp), [](const auto &a) {
            return std::to_string(a);
        });
        ranges::sort(temp, [](const string &a, const string &b) {
            return a + b < b + a;
        });
        return std::reduce(temp.begin(), temp.end(), string(), [](string &total, const string &str) {
            return total += str;
        });
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
