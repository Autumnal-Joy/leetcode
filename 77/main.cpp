#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int cnt, int begin, int end, vector<vector<int>>& res, vector<int>& path) {
        if (cnt == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= end; i++) {
            path.push_back(i);
            dfs(cnt - 1, i + 1, end, res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        auto res = vector<vector<int>>();
        auto path = vector<int>();
        dfs(k, 1, n, res, path);
        return res;
    }
};

int main() {
    return 0;
}
