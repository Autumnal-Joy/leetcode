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
    int getKthMagicNumber(int k) {
        auto s = set({1});
        auto q = queue<int>();
        q.push(3);
        q.push(5);
        q.push(7);
        while (!q.empty()) {
            auto n = q.size();
            for (int i = 0; i < n; ++i) {
                auto top = q.front();
                s.insert(top);
                q.pop();
                if (top % 7 == 0) {
                    if (top <= numeric_limits<int>::max() / 7) {
                        q.push(top * 7);
                    }
                } else if (top % 5 == 0) {
                    if (top <= numeric_limits<int>::max() / 5) {
                        q.push(top * 5);
                    }
                    if (top <= numeric_limits<int>::max() / 7) {
                        q.push(top * 7);
                    }
                } else {
                    if (top <= numeric_limits<int>::max() / 3) {
                        q.push(top * 3);
                    }
                    if (top <= numeric_limits<int>::max() / 5) {
                        q.push(top * 5);
                    }
                    if (top <= numeric_limits<int>::max() / 7) {
                        q.push(top * 7);
                    }
                }
            }
        }

        auto it = s.begin();
        for (int i = 1; i < k; ++i) ++it;
        return *it;
    }
};

int main() {
    Solution().getKthMagicNumber(10);
    return 0;
}
