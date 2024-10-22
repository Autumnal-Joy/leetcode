#include <deque>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

void helper(int n) {
    auto v = vector<int>(n);
    std::iota(v.begin(), v.end(), 1);
    std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    while (v.size() > 1) {
        auto temp = deque<int>();
        for (int i = 1; i < v.size(); i += 2) {
            temp.push_back(v[i]);
        }
        v = vector<int>(temp.begin(), temp.end());
        std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        temp.clear();
        for (int i = v.size() - 2; i >= 0; i -= 2) {
            temp.push_front(v[i]);
        }
        v = vector<int>(temp.begin(), temp.end());
        std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n & 1) {
            return lastRemaining(n - 1);
        }
        if (n % 4 == 0) {
            return lastRemaining(n / 4) * 4 - 2;
        } else {
            return lastRemaining(n / 4) * 4;
        }
    }
};

int main() {
    helper(14);
    helper(16);
    helper(18);
    helper(20);
    helper(22);
    helper(24);
    Solution s;
    return 0;
}

// 1 2 3 ... 4n+2
// 2 4 6 ... 4n+2
// 4 8 12 ... 4n
// 1 2 3 ... n
