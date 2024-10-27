#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    int res;
    unordered_set<int> blacklist;
    int maxCnt;
    int avoid;

    bool dfs(int begin, int cnt, int sum) {
        if (cnt == maxCnt) {
            res = min(res, sum);
            return true;
        }
        for (int i = begin;; ++i) {
            auto it = blacklist.find(i);
            if (it != blacklist.end()) {
                continue;
            }
            if (i < avoid) {
                blacklist.insert(avoid - i);
            }

            if (dfs(i + 1, cnt + 1, sum + i)) {
                return true;
            }

            if (i < avoid) {
                blacklist.erase(avoid - i);
            }
        }
    }

public:
    Solution() : res(numeric_limits<int>::max()) {}

    int minimumSum(int n, int k) {
        maxCnt = n;
        avoid = k;
        dfs(1, 0, 0);
        return res;
    }
};

int main() {
    Solution s;
    s.minimumSum(5, 4);
    return 0;
}
