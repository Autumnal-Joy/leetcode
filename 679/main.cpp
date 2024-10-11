#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
    double precision = 1e-6;
    double target = 24;
    vector<std::function<double(double, double)>> operators = {
            [](double a, double b) { return a + b; },
            [](double a, double b) { return a - b; },
            [](double a, double b) { return a * b; },
            [](double a, double b) {
                return b != 0 ? a / b : numeric_limits<double>::infinity();
            },
    };

public:
    bool judgePoint24double(const vector<double> &cards) {
        if (cards.size() == 1) {
            return abs(cards[0] - target) < precision;
        }

        for (int i = 0; i < cards.size(); ++i) {
            for (int j = 0; j < cards.size(); ++j) {
                if (i == j) {
                    continue;
                }
                vector<double> next;
                std::copy_if(cards.begin(), cards.end(), std::back_inserter(next),
                             [&, idx = 0](int) mutable {
                                 bool selected = idx != i && idx != j;
                                 ++idx;
                                 return selected;
                             });

                for (const auto &fn: operators) {
                    next.push_back(fn(cards[i], cards[j]));
                    if (judgePoint24double(next)) {
                        return true;
                    }
                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(const vector<int> &cards) {
        return judgePoint24double(vector<double>(cards.begin(), cards.end()));
    }
};

int main() {
    auto s = Solution();
    cout << s.judgePoint24(vector<int>{1, 2, 1, 2}) << endl;
    return 0;
}
