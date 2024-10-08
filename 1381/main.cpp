#include <algorithm>
#include <vector>

using namespace std;

class BIT {
    int n;
    vector<int> tree;

    static int lowbit(int x) {
        return x & -x;
    }

public:
    explicit BIT(int n) : n(n), tree(n + 2) {}

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

    int rangeSum(int i, int j) {
        return sum(j) - sum(i - 1);
    }
};

class CustomStack {
    int maxSize;
    BIT bit;

    int size = 0;
public:
    explicit CustomStack(int maxSize) : maxSize(maxSize), bit(maxSize) {}

    // Stack: 0 0 0 0 0 -> 1 0  0 0 0 -> 1 2 0  0 0
    // BIT:   0 0 0 0 0 -> 0 1 -1 0 0 -> 0 1 1 -2 0
    void push(int x) {
        if (size < maxSize) {
            bit.add(size + 1, x);
            bit.add(size + 2, -x);
            ++size;
        }
    }

    // Stack: 1 2 3  0 0 -> 1 2  0 0 0 -> 1 0  0 0 0
    // BIT:   0 1 1 -3 0 -> 0 1 -2 0 0 -> 0 1 -1 0 0
    int pop() {
        if (size == 0) {
            return -1;
        }
        auto res = bit.sum(size);
        bit.add(size, -res);
        bit.add(size + 1, res);
        --size;
        return res;
    }

    void increment(int k, int val) {
        bit.add(1, val);
        bit.add(std::min({k, size}) + 1, -val);
    }
};


int main() {
    auto *obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    obj->pop();
    obj->push(2);
    obj->push(3);
    obj->push(3);
    obj->increment(5, 100);
    obj->increment(2, 100);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();

    return 0;
}
