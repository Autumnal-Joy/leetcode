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
    bool binarySearch(const vector<vector<int>> &matrix, const int target, const int top, const int bottom, const int left, const int right) {
        if (top > bottom || left > right) {
            return false;
        }
        if (top == bottom && left == right) {
            return matrix[top][left] == target;
        }
        const int midVertical = (top + bottom) / 2;
        const int midHorizontal = (left + right) / 2;
        if (matrix[midVertical][midHorizontal] == target) {
            return true;
        }
        if (matrix[midVertical][midHorizontal] < target) {
            return binarySearch(matrix, target, midVertical + 1, bottom, left, right) ||
                   binarySearch(matrix, target, top, midVertical, midHorizontal + 1, right);
        }
        return binarySearch(matrix, target, top, midVertical - 1, left, right) ||
               binarySearch(matrix, target, midVertical, bottom, left, midHorizontal - 1);
    }
    bool searchMatrix(const vector<vector<int>> &matrix, const int target) {
        if (matrix.empty()) {
            return false;
        }
        return binarySearch(matrix, target, 0, static_cast<int>(matrix.size()) - 1, 0, static_cast<int>(matrix[0].size()) - 1);
    }
};

int main() {
    auto matrix = vector<vector<int>>({
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30},
    });
    cout << Solution().searchMatrix(matrix, 5) << endl;
    return 0;
}
