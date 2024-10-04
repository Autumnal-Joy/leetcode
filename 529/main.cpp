#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
      return;
    }

    if (board[x][y] == 'B') {
      return;
    }

    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return;
    }

    if (board[x][y] == 'E') {
      int cnt = 0;
      for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
          if (i == 0 && j == 0) {
            continue;
          }
          if (x + i < 0 || x + i >= board.size() || y + j < 0 ||
              y + j >= board[0].size()) {
            continue;
          }
          if (board[x + i][y + j] == 'M') {
            ++cnt;
          }
        }
      }

      if (cnt > 0) {
        board[x][y] = static_cast<char>('0' + cnt);
      } else {
        board[x][y] = 'B';
        for (int i = -1; i <= 1; ++i) {
          for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
              continue;
            }
            dfs(board, x + i, y + j);
          }
        }
      }
    }
  }

public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    dfs(board, click[0], click[1]);
    return board;
  }
};

int main() {
  auto s = Solution();
  return 0;
}
