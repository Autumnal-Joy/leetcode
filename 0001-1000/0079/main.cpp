#ifdef LEETCODE
#include <bits/stdc++.h>

using namespace std;
#endif

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#ifdef LEETCODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
    bool dfs(vector<vector<char>> &board, const string &word,
             int i, int j, int depth,
             vector<vector<bool>> &visited) {
        if (board[i][j] != word[depth]) return false;
        if (depth == word.size() - 1) return true;
        auto res = false;
        visited[i][j] = true;
        if (i - 1 >= 0 && !visited[i - 1][j]) res = dfs(board, word, i - 1, j, depth + 1, visited);
        if (i + 1 < board.size() && !visited[i + 1][j]) res = res || dfs(board, word, i + 1, j, depth + 1, visited);
        if (j - 1 >= 0 && !visited[i][j - 1]) res = res || dfs(board, word, i, j - 1, depth + 1, visited);
        if (j + 1 < board[0].size() && !visited[i][j + 1]) res = res || dfs(board, word, i, j + 1, depth + 1, visited);
        visited[i][j] = false;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, const string &word) {
        auto visited = vector(board.size(), vector(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
