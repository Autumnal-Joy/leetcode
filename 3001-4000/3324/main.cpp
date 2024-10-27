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
    vector<string> stringSequence(string target) {
        auto res = vector<string>();
        for (int i = 0; i < target.size(); ++i) {
            const auto ch = target[i];
            for (char c = 'a'; c <= ch; ++c) {
                res.push_back(target.substr(0, i) + c);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
