#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    template<typename T, size_t N>
    class HashArray {
    public:
        size_t operator()(const array<T, N> &arr) const {
            return std::accumulate(arr.begin(), arr.end(), static_cast<size_t>(0), [hasher = hash<T>()](const size_t seed, const T &val) {
                return seed ^ hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            });
        }
    };

    unordered_map<array<int, 2>, int, HashArray<int, 2>> memo;


public:
    int multiply(int A, int B) {
        if (!memo.contains({A, B})) {
            if (A > B) {
                memo[{A, B}] = multiply(B, A);
            } else if (A & 1) {
                memo[{A, B}] = multiply(A - 1, B) + B;
            } else if (A == 0) {
                memo[{A, B}] = 0;
            } else {
                memo[{A, B}] = multiply(A / 2, B) << 1;
            }
        }
        return memo[{A, B}];
    }
};

int main() {

    return 0;
}
