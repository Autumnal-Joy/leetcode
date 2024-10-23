#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        auto res = vector<vector<string>>({{""}});
        for (int i = 1; i <= n; ++i) {
            for (auto &str: res[0]) {
                str += '(';
            }
            for (int j = 1; j < i; ++j) {
                auto temp = vector<string>();
                ranges::transform(res[j], std::back_inserter(temp), [](auto &str) {
                    return std::move(str += '(');
                });
                ranges::transform(res[j - 1], std::back_inserter(temp), [](const auto &str) {
                    return str + ')';
                });
                res[j] = std::move(temp);
            }
            res.emplace_back();
            ranges::transform(res[i - 1], std::back_inserter(res[i]), [](const auto &str) {
                return str + ')';
            });
        }
        return res[n];
    }
};

int main() {

    return 0;
}
