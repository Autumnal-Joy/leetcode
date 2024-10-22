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
    void add(int i, int delta) {
        while (i <= n) {
            tree[i] += delta;
            i += lowbit(i);
        }
    }
    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
    int rangeSum(int i, int j) { return sum(j) - sum(i - 1); }

public:
    explicit BIT(int n) : n(n), tree(n + 2) {}
    void rangeAdd(int i, int j, int delta) {
        add(i, delta);
        add(j + 1, -delta);
    }
    int query(int i) { return sum(i); }
};

class Solution {
public:
    int maxAliveYear(vector<int> &birth, vector<int> &death) {
        auto n = static_cast<int>(birth.size());
        auto bit = BIT(102);
        for (int i = 0; i < n; ++i) {
            bit.rangeAdd(birth[i] - 1899, death[i] - 1899, 1);
        }
        int maxAlive = 0, maxAliveYear = 0;
        for (int i = 1900; i <= 2000; ++i) {
            if (bit.query(i - 1899) > maxAlive) {
                maxAlive = bit.query(i - 1899);
                maxAliveYear = i;
            }
        }
        return maxAliveYear;
    }
};

int main() {

    return 0;
}
