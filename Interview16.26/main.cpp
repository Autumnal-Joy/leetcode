#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
    static int priority(char c) {
        if (c == '-' || c == '+') {
            return 1;
        }
        if (c == '*' || c == '/') {
            return 2;
        }
        return 0;
    }
    static long long cal(long long num1, char op, long long num2) {
        long long res;
        if (op == '-') {
            res = num1 - num2;
        } else if (op == '+') {
            res = num1 + num2;
        } else if (op == '*') {
            res = num1 * num2;
        } else {
            res = num1 / num2;
        }
        return res;
    }

public:
    int calculate(string s) {
        auto numStack = stack<long long>();
        auto opStack = stack<char>();

        auto num = 0ll;
        auto sign = 1;

        auto state = 0;
        for (auto c: s) {
            switch (state) {
                case 0: {
                    if (isdigit(c)) {
                        state = 2;
                        num += (c - '0');
                    } else if (c == '-' || c == '+') {
                        state = 1;
                        if (c == '-') {
                            sign = -1;
                        }
                    }
                    break;
                }
                case 1: {
                    if (isdigit(c)) {
                        state = 2;
                        num += (c - '0');
                    }
                    break;
                }
                case 2: {
                    if (c == '-' || c == '+' || c == '*' || c == '/') {
                        state = 1;
                        numStack.push(sign * num);
                        sign = 1;
                        num = 0;
                        while (!opStack.empty() && priority(c) <= priority(opStack.top())) {
                            const auto num2 = numStack.top();
                            numStack.pop();
                            const auto num1 = numStack.top();
                            numStack.pop();
                            const auto op = opStack.top();
                            opStack.pop();
                            numStack.push(cal(num1, op, num2));
                        }
                        opStack.push(c);
                    } else if (isdigit(c)) {
                        state = 2;
                        num = num * 10 + (c - '0');
                    }
                    break;
                }
                default:;
            }
        }
        numStack.push(num);
        while (!opStack.empty()) {
            const auto num2 = numStack.top();
            numStack.pop();
            const auto num1 = numStack.top();
            numStack.pop();
            const auto op = opStack.top();
            opStack.pop();
            numStack.push(cal(num1, op, num2));
        }

        return static_cast<int>(numStack.top());
    }
};

int main() {
    const auto s = "1*2-3/4+5*6-7*8+9/10";
    cout << Solution().calculate(s) << endl;
    return 0;
}
