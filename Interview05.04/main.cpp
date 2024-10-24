#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static int lowbit(const int num) {
        return num & -num;
    }
    // 将最后一个 01 反转，然后将后面的 1 挪到末尾
    static int next(const int num) {
        const auto lb = lowbit(num);
        // left 保存最后一个 01 之前的数，并反转 01 为 10，后面的数全为 0
        const auto left = num + lb;
        // right 保存了最后一个 01 以及之后的数，10 与 01 异或为 11，因此多了 2 个 1 通过移位舍去
        const auto right = (num ^ left) / lb >> 2;
        return left | right;
    }
    //
static bool exist10(const unsigned num) {
        return num & num + 1;
    }
    static bool exist01(const unsigned num) {
        return exist10(~num ^ 1 << 31);
    }

public:
    vector<int> findClosedNumbers(int num) {
        auto res = vector({-1, -1});
    if (exist01(num)) {
        res[0] = next(num);
    }
    if (exist10(num)) {
        res[1] = ~next(~num);
    }
    return res;
}
};

int main() {
    Solution().findClosedNumbers(7);
    return 0;
}
