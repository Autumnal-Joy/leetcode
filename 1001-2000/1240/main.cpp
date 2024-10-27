#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    vector<vector<bool>> mat;
    int rowMax;
    int colMax;
    int minCnt;

public:
    bool collapse(int row, int col, int edge) {
        return std::accumulate(mat[row].begin() + col, mat[row].begin() + col + edge, 0) > 0;
    }

    void fill(int row, int col, int edge, bool val) {
        for (int i = row; i < row + edge; ++i) {
            std::fill(mat[i].begin() + col, mat[i].begin() + col + edge, val);
        }
    }

    // 以 row,col 为左上角填充正方形
    void dfs(int row, int col, int cnt) {
        if (cnt >= minCnt) {
            return;
        }
        if (row == rowMax) {
            minCnt = cnt;
            return;
        }
        if (mat[row][col]) {
            int k = 0, i, j;
            do {
                ++k;
                i = row + (col + k) / colMax;
                j = (col + k) % colMax;
            } while (i < rowMax && mat[i][j]);
            dfs(row + (col + k) / colMax, (col + k) % colMax, cnt);
            return;
        }
        for (int k = std::min({rowMax - row, colMax - col}); k > 0; --k) {
            if (collapse(row, col, k)) {
                continue;
            }

            fill(row, col, k, true);
            dfs(row + (col + k) / colMax, (col + k) % colMax, cnt + 1);
            fill(row, col, k, false);
        }
    }

    int tilingRectangle(int n, int m) {
        if (n > m) swap(n, m);
        mat = vector<vector<bool>>(n, vector<bool>(m, false));
        rowMax = n, colMax = m, minCnt = numeric_limits<int>::max();
        dfs(0, 0, 0);
        return minCnt;
    }
};

int main() {
    auto s = Solution();
    cout << s.tilingRectangle(13, 8) << endl;
    return 0;
}
