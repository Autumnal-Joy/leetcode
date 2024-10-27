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
    string printBin(double num) {
        auto res = string("0.");
        double base = 1;
        for (int i = 0; i < 6; ++i) {
            base *= 0.5;
            if (num + 1e-7 > base) {
                res.push_back('1');
                num -= base;
            } else {
                res.push_back('0');
            }
            if (num == 0) {
                break;
            }
        }
        if (num == 0) {
            return res;
        }
        return "ERROR";
    }
};

int main() {

    return 0;
}
