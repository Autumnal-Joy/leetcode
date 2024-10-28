#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static pair<int, int> from(const int n, const pair<int, int> &loc) {
        return {loc.second, n - 1 - loc.first};
    }
    static void rotateOne(vector<vector<int>> &matrix, int n, const pair<int, int> &loc) {
        const auto loc1 = loc;
        const auto loc2 = from(n, loc1);
        const auto loc3 = from(n, loc2);
        const auto loc4 = from(n, loc3);
        swap(matrix[loc1.first][loc1.second], matrix[loc2.first][loc2.second]);
        swap(matrix[loc1.first][loc1.second], matrix[loc3.first][loc3.second]);
        swap(matrix[loc1.first][loc1.second], matrix[loc4.first][loc4.second]);
    }

public:
    void rotate(vector<vector<int>> &matrix) {
        auto n = static_cast<int>(matrix.size());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                rotateOne(matrix, n, {i, j});
            }
        }
    }
};

int main() {

    return 0;
}
