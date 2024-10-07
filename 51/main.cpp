#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    static vector<string> loc2str(const vector<int> &loc) {
        vector<string> board(loc.size(), string(loc.size(), '.'));
        for (int i = 0; i < loc.size(); ++i) {
            board[i][loc[i]] = 'Q';
        }
        return board;
    }

    void solve(vector<int> &loc, int row) {
        if (row == loc.size()) {
            res.push_back(loc2str(loc));
            return;
        }
        for (int col = 0; col < loc.size(); ++col) {
            bool valid = true;
            for (int i = 0; i < row; ++i) {
                auto j = loc[i];
                if (j == col || j - i == col - row || j + i == col + row) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                loc[row] = col;
                solve(loc, row + 1);
                loc[row] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        auto loc = vector<int>(n, -1);
        solve(loc, 0);
        return res;
    }
};

int main() {
    return 0;
}
