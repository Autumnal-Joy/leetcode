#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    static auto legal(const vector<int> &array, int x) {
        if (x == 1)
            return true;
        int remain = array[0] % x;
        for (int i = 1; i < array.size(); ++i) {
            if (array[i] % x != remain) {
                return false;
            }
        }

        return true;
    }

public:
    int minOperations(vector<vector<int>> &grid, int x) {
        auto array = vector<int>();
        for (const auto &v: grid) {
            std::copy(v.begin(), v.end(), std::back_inserter(array));
        }

        if (!legal(array, x)) {
            return -1;
        }

        std::sort(array.begin(), array.end());

        int cnt = 0;
        int middle = static_cast<int>(array.size()) / 2;
        for (int i = 0; i < middle; ++i) {
            cnt += (array[middle] - array[i]) / x;
        }
        for (int i = middle + 1; i < array.size(); ++i) {
            cnt += (array[i] - array[middle]) / x;
        }

        return cnt;
    }
};

int main() { return 0; }
