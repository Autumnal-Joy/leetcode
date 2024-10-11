#include <vector>

using namespace std;

class Solution {
    long long xor3(long long a, long long b) {
        long long ret = 0, pow = 1;
        while (a > 0 || b > 0) {
            ret += pow * ((a % 3 + b % 3) % 3);
            a /= 3, b /= 3, pow *= 3;
        }
        return ret;
    }

public:
    int trainingPlan(vector<int> &actions) {
        long long ret = 0;
        for (auto a: actions) {
            ret = xor3(ret, a);
        }
        return static_cast<int>(ret);
    }
};

int main() {
    return 0;
}
