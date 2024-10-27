#include <bits/stdc++.h>

using namespace std;

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class StackOfPlates {
    list<stack<int>> stacks;
    int cap;

public:
    explicit StackOfPlates(const int cap) : cap(cap) {
        stacks.emplace_back();
    }

    void push(const int val) {
        if (cap == 0) {
            return;
        }
        if (stacks.size() > 1 && stacks.back().empty() && prev(prev(stacks.end()))->size() < cap) {
            stacks.pop_back();
        }
        stacks.back().push(val);
        if (stacks.back().size() == cap) {
            stacks.emplace_back();
        }
    }

    int pop() {
        if (cap == 0 || stacks.size() == 1 && stacks.back().empty()) {
            return -1;
        }
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        const auto top = stacks.back().top();
        stacks.back().pop();
        return top;
    }

    int popAt(const int index) {
        if (cap == 0 || index >= stacks.size()) {
            return -1;
        }
        if (index + 1 == stacks.size()) {
            return stacks.back().empty() ? -1 : pop();
        }
        auto temp = stacks.begin();
        for (int i = 0; i < index; ++i) {
            temp = next(temp);
        }
        auto top = temp->top();
        temp->pop();
        if (temp->empty()) {
            stacks.erase(temp);
        }
        return top;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

int main() {
    auto operations = vector<string>({
            "StackOfPlates",
            "push",
            "pop",
            "popAt",
            "popAt",
            "popAt",
            "push",
            "push",
            "push",
            "popAt",
            "popAt",
            "push",
            "pop",
            "popAt",
            "push",
            "popAt",
            "popAt",
            "pop",
            "popAt",
            "push",
            "push",
            "pop",
            "push",
            "push",
            "popAt",
            "popAt",
            "popAt",
            "push",
            "popAt",
            "push",
            "pop",
            "push",
            "push",
            "popAt",
            "popAt",
            "push",
            "popAt",
            "push",
            "pop",
            "pop",
            "popAt",
            "push",
            "popAt",
            "pop",
            "popAt",
            "popAt",
            "popAt",
    });
    auto data = vector<vector<int>>({
            {1},
            {33},
            {},
            {0},
            {1},
            {0},
            {17},
            {9},
            {17},
            {1},
            {1},
            {3},
            {},
            {1},
            {37},
            {0},
            {0},
            {},
            {1},
            {26},
            {32},
            {},
            {36},
            {24},
            {1},
            {0},
            {0},
            {4},
            {0},
            {34},
            {},
            {26},
            {45},
            {1},
            {0},
            {13},
            {1},
            {37},
            {},
            {},
            {0},
            {5},
            {0},
            {},
            {1},
            {1},
            {1},
    });

    StackOfPlates *st = nullptr;
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "StackOfPlates") {
            st = new StackOfPlates(data[i][0]);
        } else if (operations[i] == "push") {
            st->push(data[i][0]);
        } else if (operations[i] == "pop") {
            st->pop();
        } else {
            st->popAt(data[i][0]);
        }
    }

    delete st;
    return 0;
}
