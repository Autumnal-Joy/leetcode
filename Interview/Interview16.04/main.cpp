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
    string tictactoe(vector<string> &board) {
        auto N = static_cast<int>(board.size());
        auto row = vector(N, 0);
        auto col = vector(N, 0);
        auto diag = 0, anti_diag = 0;
        auto is_full = true;
        auto score = unordered_map<char, int>({
                {'X', 1},
                {'O', -1},
                {' ', 0},
        });
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                auto ch = board[i][j];
                if (i == j) {
                    diag += score[ch];
                }
                if (i + j == N - 1) {
                    anti_diag += score[ch];
                }
                row[i] += score[ch];
                col[j] += score[ch];
                is_full = is_full && ch != ' ';
            }
        }
        for (int i = 0; i < N; ++i) {
            if (row[i] == N || col[i] == N || diag == N || anti_diag == N) {
                return "X";
            }
            if (row[i] == -N || col[i] == -N || diag == -N || anti_diag == -N) {
                return "O";
            }
        }
        if (is_full) {
            return "Draw";
        }
        return "Pending";
    }
};

int main() {
    auto board = vector<string>({"O X", "XO ", "X O"});
    cout << Solution().tictactoe(board) << endl;
    return 0;
}
