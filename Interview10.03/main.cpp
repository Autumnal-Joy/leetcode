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
    int search(const vector<int> &arr, const int target) {
        int left = 0, right = static_cast<int>(arr.size());
        while (left < right) {
            if (arr[left] == target) {
                return left;
            }
            // left 一定不为解，解在 (left, right)
            const auto mid = (left + right) / 2;
            if (arr[left] < arr[mid]) {
                // 区间 [left, mid] 递增
                if (arr[left] < target && target <= arr[mid]) {
                    // 解在 (left, mid]
                    ++left;
                    right = mid + 1;
                } else {
                    // 解在 (mid, right)
                    left = mid + 1;
                }
            } else if (arr[left] > arr[mid]) {
                // 区间 [mid, right) 递增
                if (arr[mid] <= target && target <= arr[right - 1]) {
                    // 解在 [mid, right)
                    left = mid;
                } else {
                    // 解在 (left, mid)
                    ++left;
                    right = mid;
                }
            } else {
                // 无信息
                ++left;
            }
        }
        return -1;
    }
};

int main() {
    auto arr = vector<int>({1, 1, 1, 1, 1, 2, 1, 1, 1});
    cout << Solution().search(arr, 2) << endl;
        return 0;
    }
