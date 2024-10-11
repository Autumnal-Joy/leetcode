#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool inBoard(const vector<vector<char>> &board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }

    bool dfs(const vector<vector<char>> &board, const string &word, int depth,
             int x, int y, vector<vector<bool>> &visited) {
        if (board[x][y] != word[depth]) {
            return false;
        }
        if (depth + 1 == word.size()) {
            return true;
        }
        visited[x][y] = true;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) + abs(j) == 1 && inBoard(board, x + i, y + j) &&
                    !visited[x + i][y + j]) {
                    if (dfs(board, word, depth + 1, x + i, y + j, visited)) {
                        return true;
                    }
                }
            }
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, const string &word) {
        auto visited = vector<vector<bool>>(board.size(),
                                            vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// ABCE
// SFES
// ADEE

int main() {
    auto s = Solution();
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'E', 'S'},
            {'A', 'D', 'E', 'E'}};
    cout << s.exist(board, "ABCESEEEFS") << endl;
    return 0;
}
