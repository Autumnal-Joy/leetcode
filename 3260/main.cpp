#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static auto largestPalindrome1(int n) {
        return string(n, '9');
    }
    static auto largestPalindrome2(int n) {
        if (n == 1) {
            return string(n, '8');
        }
        return string("8") + string(n - 2, '9') + string("8");
    }
    static auto largestPalindrome3(int n) {
        return string(n, '9');
    }
    static auto largestPalindrome4(int n) {
        if (n <= 4) {
            return string(n, '8');
        }
        return string("88") + string(n - 4, '9') + string("88");
    }
    static auto largestPalindrome5(int n) {
        if (n == 1) {
            return string(n, '5');
        }
        return string("5") + string(n - 2, '9') + string("5");
    }
    static auto largestPalindrome6(int n) {
        if (n <= 2) {
            return string(n, '6');
        }
        if (n & 1) {
            return string("8") + string((n - 3) / 2, '9') + string("8") + string((n - 3) / 2, '9') + string("8");
        } else {
            return string("8") + string((n - 4) / 2, '9') + string("77") + string((n - 4) / 2, '9') + string("8");
        }
    }
    static auto largestPalindrome7(int n) {
        auto circle = vector<string>({"7", "77", "5", "77", "7", "", "4", "44", "6", "44", "4", ""});
        auto center = circle[(n - 1) % 12];
        auto cnt = n - center.size();

        return string(cnt / 2, '9') + center + string(cnt / 2, '9');
    }
    static auto largestPalindrome8(int n) {
        if (n <= 6) {
            return string(n, '8');
        }
        return string("888") + string(n - 6, '9') + string("888");
    }
    static auto largestPalindrome9(int n) {
        return string(n, '9');
    }

    string largestPalindrome(int n, int k) {
        auto fns = vector<function<string(int)>>({largestPalindrome1,
                                                  largestPalindrome2,
                                                  largestPalindrome3,
                                                  largestPalindrome4,
                                                  largestPalindrome5,
                                                  largestPalindrome6,
                                                  largestPalindrome7,
                                                  largestPalindrome8,
                                                  largestPalindrome9});
        return fns[k - 1](n);
    }
};

int main() {
    auto s = Solution();
    auto str = string(0, '9');
    cout << str << endl;
    return 0;
}
