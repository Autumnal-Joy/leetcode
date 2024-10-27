#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    enum class State {
        start,
        s1,
        s2,
        s3,
        s4,
        s5,
        s6,
        s7,
        s8,
        s9,
        fail
    };

    static bool isDigit(char c) { return c >= '0' && c <= '9'; };

    static bool isSpace(char c) { return c == ' '; };

    static bool isSign(char c) { return c == '-' || c == '+'; };

    static bool isDot(char c) { return c == '.'; };

    static bool isE(char c) { return c == 'E' || c == 'e'; };

    State nextState(const State &current, char input) {
        switch (current) {
            case State::start:
                if (isSpace(input))
                    return State::start;
                if (isSign(input))
                    return State::s1;
                if (isDot(input))
                    return State::s2;
                if (isDigit(input))
                    return State::s3;
                return State::fail;
            case State::s1:
                if (isDot(input))
                    return State::s2;
                if (isDigit(input))
                    return State::s3;
                return State::fail;
            case State::s2:
                if (isDigit(input))
                    return State::s5;
                return State::fail;
            case State::s3:
                if (isDigit(input))
                    return State::s3;
                if (isDot(input))
                    return State::s4;
                if (isE(input))
                    return State::s6;
                if (isSpace(input))
                    return State::s9;
                return State::fail;
            case State::s4:
                if (isDigit(input))
                    return State::s5;
                if (isE(input))
                    return State::s6;
                if (isSpace(input))
                    return State::s9;
                return State::fail;
            case State::s5:
                if (isDigit(input))
                    return State::s5;
                if (isE(input))
                    return State::s6;
                if (isSpace(input))
                    return State::s9;
                return State::fail;
            case State::s6:
                if (isSign(input))
                    return State::s7;
                if (isDigit(input))
                    return State::s8;
                return State::fail;
            case State::s7:
                if (isDigit(input))
                    return State::s8;
                return State::fail;
            case State::s8:
                if (isDigit(input))
                    return State::s8;
                if (isSpace(input))
                    return State::s9;
                return State::fail;
            case State::s9:
                if (isSpace(input))
                    return State::s9;
                return State::fail;
            case State::fail:
                return State::fail;
        }
    }

    bool validNumber(string s) {
        State current = State::start;
        for (char c: s) {
            current = nextState(current, c);
        }
        return current == State::s3 || current == State::s4 ||
               current == State::s5 || current == State::s8 || current == State::s9;
    }
};

int main() {
    Solution s;

    return 0;
}
