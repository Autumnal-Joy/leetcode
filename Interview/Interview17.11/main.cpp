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
    int findClosest(vector<string> &words, const string &word1, const string &word2) {
        auto word2locs = unordered_map<string, vector<int>>();
        for (int i = 0; i < words.size(); ++i) {
            word2locs[words[i]].push_back(i);
        }

        const auto loc1 = word2locs[word1];
        const auto loc2 = word2locs[word2];
        auto idx1 = 0, idx2 = 0;
        auto res = numeric_limits<int>::max();
        while (idx1 < loc1.size() && idx2 < loc2.size()) {
            res = std::min({res, std::abs(loc1[idx1] - loc2[idx2])});
            if (loc1[idx1] < loc2[idx2]) {
                idx1++;
            } else {
                idx2++;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
