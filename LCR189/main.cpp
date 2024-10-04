#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int mechanicalAccumulator(int target) {
    return target == 1 ? 1 : mechanicalAccumulator(target - 1) + target;
  }
};

int main() {
  auto s = Solution();
  return 0;
}
