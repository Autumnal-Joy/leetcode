#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        size_t seed = 0;
        seed ^= p.first + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>> &docs) {
        auto word2docs = unordered_map<int, unordered_set<int>>();
        for (int i = 0; i < docs.size(); ++i) {
            for (int word: docs[i]) {
                word2docs[word].insert(i);
            }
        }

        auto pair2cnt = unordered_map<pair<int, int>, int, PairHash>();
        for (const auto &similarDocs: word2docs | views::values) {
            for (auto it1 = similarDocs.begin(); it1 != similarDocs.end(); ++it1) {
                auto it2 = it1;
                for (++it2; it2 != similarDocs.end(); ++it2) {
                    if (*it1 < *it2) {
                        ++pair2cnt[{*it1, *it2}];
                    } else {
                        ++pair2cnt[{*it2, *it1}];
                    }
                }
            }
        }

        cout << pair2cnt[{18, 43}] << endl;
        auto res = vector<string>();
        ranges::transform(pair2cnt, std::back_inserter(res), [&](const auto &p2c) {
            auto [p, c] = p2c;
            auto join = docs[p.first].size() + docs[p.second].size() - c;
            return std::format("{},{}: {:.4f}", p.first, p.second, 1.0 * c / join + 1e-9);
        });

        return res;
    }
};

int main() {
    auto s = Solution();
    vector<vector<int>> docs;

    ifstream infile("../Interview17.26/input.txt");
    string line;

    while (std::getline(infile, line)) {
        vector<int> row;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            row.push_back(number);
        }
        docs.push_back(std::move(row));
    }
    auto res = s.computeSimilarities(docs);

    ofstream outfile("../Interview17.26/output.txt");
    std::copy(res.begin(), res.end(), std::ostream_iterator<string>(outfile, "\n"));

    return 0;
}
