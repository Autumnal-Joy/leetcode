#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    void dfs(int begin, int cnt, int target) {
        if (cnt == 0) {
            if (target == 0) {
                res.push_back(path);
            }
            return;
        }
        for (int i = begin; i <= 9; ++i) {
            if (target - i < 0) break;
            path.push_back(i);
            dfs(i + 1, cnt - 1, target - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};

int main() {
    auto s = Solution();
    return 0;
}
