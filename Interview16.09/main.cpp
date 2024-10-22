#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Operations {
    vector<long long> negative;
    vector<long long> positive;

    [[nodiscard]] long long neg(long long a) const {
        long long negA = 0;

        if (a >= 0) {
            for (long long i = static_cast<long long>(negative.size()) - 1; i >= 0; --i) {
                if (negA + negative[i] + a >= 0) {
                    negA += negative[i];
                }
            }
        } else {
            for (long long i = static_cast<long long>(positive.size()) - 1; i >= 0; --i) {
                if (positive[i] + a + negA <= 0) {
                    negA += positive[i];
                }
            }
        }
        return negA;
    }

public:
    Operations() {
        negative = vector<long long>({-1, -2, -4, -8, -16, -32, -64, -128,
                                      -256, -512, -1024, -2048, -4096, -8192, -16384, -32768,
                                      -65536, -131072, -262144, -524288, -1048576, -2097152, -4194304, -8388608,
                                      -16777216, -33554432, -67108864, -134217728, -268435456, -536870912, -1073741824, -2147483648});
        positive = vector<long long>({1, 2, 4, 8, 16, 32, 64, 128,
                                      256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
                                      65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608,
                                      16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648});
    }

    int minus(long long a, long long b) {
        return static_cast<int>(a + neg(b));
    }

    int multiply(long long a, long long b) {
        if (a < 0) {
            return static_cast<int>(neg(multiply(neg(a), b)));
        }
        if (b < 0) {
            return static_cast<int>(neg(multiply(a, neg(b))));
        }
        if (a > b) {
            return multiply(b, a);
        }

        auto cache = vector<long long>(positive.size(), 0);
        cache[0] = b;
        for (long long i = 1; i < cache.size(); ++i) {
            cache[i] = cache[i - 1] + cache[i - 1];
        }

        long long sumB = 0;
        long long coefficient = 0;
        for (long long i = static_cast<long long>(positive.size()) - 1; i >= 0; --i) {
            if (a >= coefficient + positive[i]) {
                coefficient += positive[i];
                sumB += cache[i];
            }
        }
        return static_cast<int>(sumB);
    }

    int divide(long long a, long long b) {
        if (a < 0) {
            return static_cast<int>(neg(divide(neg(a), b)));
        }
        if (b < 0) {
            return static_cast<int>(neg(divide(a, neg(b))));
        }

        auto cache = vector<long long>(positive.size(), 0);
        cache[0] = b;
        for (long long i = 1; i < cache.size(); ++i) {
            cache[i] = cache[i - 1] + cache[i - 1];
        }

        long long sumB = 0;
        long long coefficient = 0;
        for (long long i = static_cast<long long>(positive.size()) - 1; i >= 0; --i) {
            if (a >= sumB + cache[i]) {
                coefficient += positive[i];
                sumB += cache[i];
            }
        }
        return static_cast<int>(coefficient);
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */

int main() {
    auto obj = Operations();
    cout << obj.multiply(-1, -2147483647) << endl;
    return 0;
}
