#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class BIT {
    int n;
    std::vector<int> tree;

    static int lowbit(int x) { return x & -x; }

public:
    explicit BIT(int n) : n(n), tree(n + 1) {}
    void add(int i, int delta) {
        while (i <= n) {
            tree[i] += delta;
            i += lowbit(i);
        }
    }
    [[nodiscard]] int sum(int i) const {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
    [[nodiscard]] int rangeSum(int i, int j) const { return sum(j) - sum(i - 1); }
};

class StreamRank {
    BIT bit;

public:
    StreamRank() : bit(50002) {}

    void track(int x) {
        bit.add(x + 1, 1);
        bit.add(50002, -1);
    }

    int getRankOfNumber(int x) {
        return bit.sum(x + 1);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */

int main() {

    return 0;
}
