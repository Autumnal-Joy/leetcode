#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BIT {
private:
    int size;
    vector<int> tree;

    static int lowbit(int x) { return x & -x; }

public:
    explicit BIT(int n) : size(n + 1), tree(n + 1, 1) {}

    void update(int n, int val) {
        n++;
        while (n <= size) {
            tree[n] *= val;
            n += lowbit(n);
        }
    }

    // [0, n)
    int query(int n) {
        int sum = 1;

        while (n > 0) {
            sum *= tree[n];
            n -= lowbit(n);
        }

        return sum;
    }

    int query(int i, int j) { return query(j) / query(i); }
};

// 单点修改、区间求和
class ProductOfNumbers {
private:
    BIT bit;
    int size;

public:
    ProductOfNumbers() : bit(40000), size(0) {}

    void add(int num) {
        if (num == 0) {
            bit = BIT(40000);
            size = 0;
        } else {
            bit.update(size++, num);
        }
    }

    int getProduct(int k) {
        if (size < k) {
            return 0;
        } else {
            return bit.query(size - k, size);
        }
    }
};

int main() {
    ProductOfNumbers productOfNumbers = ProductOfNumbers();
    productOfNumbers.add(31);
    productOfNumbers.add(36);
    productOfNumbers.add(69);
    productOfNumbers.add(34);
    productOfNumbers.add(73);
    cout << productOfNumbers.getProduct(5) << endl;
    productOfNumbers.add(0);
    cout << productOfNumbers.getProduct(5) << endl;
    productOfNumbers.add(72);
    cout << productOfNumbers.getProduct(1) << endl;
    cout << productOfNumbers.getProduct(2) << endl;
    return 0;
}
