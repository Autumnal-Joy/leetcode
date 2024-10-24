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
    vector<string> permutation(string S) {
        auto res = vector<string>();
        ranges::sort(S);
        while (true) {
            res.push_back(S);
            if (!ranges::next_permutation(S).found) {
                break;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
