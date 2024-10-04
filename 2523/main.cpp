#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    auto isPrime = vector<bool>(right + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= right; ++i) {
      if (isPrime[i]) {
        for (int j = i * i; j <= right; j += i) {
          isPrime[j] = false;
        }
      }
    }
    auto res = vector<int>({-1, -1});
    int primeA, primeB = -1;
    for (int i = left; i <= right; ++i) {
      if (isPrime[i]) {
        primeA = primeB;
        primeB = i;
        if (primeA != -1 &&
            (res[0] == -1 || primeB - primeA < res[1] - res[0])) {
          res[0] = primeA;
          res[1] = primeB;
        }
      }
    }
    return res;
  }
};

int main() {
  auto s = Solution();
  cout << s.closestPrimes(1, 1)[0] << endl;
  return 0;
}
