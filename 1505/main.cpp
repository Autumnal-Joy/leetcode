#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class BIT {
    int n;
    vector<int> tree;

    static int lowBit(int x) { return x & -x; }

public:
    explicit BIT(int size) : n(size), tree(n + 1) {}

    void update(int idx, int delta) {
        ++idx;
        while (idx <= n) {
            tree[idx] += delta;
            idx += lowBit(idx);// 更新下一个位置
        }
    }

    // [0, idx) 项和
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= lowBit(idx);// 移动到父节点
        }
        return sum;
    }

    // [4, 6) 项和 = [0, 6) - [0, 4)
    int query(int left, int right) { return query(right) - query(left); }
};

class Solution {
public:
    string minInteger(string num, int k) {
        string res;
        auto bit = BIT(num.size());// bit[i] 表示第 i 个数字是否发生交换

        auto pos = vector<queue<int>>(10);
        for (int i = 0; i < num.size(); i++) {
            pos[num[i] - '0'].push(i);
        }

        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < 10; j++) {
                if (!pos[j].empty()) {
                    auto oldLoc = pos[j].front();
                    auto newLoc = oldLoc + bit.query(oldLoc + 1, num.size());
                    if (newLoc - i <= k) {
                        k -= newLoc - i;
                        res.push_back(j + '0');
                        bit.update(oldLoc, 1);
                        pos[j].pop();
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    auto s = Solution();
    cout << s.minInteger("4321", 4) << endl;
    return 0;
}
