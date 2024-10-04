#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// n=3
// 123, 213, 231, 321

// n=4
// 1234, 2134, 2314, 3214, 2341, 2431, 3241, 4231

// n>1时
// 假设最后一项等于 k (1<k<n)，则第 k 项不为 k，则前 k-1 项占据了 k，矛盾
// 最后一项只能为 1 或 n
// 最后一项为 1 的排列定义为集合 A，最后一项为 n 的排列定义为集合 B
// 对于映射关系“交换 1 和 n”，满足满射+单射，即可证明 A 和 B 的元素个数相等

class Solution {
public:
  double nthPersonGetsNthSeat(int n) { return n > 1 ? 0.5 : 1; }
};

int main() {
  auto s = Solution();
  return 0;
}
