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

class Solution {
    int dfs(const int ciphertext) {
        if (ciphertext < 10) {
            return 1;
        }
        auto [quot, rem] = std::div(ciphertext, 100);

        if (rem < 10 || rem >= 26) {
            return dfs(ciphertext / 10);
        }
        return dfs(ciphertext / 10) + dfs(ciphertext / 100);
    }

public:
    int crackNumber(const int ciphertext) {
        return dfs(ciphertext);
    }
};

#ifdef LEETCODE
int main() {

    return 0;
}
#endif
