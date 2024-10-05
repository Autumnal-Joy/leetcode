#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = static_cast<int>(gas.size());

    int start = 0, totalGas = 0;
    int current = 0;
    while (true) {
      totalGas += gas[current % n] - cost[current % n];
      if (totalGas < 0) {
        start = current + 1;
        totalGas = 0;
      }
      ++current;

      if (current - start == n) {
        return start;
      }
      if (start >= n) {
        return -1;
      }
    }
  }
};

int main() {
  auto s = Solution();
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  cout << s.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
