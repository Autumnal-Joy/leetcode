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
    vector<int> statisticalResult(vector<int> &arrayA) {
        auto res = vector<int>();
        auto mul = 1;
        auto cnt0 = 0;
        for (const auto num: arrayA) {
            if (num) {
                mul *= num;
            } else {
                ++cnt0;
            }
        }
        if (cnt0 == 0) {
            for (const auto num: arrayA) {
                res.push_back(mul / num);
            }
        } else if (cnt0 == 1) {
            for (const auto num: arrayA) {
                if (num == 0) {
                    res.push_back(mul);
                } else {
                    res.push_back(0);
                }
            }
        } else {
            for (auto _: arrayA) {
                res.push_back(0);
            }
        }

        return res;
    }
};

int main() {

    return 0;
}
