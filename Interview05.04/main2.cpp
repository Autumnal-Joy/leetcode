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
    vector<int> findClosedNumbers(int num) {
        auto res = vector<int>();
        if (auto binary = bitset<31>(num).to_string();
            ranges::next_permutation(binary).found) {
            res.push_back(static_cast<int>(bitset<31>(binary).to_ulong()));
        } else {
            res.push_back(-1);
        }
        if (auto binary = bitset<31>(num).to_string();
            ranges::prev_permutation(binary).found) {
            res.push_back(static_cast<int>(bitset<31>(binary).to_ulong()));
        } else {
            res.push_back(-1);
        }
        return res;
    }
};

int main() {

    return 0;
}
