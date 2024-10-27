#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
    enum class State {
        start,
        sign,
        digit,
        end
    };
    State state = State::start;

public:
    int myAtoi(string s) {
        int res = 0;
        bool neg = false;
        bool overflow = false;

        for (int i = 0; i < s.size() && state != State::end; ++i) {
            auto c = s[i];
            switch (state) {
                case State::start: {
                    if (c == ' ') {
                        continue;
                    } else if (c == '+') {
                        state = State::sign;
                    } else if (c == '-') {
                        neg = true;
                        state = State::sign;
                    } else if (std::isdigit(c)) {
                        state = State::digit;
                        int d = c - '0';
                        if (res > (INT_MAX - d) / 10) {
                            overflow = true;
                            state = State::end;
                        } else {
                            res = res * 10 + d;
                        }
                    } else {
                        state = State::end;
                    }
                    break;
                }
                case State::sign: {
                    if (std::isdigit(c)) {
                        state = State::digit;
                        int d = c - '0';
                        if (res > (INT_MAX - d) / 10) {
                            overflow = true;
                            state = State::end;
                        } else {
                            res = res * 10 + d;
                        }
                    } else {
                        state = State::end;
                    }
                    break;
                }
                case State::digit: {
                    if (std::isdigit(c)) {
                        int d = c - '0';
                        if (res > (INT_MAX - d) / 10) {
                            overflow = true;
                            state = State::end;
                        } else {
                            res = res * 10 + d;
                        }
                    } else {
                        state = State::end;
                    }
                    break;
                }
            }
        }
        if (overflow) {
            return neg ? INT_MIN : INT_MAX;
        } else {
            return neg ? -res : res;
        }
    }
};

int main() {
    auto s = Solution();
    cout << s.myAtoi("0-1") << endl;
    return 0;
}
