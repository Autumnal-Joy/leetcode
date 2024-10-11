#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        string res;
        string nums = "123456789";
        for (int i = 0; i < n; ++i) {
            int idx = (k - 1) / factorial[n - 1 - i];
            res.push_back(nums[idx]);
            nums.erase(nums.begin() + idx);
            k -= idx * factorial[n - 1 - i];
        }
        return res;
    }
};

int main() { return 0; }
