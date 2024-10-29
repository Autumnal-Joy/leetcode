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
    vector<int> sockCollocation(vector<int> &sockets) {
        const auto xor_all = std::reduce(sockets.begin(), sockets.end(), 0, std::bit_xor<>());
        const auto lb = xor_all & -xor_all;
        auto a = 0, b = 0;
        for (const auto &sock: sockets) {
            if (sock & lb) {
                a ^= sock;
            } else {
                b ^= sock;
            }
        }
        return {a, b};
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
