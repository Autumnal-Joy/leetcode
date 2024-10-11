#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    vector<NestedInteger> list;
    int integer = 0;
    bool isList = true;

public:
    // Constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    explicit NestedInteger(int value) : integer(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return !isList;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return integer;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        integer = value;
        isList = false;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        list.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return list;
    }
};

class Solution {
public:
    pair<NestedInteger, int> readInt(const string &s, int start) {
        int i = start;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            ++i;
        }

        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
            ++i;
        }
        return {NestedInteger(sign * num), i};
    }

    NestedInteger deserialize(string s) {
        auto q = stack<NestedInteger>();
        int i = 0;
        while (true) {
            switch (s[i]) {
                case '[': {
                    q.emplace();
                    break;
                }
                case ']': {
                    auto ni = q.top();
                    q.pop();
                    if (q.empty()) {
                        return ni;
                    } else {
                        q.top().add(ni);
                    }
                    break;
                }
                case '-':
                case '0' ... '9': {
                    auto [ni, j] = readInt(s, i);
                    if (q.empty()) {
                        return ni;
                    } else {
                        q.top().add(ni);
                    }
                    i = j - 1;
                    break;
                }
                case ',': {
                    break;
                }
            }
            ++i;
        }
    }
};

int main() {
    Solution s;
    s.deserialize("[123,[456,[789]]]");
    return 0;
}
