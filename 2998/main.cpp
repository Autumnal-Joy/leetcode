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
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y) {
            return y - x;
        }
        auto remain11 = x % 11;
        auto remain5 = x % 5;
        return std::min({
                x - y,
                remain11 + 1 + minimumOperationsToMakeEqual((x - remain11) / 11, y),
                11 - remain11 + 1 + minimumOperationsToMakeEqual((x - remain11 + 11) / 11, y),
                remain5 + 1 + minimumOperationsToMakeEqual((x - remain5) / 5, y),
                5 - remain5 + 1 + minimumOperationsToMakeEqual((x - remain5 + 5) / 5, y),
        });
    }
};

int main() {
    return 0;
}
