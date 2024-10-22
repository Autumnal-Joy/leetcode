#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool inbound(const vector<vector<int>> &board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }
    void gameOfLife(vector<vector<int>> &board) {
        auto n = board.size(), m = board[0].size();

        auto copy = board;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (!inbound(board, i + di, j + dj) || di == 0 && dj == 0) { continue; }
                        cnt += copy[i + di][j + dj];
                    }
                }
                if (cnt != 2 && cnt != 3) {
                    board[i][j] = 0;
                }
                if (cnt == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    auto s = Solution();
    auto nums = vector<vector<int>>({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}});
    s.gameOfLife(nums);
    return 0;
}
