#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool checkSquare(const vector<vector<int>> &matrix, const int x, const int y, const int size) {
        for (int k = 0; k < size; ++k) {
            if (matrix[x + k][y] == 1 || matrix[x][y + k] == 1 ||
                matrix[x + k][y + size - 1] == 1 || matrix[x + size - 1][y + k] == 1) {
                return false;
            }
        }
        return true;
    }
    vector<int> findSquare(vector<vector<int>> &matrix) {
        auto n = static_cast<int>(matrix.size());
        for (int k = n; k > 0; --k) {
            for (int i = 0; i + k - 1 < n; ++i) {
                for (int j = 0; j + k - 1 < n; ++j) {
                    if (checkSquare(matrix, i, j, k)) {
                        return {i, j, k};
                    }
                }
            }
        }
        return {};
    }
};

int main() {
    auto s = Solution();
    auto matrix = vector<vector<int>>{{1, 0, 1},
                                      {0, 0, 1},
                                      {0, 0, 1}};
    s.findSquare(matrix);
    return 0;
}
