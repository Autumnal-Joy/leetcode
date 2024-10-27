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
    vector<int> subSort(vector<int> &array) {
        auto res = vector({-1, -1});
        if (array.size() < 2) {
            return res;
        }
        auto max = array[0];
        for (int i = 1; i < array.size(); ++i) {
            if (array[i] < max) {
                res[1] = i;
                if (res[0] == -1 || array[i] < array[res[0]]) {
                    res[0] = static_cast<int>(std::upper_bound(array.begin(), array.begin() + (res[0] == -1 ? i : res[0]), array[i]) - array.begin());
                }
            } else {
                max = array[i];
            }
        }
        return res;
    }
};

int main() {
    auto array = vector({5, 4, 3, 2, 1});
    Solution().subSort(array);
    return 0;
}
